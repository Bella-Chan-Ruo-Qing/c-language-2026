#include <stdio.h>
#include <string.h>


int main(void)
{
char text[100];
char key[100];
int i, j = 0;
int klen;


printf("请输入明文：");
fgets(text,sizeof(text),stdin);


printf("请输入密钥（小写字母）：");
scanf("%s", key);
klen = strlen(key);


for(i = 0; text[i] != '\0'; i = i + 1)
{
if (text[i] >= 'a' && text[i] <= 'z')
{
int shift = key[j % klen] - 'a';
text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
j = j + 1;
}
}

printf("加密后：%s", text);
return 0;
}
