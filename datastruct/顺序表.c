#include<stdio.h>
#define MAX 100
typedef int datatype;
typedef struct                              //˳���ṹ��Ķ���
{
    datatype data[MAX];
    int len;
}SeqList;
SeqList *Init_SeqList()                     //˳���ĳ�ʼ��
{
    SeqList *L;
    L=malloc(sizeof(SeqList));
    L->len=-1;
    return L;
}
int Insert_SeqList(SeqList *L,int i,datatype e)//˳���Ĳ���
{
    int j;
    if(L->len==MAX) return -1;                  //�жϲ���λ���Ƿ�����Ҫ��
    if(i<1||i>L->len+2)return 0;                //�жϲ���λ���Ƿ�����Ҫ��
    for(j=L->len;j>=i-1;j--)
        L->data[j+1]=L->data[j];
    L->data[i-1]=e;
    L->len++;
    return 1;
}
int Delate_SeqList(SeqList *L,int i)            //˳���ĳһλ�õ�ɾ��
{
    int j;
    if(i<1||i>L->len) return -1;
    for(j=i-1;j<=L->len;j++)
        L->data[j]=L->data[j+1];
    L->len--;
    return 1;
}
int Findnum_SeqList(SeqList *L,int i)            //����ֵ����
{
    int j,t=-1;
    for(j=0;j<=L->len;j++)
    {
        if(L->data[j]==i)
            t=j+1;
    }
    if(t==-1) return -1;                        //˳�����û�и���ֵ
    return t;
}
int Findpos_SeqList(SeqList *L,int i)           //��λ�ò���
{
    if(i<1||i>L->len+1) return -1;              //λ�ó���˳���Χ
    return L->data[i-1];
}
SeqList *Input_SeqList(SeqList *L)              //˳�������루����С��100��
{
    int i;
    datatype e;
    L->len=0;
    printf("������˳�������С��100��:\n");
    do
    {
        scanf("%d",&e);
        L->data[L->len]=e;
        L->len++;
    }while(getchar()!='\n');                    //����س��������
    if(L->len>=MAX) return -1;
    return L;
}
int out_SeqList(SeqList *L)             //˳�������
{
    printf("˳���Ϊ:\n");
    int j;
    for(j=0;j<L->len;j++)
    {
        printf("%d ",L->data[j]);
    }
    printf("\n");
    return 0;
}
int main()
{
    int i,t,m;
    datatype e;
    SeqList *L=Init_SeqList();
    L=Input_SeqList(L);
 A:
    system("cls");
    m=out_SeqList(L);
    printf("************************\n");
    printf("�˵���\n0���˳�����\n1������\n2��ɾ��\n3������ֵ����\n4����λ�ò���\n");
    printf("************************\n����ѡ��Ϊ��");
    scanf("%d",&t);
    switch(t)
    {
    case 0:
        return 0;
    case 1:
        printf("���������λ�ã�");
        scanf("%d",&i);
        printf("�����������ֵ��С��");
        scanf("%d",&e);
        m=Insert_SeqList(L,i,e);
        if(m==-1||m==0)
            {printf("λ�ô���\n");break;}
        m=out_SeqList(L);
            break;
    case 2:
        printf("������ɾ��λ�ã�");
        scanf("%d",&i);
        m=Delate_SeqList(L,i);
        if(m==-1){printf("λ�ô���\n");break;}
        m=out_SeqList(L);
        break;
    case 3:
        printf("�����������ֵ��");
        scanf("%d",&i);
        m=Findnum_SeqList(L,i);
        if(m==-1){printf("˳�����û�и���ֵ\n");break;}
        printf("��ֵ%d��λ��Ϊ��%d\n",i,m);
        break;
    case 4:
        printf("���������λ�ã�");
        scanf("%d",&i);
        m=Findpos_SeqList(L,i);
        if(m==-1) {printf("λ�ô���\n");break;}
        printf("��%dλ����ֵΪ:   %d\n",i,m);
        break;
        default:printf("�����������������\n");
    }
    printf("\n\n����س�����");
    getchar();
    getchar();
    goto A;
}
