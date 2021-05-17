#include<stdio.h>
#define MAX 100
typedef int datatype;
typedef struct
{
    datatype data[MAX];
    int top;
}Seqstack;
Seqstack *Init_Seqstack()
{
    Seqstack *s;
    s=malloc(sizeof(Seqstack));
    s->top=-1;
    return s;
}
int Judge_Seqstack(Seqstack *s)
{
    if(s->top==-1) return 1;
    else return 0;
}
int Push_Seqstack(Seqstack *s,datatype e)
{
    if(s->top==MAX-1) return -1;
    else
    {
        s->top++;
        s->data[s->top]=e;
        return 1;
    }
}
int Pop_Seqstack(Seqstack *s)
{
    if(s->top==-1) return -1;
    else
    {
        s->top--;
        return s->data[s->top+1];
    }
}
int Get_Seqstack(Seqstack *s)
{
    if(s->top==-1) return -1;
    else
        return s->data[s->top];
}
int Input_Seqstack(Seqstack *s)
{
    int t;
    datatype e;
    do
    {
        scanf("%d",&e);
        t=Push_Seqstack(s,e);
        if(t==-1)
        {
            printf("����˳��ջ����\n");
            return -1;
        }
    }while(getchar()!='\n');
    return 0;
}
void Output_Seqstack(Seqstack *s)
{
    printf("˳��ջΪ��");
    int t;
    t=s->top;
    while(t>=0)
    {
        printf("%d ",s->data[t]);
        t--;
    }
    printf("\n");
}
int main()
{
    int t,k;
    datatype e;
    Seqstack *s;
    s=Init_Seqstack();
    printf("������˳��ջ��");
    t=Input_Seqstack(s);
    A:
    system("cls");
    Output_Seqstack(s);
    printf("************************\n");
    printf("�˵���\n0���˳�����\n1���жϿ�ջ\n2����ջ\n3����ջ\n4��ȡ��ջ��Ԫ��\n");
    printf("************************\n����ѡ��Ϊ��");
    scanf("%d",&k);
    switch(k)
    {
        case 0:return 0;
        case 1:
            t=Judge_Seqstack(s);
            if(t==1)    printf("˳��ջΪ��\n");
            else printf("˳��ջ��Ϊ��\n");
            break;
        case 2:
            printf("��������ջԪ�أ�\n");
            scanf("%d",&e);
            t=Push_Seqstack(s,e);
            if(t==-1) printf("˳��ջ����\n");
            else
                Output_Seqstack(s);
            break;
        case 3:
            t=Pop_Seqstack(s);
            if(s->top==-1) printf("˳��ջΪ��\n");
            else
            {
                printf("��ջԪ��Ϊ��%d\n",t);
                Output_Seqstack(s);
            }
            break;
        case 4:
            t=Get_Seqstack(s);
            if(s->top==-1) printf("˳��ջΪ��\n");
            else printf("ջ��Ԫ��Ϊ��%d\n",t);
            break;
        default: printf("ѡ�����������ѡ��\n"); goto A;
    }
    printf("\n\n����س�����");
    getchar();
    getchar();
    goto A;
}
