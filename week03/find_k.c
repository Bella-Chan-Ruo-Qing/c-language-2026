#include <stdio.h>

int main(void)
{
    char text[500];
    int cnt[26];
    int k, g, i, j, n;
    double total, sum;

    printf("请输入密文：");
    fgets(text, sizeof(text), stdin);

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
        printf("k=%d   IC=%.4f\n", k, sum / k);
    }
    return 0;
}
