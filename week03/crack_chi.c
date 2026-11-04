#include <stdio.h>

int main(void)
{
    /* 英文字母出现频率（百分比）：a 8.2%, b 1.5%, ... z 0.07% */
    double freq[26] = {8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.15,
                       0.77, 4.0, 2.4, 6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1,
                       2.8, 0.98, 2.4, 0.15, 2.0, 0.07};

    char text[500];
    char key[20];
    int cnt[26];
    int k, g, i, j, n;
    int s, bests;
    int bestk;
    double chi, bestchi, diff, expect;
    double total, sum;

    printf("请输入密文：");
    fgets(text, sizeof(text), stdin);

    /* 第一步：用重合指数自己算出密钥长度 k */
    bestk = 0;
    for (k = 1; k <= 8; k = k + 1)
    {
        sum = 0;
        for (g = 0; g < k; g = g + 1)
        {
            for (i = 0; i < 26; i = i + 1)
                cnt[i] = 0;

            n = 0;
            j = 0;
            for (i = 0; text[i] != '\0'; i = i + 1)
            {
                if (text[i] >= 'a' && text[i] <= 'z')
                {
                    if (j % k == g)
                    {
                        cnt[text[i] - 'a'] = cnt[text[i] - 'a'] + 1;
                        n = n + 1;
                    }
                    j = j + 1;
                }
            }

            total = 0;
            for (i = 0; i < 26; i = i + 1)
                total = total + cnt[i] * (cnt[i] - 1);

            sum = sum + total / (n * (n - 1));
        }
        if (bestk == 0 && sum / k >= 0.050)
            bestk = k;
    }
    if (bestk == 0)
        bestk = 1;
    k = bestk;
    printf("自动算出的密钥长度 k = %d\n", k);

    /* 第二步：卡方检验算出密钥 */
    for (g = 0; g < k; g = g + 1)
    {
        for (i = 0; i < 26; i = i + 1)
            cnt[i] = 0;

        n = 0;
        j = 0;
        for (i = 0; text[i] != '\0'; i = i + 1)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                if (j % k == g)
                {
                    cnt[text[i] - 'a'] = cnt[text[i] - 'a'] + 1;
                    n = n + 1;
                }
                j = j + 1;
            }
        }

        bestchi = 1e9;
        bests = 0;
        for (s = 0; s < 26; s = s + 1)
        {
            chi = 0;
            for (i = 0; i < 26; i = i + 1)
            {
                expect = n * freq[(i - s + 26) % 26] / 100.0;
                if (expect < 0.1)
                    expect = 0.1;
                diff = cnt[i] - expect;
                chi = chi + diff * diff / expect;
            }
            if (chi < bestchi)
            {
                bestchi = chi;
                bests = s;
            }
        }
        key[g] = 'a' + bests;
    }

    printf("密钥：");
    for (g = 0; g < k; g = g + 1)
        printf("%c", key[g]);
    printf("\n");

    /* 第三步：用密钥解密整段 */
    j = 0;
    for (i = 0; text[i] != '\0'; i = i + 1)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' - (key[j % k] - 'a') + 26) % 26 + 'a';
            j = j + 1;
        }
    }
    printf("明文：%s", text);

    return 0;
}
