#include<stdio.h>
#define MAX 10
typedef int datatype;
typedef struct
{
    datatype data[MAX];
    int front,rear;
}cs;
cs *Init_Seqque()               //ѭ�����г�ʼ��
{
    cs *q;
    q=malloc(sizeof(cs));
    q->front=q->rear=0;
    return q;
}
int Jud_Seqque(cs *q)           //�ж϶����Ƿ�Ϊ��
{
    if(q->front==q->rear)return 1;
    else return 0;
}
int Insert_Seqque(cs *q,datatype e)     //��Ӻ���
{
    if((q->rear+1)%MAX==q->front)       //�ж���Ӻ��Ƿ�����Ƿ����
    {
        printf("all\n");
        return -1;
    }
    else
    {
        q->rear=(q->rear+1)%MAX;
        q->data[q->rear]=e;
        return 1;
    }
}
int Out_Seqque(cs *q)               //���Ӻ���
{
    if(q->front==q->rear)           //�ж϶����Ƿ�Ϊ��
    {
        printf("����Ϊ��\n");
        return -1;
    }

    else
    {
        q->front=(q->front+1)%MAX;
        return q->data[q->front];
    }
}
int Cin_Seqque(cs *q)                     //�������
{
    printf("������ѭ�����У�����С��10��:");
    int t;
    datatype e;
    do
    {
        scanf("%d",&e);
        t=Insert_Seqque(q,e);
        if(t==-1) return -1;
    }while(getchar()!='\n');            //����س����������
    return 1;
}
void Cout_Seqque(cs *q)                 //�������
{
    if(q->front==q->rear)           //�ж϶����Ƿ�Ϊ��
    {
        printf("ѭ������Ϊ��\n");
        return -1;
    }
    printf("ѭ������Ϊ��");
    int t;
    t=q->front+1;
    while(t!=q->rear+1)
    {
        printf("%d ",q->data[t]);
        t=(t+1)%MAX;
    }
    printf("\n");
}
int main()
{
    int t,k;
    datatype e;
    cs *q;
    q=Init_Seqque();
    t=Cin_Seqque(q);
    Cout_Seqque(q);
    A:
    system("cls");
    Cout_Seqque(q);
    printf("************************\n");
    printf("�˵���\n0���˳�����\n1���ж϶ӿ�\n2�����\n3������\n");
    printf("************************\n����ѡ��Ϊ��");
    scanf("%d",&k);
    switch(k)
    {
        case 0: return 0;
        case 1:
            t=Jud_Seqque(q);
            if(t==1) printf("ѭ������Ϊ��\n");
            else printf("ѭ�����в�Ϊ��\n");
            break;
        case 2:
            printf("���������Ԫ��:");
            scanf("%d",&e);
            t=Insert_Seqque(q,e);
            if(t==-1) printf("error\n");
            else Cout_Seqque(q);
            break;
        case 3:
            t=Out_Seqque(q);
            if(t==-1) printf("ѭ������Ϊ��\n");
            else
            {
                printf("����Ԫ��Ϊ��%d\n",t);
                Cout_Seqque(q);
            }
            break;
        default: printf("ѡ�����������ѡ��\n"); goto A;
    }
    printf("\n\n����س�����");
    getchar();
    getchar();
    goto A;
}
