#include<stdio.h>
#include<string.h>
#define MAXSSIZE 100
typedef struct
{
    char data[MAXSSIZE];
    int len
}Seqstring;
Seqstring  Input_Seqstring(Seqstring s)
{
    gets(s.data);
    s.len=strlen(s.data);
    s.data[s.len+1]='\0';
    return s;
}
Seqstring Strconat(Seqstring s1,Seqstring s2)     //串连接
{
    int i=0,j;
    Seqstring s;
    if(s1.len+s2.len>MAXSSIZE-1) return;      //*s长度不够
    j=0;
    while(j<s1.len)
    {
        s.data[i]=s1.data[j];
        i++;
        j++;
    }
    j=0;
    while(j<s2.len)
    {
        s.data[i]=s2.data[j];
        i++;
        j++;
    }
    s.data[i]='\0';
    s.len=s1.len+s2.len;
    return s;
}
Seqstring Strsub(Seqstring s,int i,int len)     //求子串
{
    int j;
    if(i<1||i>s.len||len>s.len-i+1||s.len<0)
    {
        printf("参数取值不正确\n");
        return;
    }
    Seqstring sub;
    for(j=0;j<len;j++)
        sub.data[j]=s.data[i+j-1];
    sub.data[j]='\0';
    sub.len=strlen(sub.data);                             //子串结束标志
    return sub;
}
int Strcomp(Seqstring s1,Seqstring s2)                              //串比较
{
    int j=0;
    while(s1.data[j]==s2.data[j]&&s1.data[j]!='\0')
        j++;
    return (s1.data[j]-s2.data[j]);
}
int BF_Strcomp(Seqstring s1,Seqstring s2)                   //模式匹配
{
    int i=0,j=0;
    while(i<s1.len&&j<s2.len)
    {
        if(s1.data[i]==s2.data[j])
        {i++;j++;}
        else
        {i=i-j+1;j=0;}
    }
    if(j>=s2.len)  return(i-s2.len);
    else return 0;
}
int main()
{
    int i,len,k;
    Seqstring s1,s2,s12,s,sub;
    A:
    printf("********************************\n");
    printf("*请数字选择对单链表的操作\n*0：操作结束\n*1：连接串\n*2：求子串\n*3：比较串\n*4：模式匹配\n");
    printf("********************************\n功能选择：");
    scanf("%d",&k);
    getchar();
    switch(k)
    {
        case 0:break;
        case 1:
            printf("输入串s1：");
            s1=Input_Seqstring(s1);
            printf("输入串s2：");
            s2=Input_Seqstring(s2);
            s12=Strconat(s1,s2);
            printf("输出连接后的串s12\n");
            printf("%s",s12.data);
            break;
        case 2:
            printf("输入主串s：");
            s=Input_Seqstring(s);
            printf("输入子串位置i（第i位）：");
            scanf("%d",&i);
            printf("输入子串长度len：");
            scanf("%d",&len);
            sub=Strsub(s,i,len);
            printf("输出子串：");
            printf("%s\n",sub.data);
            break;
        case 3:
            printf("输入串s1：");
            s1=Input_Seqstring(s1);
            printf("输入串s2：");
            s2=Input_Seqstring(s2);
            i=Strcomp(s1,s2);
            if(i==0)    printf("s1=s2");
            if(i<0)    printf("s1<s2");
            if(i>0)    printf("s1>s2");
            break;
        case 4:
            printf("输入串s1：");
            s1=Input_Seqstring(s1);
            printf("输入串s2：");
            s2=Input_Seqstring(s2);
            i=BF_Strcomp(s1,s2);
            if(i==0)printf("匹配失败\n");
            else printf("s2位于s1第%d位",i+1);
            break;
         default:
            printf("选择错误，请重新输入\n");
            break;
    }
    getchar();
    printf("输入回车继续操作");
    getchar();
    system("cls");
    goto A;
    return 0;
}







