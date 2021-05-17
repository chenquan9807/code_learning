#include<stdio.h>
#include<string.h>
#define MAX 100
int next[MAX];
int BF_str(char *s,char *t)             //简单的模式匹配
{
    int i=0,j=0,m,n;
    m=Len_str(s);
    n=Len_str(t);
    while(i<m&&j<n)                     //当主串或模式串其中一个比较完毕结束循环
    if(s[i]==t[j])
    {
        i++;
        j++;
    }
    else                                //回溯到上次匹配位置的后一位
    {
        i=i-j+1;
        j=0;
    }
    if(j>=n) return (i-n+1);            //返回模式串在主串的位置
    else return -1;
}
void Getnext(char *t,int next[])        //next数组的获取，确定模式串的移动
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
int KMP_str(char *s,char *t)            //KMP算法的实现
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
int Len_str(char *c)                    //求字符串的长度
{
    int n=0;
    while(c[n]!='\0')                   //到字符串最后一位结束输入
        n++;
    return n;
}
int main()
{
    int p,m,n,i,e;
    char *s,*t;
    s=malloc(MAX);
    t=malloc(MAX);
    printf("请输入主串S：");
    scanf("%s",s);
    printf("请输入模式串t：");
    scanf("%s",t);
    printf("请选择匹配类型：\n1:简单模式匹配\n2: KMP匹配\n");
    scanf("%d",&e);
    if(e==1)
    p=BF_str(s,t);
    else if(e==2)
    {
    m=Len_str(s);
    for(i=m;i>=1;i--)       //数后移一位第一位存入长度
        s[i]=s[i-1];
    s[0]=m;
    s[m+1]='\0';
    n=Len_str(t);
    for(i=n;i>=1;i--)       ////数后移一位第一位存入长度
        t[i]=t[i-1];
    t[0]=n;
    t[n+1]='\0';
    Getnext(t,next);
    p=KMP_str(s,t);
    }
    else printf("选择错误\n");
    if(p==-1)
        printf("模式串匹配失败");
    else
        printf("模式串位于主串的第%d位",p);
    return 0;
}
