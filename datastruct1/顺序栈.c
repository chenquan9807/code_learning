#include<stdio.h>
#define MAXSSIZE 100
typedef int datatype;
typedef struct
{
    datatype data[MAXSSIZE];
    int top;
}Seqstack;
Seqstack *Init_sstack()
{
    Seqstack *s;
    s=malloc(sizeof(Seqstack));
    if(s) {s->top=-1;printf("�ÿճɹ�\n");}
    return s;
}
int Empty_SStack(Seqstack *s)
{
    if(s->top==-1) return 1;
    else return 0;
}
int Push_SStack(Seqstack *s,datatype e)
{
    if(s->top==MAXSSIZE-1) return 0;
    else
    {
        s->top++;
        s->data[s->top]=e;
        return 1;
    }
}
void Out_SStack(Seqstack *s)
{
    int k;
    k=s->top;
    if(s->top==-1) {printf("˳��ջΪ��\n");return 0;}
    printf("˳��ջΪ��");
    while(s->top>=0)
    {
        printf("%d ",s->data[s->top]);
        s->top--;
    }
    printf("\n");
    s->top=k;
}
int Pop_SStack(Seqstack *s,datatype *e)
{
    if(Empty_SStack(s)) return 0;
    else
    {
        *e=s->data[s->top];
        s->top--;
        return  1;
    }
}
int Gettop_SStack(Seqstack *s)
{
    if(Empty_SStack(s)) return 0;
    else return (s->data[s->top]);
}
Seqstack *Creat_sstack()
{
    int e;
    Seqstack *s;
    s=malloc(sizeof(Seqstack));
    s->top=-1;
    do
    {
        scanf("%d",&e);
        s->top++;
        s->data[s->top]=e;
    }while(getchar()!='\n');
    printf("������س�");
    return s;
}
int Get_Seqstack(Seqstack *s,int i)
{
     if(s->top==-1) {printf("˳��ջΪ��\n");return 0;}
    if(i>=MAXSSIZE) return -1;
    s->top=i-1;
    return  s->data[s->top];
}                                   //����Ų���
int Locate_Seqstack(Seqstack *s,int i)
{
    int k;
    k=s->top;
    if(s->top==-1) {printf("˳��ջΪ��\n");return 0;}
    while(s->top>=0)
    {
        if(s->data[s->top]==i)
             return ++s->top;
        s->top--;
    }
    s->top=k;
    return -1;
}                                      //�����ݲ���
int main()
{
    Seqstack *s;
    int n,m,i;
    datatype e;
    printf("����һ��˳��ջ������س���������\n");
    s=Creat_sstack();
A:
    getchar();
    printf("\n������س�����");
    getchar();
    system("cls");
    Out_SStack(s);
    printf("****************************\n");
    printf("������ѡ���˳��ջ�Ĳ���\n0����������\n1���ÿ�ջ\n2���жϿ�ջ\n3����ջ\n4����ջ\n5��ȡ��ջ��Ԫ��\n6�����˳��ջ\n7����������˳��ջ\n8����λ�ò���Ԫ��\n9������ֵ����Ԫ��\n");
    printf("****************************\n");
    printf("����ѡ��Ϊ��");
    scanf("%d",&n);
    switch(n)
    {
        case 0:break;
        case 1:s=Init_sstack();goto A;
        case 2:
        {
            m=Empty_SStack(s);
            if(m==1)    printf("ջΪ��ջ\n");
            else    printf("ջ��Ϊ��\n");
            goto A;
        }
        case 3:
            {
                printf("��������ջԪ��e: ");
                scanf("%d",&e);
                m=Push_SStack(s,e);
                if(m==0)    printf("ջ��������ջ\n");
                else printf("��ջ�ɹ�\n");
                goto A;
            }
        case 4:
            {
                m=Pop_SStack(s,&e);
                if(m!=0)    printf("��ջ�ɹ�,��ջԪ��Ϊ%d\n",e);
                else    printf("��ջʧ��\n");
                goto A;
            }
        case 5:
            {
                m=Gettop_SStack(s);
                if(m==0)    printf("ȡ��ʧ��\n");
                else    printf("ջ��Ԫ��Ϊ%d\n",m);
                goto A;
            }
        case 6:Out_SStack(s); goto A;
        case 7:
            {
                printf("����һ��˳��ջ������س���������\n");
                s=Creat_sstack();
                printf("������˳��ջΪ��");
                Out_SStack(s);
            }
            goto A;
        case 8:
            {
                printf("���������λ��i:");
                scanf("%d",&i);
                e=Get_Seqstack(s,i);
                if(e==-1)
                    printf("�����ڵ�%dλԪ��\n");
                else
                    printf("��%dλΪ%d\n",i,e);
                goto A;
            }
        case 9:
            {
                printf("�����������ֵi��");
                scanf("%d",&i);
                e=Locate_Seqstack(s,i);
                if(e==-1) printf("��������ֵΪ%d��Ԫ��\n",i);
                if(e!=-1&&e!=0)
                    printf("��ֵλ%d��Ԫ��λ�ڵ�%dλ\n",i,e);
                goto A;
            }
        default:printf("ѡ�����������ѡ��\n");goto A;
    }
    return 0;
}





