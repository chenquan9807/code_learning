#include<stdio.h>
#define MAXQSIZE 100
typedef  int datatype;
typedef struct                          //����ѭ������
{
    datatype data[MAXQSIZE];
    int front,rear;
}c_Seqque;
c_Seqque *Init_Seqque()                 //�ÿն�
{
    c_Seqque *q;
    q=malloc(sizeof(c_Seqque));
    q->front=q->rear=0;
    return q;
}
c_Seqque *In_Seqque(c_Seqque *q,datatype e)     //���
{
    c_Seqque *p;
    p=q;
    if((p->rear+1)%MAXQSIZE==p->front)      //�����������
    {
        printf("����\n");
        return NULL;
    }
    else                                   //������
    {
        p->rear=(p->rear+1)%MAXQSIZE;
        p->data[p->rear]=e;
        return q;
    }
}
c_Seqque *input(c_Seqque *q)                //�����
{
    int e,k;
    do
    {
        scanf("%d",&e);
        k=In_Seqque(q,e);
    }while(getchar()!='\n');
    printf("�������\n");
    return q;
}
int Out_Seqque(c_Seqque *q,datatype *e)    //����
{
    if(q->front==q->rear)                   //�ӿղ��ܳ���
    {
        printf("�Կ�\n");
        return -1;
    }
    else                                   //�������
    {
        q->front=(q->front+1)%MAXQSIZE;
        *e=q->data[q->front];
        return *e;
    }
}
int Empty_Seqque(c_Seqque *q)              //�ж϶ӿ�
{
    if(q->rear==q->front) return 1;
    else return 0;
}
void output(c_Seqque *q)
{
    int e,k,m;
    m=q->front;
    printf("����Ϊ��\n��ͷ||");
    while(q->front!=q->rear)
    {
        k=Out_Seqque(q,&e);
        printf("%d ",k);
    }
    printf("||��β\n");
    q->front=m;
}
int main()
{
    c_Seqque *T;
    T=Init_Seqque();
    int i,o,e;
    printf("������˳�����\n");
    T=input(T);
    printf("˳�����Ϊ��\n");
    output(T);
    A:
    printf("****************************\n");
    printf("������ѡ���˳��ջ�Ĳ���\n0����������\n1�����\n2������\n3���жϿն�\n4���������\n");
    printf("****************************\n");
    scanf("%d",&i);
    switch(i)
    {
        case 0: printf("��������\n");return 0;
        case 1:
            printf("�������Ԫ��e��");
            scanf("%d",&e);
            T=In_Seqque(T,e);
            if(T==NULL) printf("�����������\n");
            else printf("������\n");
            output(T);
            break;
        case 2:
            o=Out_Seqque(T,&e);
            if(o==-1) printf("�ӿղ��ܳ���\n");
            else printf("����Ԫ��Ϊ��%d\n",o);
            output(T);
            break;
        case 3:
            o=Empty_Seqque(T);
            if(o==1) printf("�ӿ�\n");
            else    printf("�Ӳ�Ϊ��\n");
            break;
        case 4:output(T);break;
        default:printf("ѡ�����������ѡ��\n");break;
    }
    getchar();
    printf("����س�����");
    getchar();
    system("cls");
    printf("˳�����Ϊ��\n");
    output(T);
    goto A;
}




