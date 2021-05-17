#include <stdio.h>
#include <string.h>
int next[32]={-999};
/* 返回模式串T在母串S中第pos个字符的位置 */
void get_next(char *T,int *next)
{
    int k=-1;
    int j=0;
    next[j]=k;
    while(j<strlen(T))
    {
        if((k==-1)||(T[j]==T[k]))
        {
            ++k;
            ++j;
            next[j]=k;
        }
        else
            k=next[k];
    }
}
int KMP(char *S,char *T,int pos)
{
    int i;
    int j;
    i=pos;
    j=0;
    while((i<strlen(S))&&(j<strlen(T)))
    {
        /* j = -1 表示next[0], 说明失配处在模式串T的第0个字符。所以这里特殊处理，然后令i+1和j+1。*/
        if ((j==-1)||S[i]==T[j])
        {
            i++;j++;
        }
        else
            j=next[j];
    }
    if(strlen(T)==j)
        return i-strlen(T);
    else
        return -1;
}
int main(void)
{
    int i;
    char *s,*t;
    s=malloc(100);
    t=malloc(100);
    printf("请输入主串s：");
    gets(s);
    printf("请输入模式串串s：");
    gets(t);
    int pos=0;
    get_next(t,next);
    i=KMP(s,t,pos);
    if(i==-1)printf("匹配失败\n");
    else printf("模式串位于主串第%d位\n",i);
}
