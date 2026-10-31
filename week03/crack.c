#include <stdio.h>

int main(void)
{
char text[100];
int shift, i;


printf("请输入密文：");
fgets(text, sizeof(text), stdin);


for (shift = 1; shift <= 25; shift = shift + 1)
{
printf("位移%2d：", shift);
for (i = 0; text[i] != '\0'; i = i + 1)
{
if (text[i] >= 'a' && text[i] <= 'z')
printf("%c",(text[i] - 'a' + shift) % 26 + 'a');
else
printf("%c",text[i]);
}
printf("\n");
}
return 0;
}
