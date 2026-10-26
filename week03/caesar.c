#include <stdio.h>

int main(void)
{
char text[100];
int i;
int shift;

printf("请输入密钥（1-25 的整数）：");
scanf("%d", &shift);
getchar();

printf("请输入一句话：");
fgets(text,sizeof(text),stdin);

for(i=0; text[i] !='\0'; i = i + 1)
{
if (text[i]>='a' && text[i]<= 'z')
{
text[i] = (text[i] - 'a' +shift) % 26 + 'a';
}
}

printf("加密后： %s", text);

printf("请输入密文：");
fgets(text,sizeof(text),stdin);

for(i=0; text[i] !='\0'; i = i + 1)
{
if(text[i]>='a' && text[i]<= 'z')
{
text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
}
}

printf("解密后： %s", text);

return 0;
}

