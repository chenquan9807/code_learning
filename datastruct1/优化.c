#include <stdio.h>
#include <string.h>
int next[32]={-999};
/* ����ģʽ��T��ĸ��S�е�pos���ַ���λ�� */
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
        /* j = -1 ��ʾnext[0], ˵��ʧ�䴦��ģʽ��T�ĵ�0���ַ��������������⴦��Ȼ����i+1��j+1��*/
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
    printf("����������s��");
    gets(s);
    printf("������ģʽ����s��");
    gets(t);
    int pos=0;
    get_next(t,next);
    i=KMP(s,t,pos);
    if(i==-1)printf("ƥ��ʧ��\n");
    else printf("ģʽ��λ��������%dλ\n",i);
}
