#include<stdio.h>
#define MAXQSIZE 100
typedef  int datatype;
typedef struct                          //定义循环队列
{
    datatype data[MAXQSIZE];
    int front,rear;
}c_Seqque;
c_Seqque *Init_Seqque()                 //置空队
{
    c_Seqque *q;
    q=malloc(sizeof(c_Seqque));
    q->front=q->rear=0;
    return q;
}
c_Seqque *In_Seqque(c_Seqque *q,datatype e)     //入队
{
    c_Seqque *p;
    p=q;
    if((p->rear+1)%MAXQSIZE==p->front)      //队满不能入队
    {
        printf("队满\n");
        return NULL;
    }
    else                                   //入队完成
    {
        p->rear=(p->rear+1)%MAXQSIZE;
        p->data[p->rear]=e;
        return q;
    }
}
c_Seqque *input(c_Seqque *q)                //输入队
{
    int e,k;
    do
    {
        scanf("%d",&e);
        k=In_Seqque(q,e);
    }while(getchar()!='\n');
    printf("输入结束\n");
    return q;
}
int Out_Seqque(c_Seqque *q,datatype *e)    //出队
{
    if(q->front==q->rear)                   //队空不能出队
    {
        printf("对空\n");
        return -1;
    }
    else                                   //出队完成
    {
        q->front=(q->front+1)%MAXQSIZE;
        *e=q->data[q->front];
        return *e;
    }
}
int Empty_Seqque(c_Seqque *q)              //判断队空
{
    if(q->rear==q->front) return 1;
    else return 0;
}
void output(c_Seqque *q)
{
    int e,k,m;
    m=q->front;
    printf("队列为：\n队头||");
    while(q->front!=q->rear)
    {
        k=Out_Seqque(q,&e);
        printf("%d ",k);
    }
    printf("||队尾\n");
    q->front=m;
}
int main()
{
    c_Seqque *T;
    T=Init_Seqque();
    int i,o,e;
    printf("请输入顺序队列\n");
    T=input(T);
    printf("顺序队列为：\n");
    output(T);
    A:
    printf("****************************\n");
    printf("请数字选择对顺序栈的操作\n0：结束操作\n1：入队\n2：出队\n3：判断空队\n4：输出队列\n");
    printf("****************************\n");
    scanf("%d",&i);
    switch(i)
    {
        case 0: printf("操作结束\n");return 0;
        case 1:
            printf("输入入队元素e：");
            scanf("%d",&e);
            T=In_Seqque(T,e);
            if(T==NULL) printf("队满不能入队\n");
            else printf("入队完成\n");
            output(T);
            break;
        case 2:
            o=Out_Seqque(T,&e);
            if(o==-1) printf("队空不能出队\n");
            else printf("出队元素为：%d\n",o);
            output(T);
            break;
        case 3:
            o=Empty_Seqque(T);
            if(o==1) printf("队空\n");
            else    printf("队不为空\n");
            break;
        case 4:output(T);break;
        default:printf("选择错误请重新选择\n");break;
    }
    getchar();
    printf("输入回车继续");
    getchar();
    system("cls");
    printf("顺序队列为：\n");
    output(T);
    goto A;
}




