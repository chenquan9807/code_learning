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
Seqstring Strconat(Seqstring s1,Seqstring s2)     //������
{
    int i=0,j;
    Seqstring s;
    if(s1.len+s2.len>MAXSSIZE-1) return;      //*s���Ȳ���
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
Seqstring Strsub(Seqstring s,int i,int len)     //���Ӵ�
{
    int j;
    if(i<1||i>s.len||len>s.len-i+1||s.len<0)
    {
        printf("����ȡֵ����ȷ\n");
        return;
    }
    Seqstring sub;
    for(j=0;j<len;j++)
        sub.data[j]=s.data[i+j-1];
    sub.data[j]='\0';
    sub.len=strlen(sub.data);                             //�Ӵ�������־
    return sub;
}
int Strcomp(Seqstring s1,Seqstring s2)                              //���Ƚ�
{
    int j=0;
    while(s1.data[j]==s2.data[j]&&s1.data[j]!='\0')
        j++;
    return (s1.data[j]-s2.data[j]);
}
int BF_Strcomp(Seqstring s1,Seqstring s2)                   //ģʽƥ��
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
    printf("*������ѡ��Ե�����Ĳ���\n*0����������\n*1�����Ӵ�\n*2�����Ӵ�\n*3���Ƚϴ�\n*4��ģʽƥ��\n");
    printf("********************************\n����ѡ��");
    scanf("%d",&k);
    getchar();
    switch(k)
    {
        case 0:break;
        case 1:
            printf("���봮s1��");
            s1=Input_Seqstring(s1);
            printf("���봮s2��");
            s2=Input_Seqstring(s2);
            s12=Strconat(s1,s2);
            printf("������Ӻ�Ĵ�s12\n");
            printf("%s",s12.data);
            break;
        case 2:
            printf("��������s��");
            s=Input_Seqstring(s);
            printf("�����Ӵ�λ��i����iλ����");
            scanf("%d",&i);
            printf("�����Ӵ�����len��");
            scanf("%d",&len);
            sub=Strsub(s,i,len);
            printf("����Ӵ���");
            printf("%s\n",sub.data);
            break;
        case 3:
            printf("���봮s1��");
            s1=Input_Seqstring(s1);
            printf("���봮s2��");
            s2=Input_Seqstring(s2);
            i=Strcomp(s1,s2);
            if(i==0)    printf("s1=s2");
            if(i<0)    printf("s1<s2");
            if(i>0)    printf("s1>s2");
            break;
        case 4:
            printf("���봮s1��");
            s1=Input_Seqstring(s1);
            printf("���봮s2��");
            s2=Input_Seqstring(s2);
            i=BF_Strcomp(s1,s2);
            if(i==0)printf("ƥ��ʧ��\n");
            else printf("s2λ��s1��%dλ",i+1);
            break;
         default:
            printf("ѡ���������������\n");
            break;
    }
    getchar();
    printf("����س���������");
    getchar();
    system("cls");
    goto A;
    return 0;
}







