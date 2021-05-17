#include<stdio.h>
typedef int datatype;
typedef struct node             //����ӽڵ������
{
    datatype data;
    struct node *next;
}Qnode;
typedef struct               //����ͷ����βָ���װ��һ��
{
    Qnode *front,*rear;
}LQueue;
LQueue *Init_LQue()         //������ͷ�ڵ�Ŀն���
{
    LQueue *q;
    Qnode *p;
    q=malloc(sizeof(LQueue));
    p=malloc(sizeof(Qnode));
    p->next=NULL;
    q->front=q->rear=p;
    return q;
}
int In_LQue(LQueue *q,datatype e)      //���
{
    Qnode *p;
    p=malloc(sizeof(Qnode));            //�����½ڵ�
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return 1;
}
LQueue *Input(LQueue *q)               //�������
{
    datatype e,i;
    do
    {
        scanf("%d",&e);
        i=In_LQue(q,e);                 //������Ӻ���
    }while(getchar()!='\n');            //����س�����ѭ��
    return q;
}
int Empty_LQue(LQueue *q)               //�жϿն�
{
    if(q->front==q->rear)   return 0;
    else return 1;
}
int Out_LQue(LQueue *q,datatype *e)    //����
{
    Qnode *p;
    int i;
    i=Empty_LQue(q);
    if(i==0)
    {
        return 0;
    }                                   //�ӿգ�����ʧ��
    else
    {
        p=q->front->next;
        q->front->next=p->next;
        *e=p->data;                     //��ͷԪ�ط�e��
        printf("%d ",*e);
        free(p);
        if(q->front->next==NULL)        //��ԭ����ֻ��һ��Ԫ��ʱ
            q->rear=q->front;           //��Ԫ�س��Ӻ����Ϊ�գ�ע���޸Ķ�βָ��
        return 1;
    }
}
void Output(LQueue *q)              //�������
{
    int i,j,e;
    Qnode *p;
    printf("��ʽ����Ϊ��");
    p=q->front->next;
	while(p!=NULL)                  //����ǿ�Ԫ��
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
Qnode *Get_LQue(LQueue *q,int i)//����Ų���(�������ã�
{

    Qnode *p=q->front->next;
    int j=1;
    while (p->next!=NULL&&j<i)
    {
        p=p->next;
        j++;
    }
    if(j==i) return p;
    else    return NULL;
}
void Locate_LQue(LQueue *q,int e)//��ֵ����
{
    Qnode *p=q->front->next;
    int j=1;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        j++;
    }
    if(p!=NULL) printf("����Ԫ��λ�ڵ�%dλ\n",j);
    else printf("����ʧ��\n");
}
LQueue *Change_LQue(LQueue *q,int i,int e)//�޸�����
{
    Qnode *p;
    p=Get_LQue(q,i);
    if(p==NULL)
        printf("����λ�ô���\n");
    else
        p->data=e;
    return q;
}
int main()
{
    LQueue *q;
    Qnode *p;
    q=Init_LQue();
    int c=1,i;
    datatype e;
    printf("�������\n");
    q=Input(q);
    A:
    printf("****************************\n");
    printf("������ѡ�����ʽ���еĲ���\n0����������\n1���жϿն�\n2�����\n3������\n4����λ�ò���\n5������ֵ����\n6���޸�Ԫ��\n7���������\n");
    printf("****************************\n����ѡ��Ϊ��");
    scanf("%d",&c);
    switch(c)
    {
        case 0:printf("��������\n");return 0;
        case 1:
            i=Empty_LQue(q);
            if(i==0) printf("����Ϊ��\n");
            else printf("���в�Ϊ��\n");
            break;
        case 2:
            printf("���������Ԫ�أ�");
            scanf("%d",&e);
            i=In_LQue(q,e);
            if(i==1) printf("��ӳɹ�\n");
            Output(q);
            break;
        case 3:
            printf("����Ԫ��Ϊ��");
            i=Out_LQue(q,&e);
            if(i==0)printf("�ӿ�");
            printf("\n");
            Output(q);
            break;
        case 4:
            printf("���������λ�ã�");
            scanf("%d",&i);
            p=Get_LQue(q,i);
            if(p==NULL) printf("����ʧ��\n");
            else printf("��λ������λ%d\n",p->data);
            break;
        case 5:
            printf("������������ݣ�");
            scanf("%d",&e);
            Locate_LQue(q,e);
            break;
        case 6:
            printf("�������޸�λ�ã�");
            scanf("%d",&i);
            printf("�������޸ĺ����ݵ�ֵ��");
            scanf("%d",&e);
            q=Change_LQue(q,i,e);
            Output(q);
        case 7:Output(q);break;
        default:printf("�����������ѡ��\n");break;
    }
    getchar();
    printf("����س�����");
    getchar();
    system("cls");
    Output(q);
    goto A;
}




