#include<stdio.h>
typedef int datatype;
typedef struct node             //定义队节点的类型
{
    datatype data;
    struct node *next;
}Qnode;
typedef struct               //将队头，队尾指针封装在一起
{
    Qnode *front,*rear;
}LQueue;
LQueue *Init_LQue()         //创建带头节点的空队列
{
    LQueue *q;
    Qnode *p;
    q=malloc(sizeof(LQueue));
    p=malloc(sizeof(Qnode));
    p->next=NULL;
    q->front=q->rear=p;
    return q;
}
int In_LQue(LQueue *q,datatype e)      //入队
{
    Qnode *p;
    p=malloc(sizeof(Qnode));            //申请新节点
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return 1;
}
LQueue *Input(LQueue *q)               //输入队列
{
    datatype e,i;
    do
    {
        scanf("%d",&e);
        i=In_LQue(q,e);                 //调用入队函数
    }while(getchar()!='\n');            //输入回车跳出循环
    return q;
}
int Empty_LQue(LQueue *q)               //判断空队
{
    if(q->front==q->rear)   return 0;
    else return 1;
}
int Out_LQue(LQueue *q,datatype *e)    //出队
{
    Qnode *p;
    int i;
    i=Empty_LQue(q);
    if(i==0)
    {
        return 0;
    }                                   //队空，出队失败
    else
    {
        p=q->front->next;
        q->front->next=p->next;
        *e=p->data;                     //队头元素放e中
        printf("%d ",*e);
        free(p);
        if(q->front->next==NULL)        //当原队列只有一个元素时
            q->rear=q->front;           //该元素出队后队列为空，注意修改队尾指针
        return 1;
    }
}
void Output(LQueue *q)              //输出队列
{
    int i,j,e;
    Qnode *p;
    printf("链式队列为：");
    p=q->front->next;
	while(p!=NULL)                  //输出非空元素
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
Qnode *Get_LQue(LQueue *q,int i)//按序号查找(函数调用）
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
void Locate_LQue(LQueue *q,int e)//按值查找
{
    Qnode *p=q->front->next;
    int j=1;
    while(p!=NULL&&p->data!=e)
    {
        p=p->next;
        j++;
    }
    if(p!=NULL) printf("数据元素位于第%d位\n",j);
    else printf("查找失败\n");
}
LQueue *Change_LQue(LQueue *q,int i,int e)//修改数据
{
    Qnode *p;
    p=Get_LQue(q,i);
    if(p==NULL)
        printf("输入位置错误！\n");
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
    printf("输入队列\n");
    q=Input(q);
    A:
    printf("****************************\n");
    printf("请数字选择对链式队列的操作\n0：结束操作\n1：判断空队\n2：入队\n3：出队\n4：按位置查找\n5：按数值查找\n6：修改元素\n7：输出队列\n");
    printf("****************************\n功能选择为：");
    scanf("%d",&c);
    switch(c)
    {
        case 0:printf("操作结束\n");return 0;
        case 1:
            i=Empty_LQue(q);
            if(i==0) printf("队列为空\n");
            else printf("队列不为空\n");
            break;
        case 2:
            printf("请输入入队元素：");
            scanf("%d",&e);
            i=In_LQue(q,e);
            if(i==1) printf("入队成功\n");
            Output(q);
            break;
        case 3:
            printf("出队元素为：");
            i=Out_LQue(q,&e);
            if(i==0)printf("队空");
            printf("\n");
            Output(q);
            break;
        case 4:
            printf("请输入查找位置：");
            scanf("%d",&i);
            p=Get_LQue(q,i);
            if(p==NULL) printf("查找失败\n");
            else printf("该位置数据位%d\n",p->data);
            break;
        case 5:
            printf("请输入查找数据：");
            scanf("%d",&e);
            Locate_LQue(q,e);
            break;
        case 6:
            printf("请输入修改位置：");
            scanf("%d",&i);
            printf("请输入修改后数据的值：");
            scanf("%d",&e);
            q=Change_LQue(q,i,e);
            Output(q);
        case 7:Output(q);break;
        default:printf("输入错误重新选择\n");break;
    }
    getchar();
    printf("输入回车继续");
    getchar();
    system("cls");
    Output(q);
    goto A;
}




