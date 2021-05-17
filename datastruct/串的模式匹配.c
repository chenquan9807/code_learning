#include<stdio.h>
#include<string.h>
#define MAX 100
int next[MAX];
int BF_str(char *s,char *t)             //�򵥵�ģʽƥ��
{
    int i=0,j=0,m,n;
    m=Len_str(s);
    n=Len_str(t);
    while(i<m&&j<n)                     //��������ģʽ������һ���Ƚ���Ͻ���ѭ��
    if(s[i]==t[j])
    {
        i++;
        j++;
    }
    else                                //���ݵ��ϴ�ƥ��λ�õĺ�һλ
    {
        i=i-j+1;
        j=0;
    }
    if(j>=n) return (i-n+1);            //����ģʽ����������λ��
    else return -1;
}
void Getnext(char *t,int next[])        //next����Ļ�ȡ��ȷ��ģʽ�����ƶ�
{
    int i=1,j=0,n;
    next[1]=0;
    n=Len_str(t);
    while(i<n-1)
    {
        if(j==0||t[i]==t[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else j=next[j];
    }
}
int KMP_str(char *s,char *t)            //KMP�㷨��ʵ��
{
    int i=1,j=1,m,n;
    m=Len_str(s);
    n=Len_str(t);
    while(i<=m-1&&j<=n-1)
    {
        if(j==0||s[i]==t[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j>n-1) return (i-(n-1));
    else return -1;
}
int Len_str(char *c)                    //���ַ����ĳ���
{
    int n=0;
    while(c[n]!='\0')                   //���ַ������һλ��������
        n++;
    return n;
}
int main()
{
    int p,m,n,i,e;
    char *s,*t;
    s=malloc(MAX);
    t=malloc(MAX);
    printf("����������S��");
    scanf("%s",s);
    printf("������ģʽ��t��");
    scanf("%s",t);
    printf("��ѡ��ƥ�����ͣ�\n1:��ģʽƥ��\n2: KMPƥ��\n");
    scanf("%d",&e);
    if(e==1)
    p=BF_str(s,t);
    else if(e==2)
    {
    m=Len_str(s);
    for(i=m;i>=1;i--)       //������һλ��һλ���볤��
        s[i]=s[i-1];
    s[0]=m;
    s[m+1]='\0';
    n=Len_str(t);
    for(i=n;i>=1;i--)       ////������һλ��һλ���볤��
        t[i]=t[i-1];
    t[0]=n;
    t[n+1]='\0';
    Getnext(t,next);
    p=KMP_str(s,t);
    }
    else printf("ѡ�����\n");
    if(p==-1)
        printf("ģʽ��ƥ��ʧ��");
    else
        printf("ģʽ��λ�������ĵ�%dλ",p);
    return 0;
}
