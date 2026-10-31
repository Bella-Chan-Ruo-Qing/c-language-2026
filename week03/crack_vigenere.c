#include <stdio.h>


int main(void)
{
char text[100];
int cnt[26];
int k = 3;
int g, i, letterpos;
int maxidx, shift;


printf("请输入密文：");
fgets(text,sizeof(text), stdin);


for (g = 0; g < k; g = g + 1)
{
for (i = 0; i < 26; i = i + 1)
cnt[i] = 0;


letterpos = 0;
for (i = 0; text[i] != '\0'; i = i + 1)
{
if (text[i] >= 'a' && text[i] <= 'z')
{
if (letterpos % k == g)
cnt[text[i] - 'a'] = cnt[text[i] - 'a'] + 1;
letterpos = letterpos +1;
}
}


maxidx = 0;
for (i = 1; i < 26; i = i + 1)
if (cnt[i] > cnt[maxidx])
maxidx = i;


shift = (maxidx - 4 + 26) % 26;
printf("第%d个密钥字母：%c\n", g + 1, 'a' + shift);
}
return 0;
}
