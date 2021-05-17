#include<stdio.h>
#define MAX 10
typedef int datatype;
typedef struct
{
    datatype data[MAX];
    int front,rear;
}cs;
cs *Init_Seqque()               //循环队列初始化
{
    cs *q;
    q=malloc(sizeof(cs));
    q->front=q->rear=0;
    return q;
}
int Jud_Seqque(cs *q)           //判断队列是否为空
{
    if(q->front==q->rear)return 1;
    else return 0;
}
int Insert_Seqque(cs *q,datatype e)     //入队函数
{
    if((q->rear+1)%MAX==q->front)       //判断入队后是否队列是否溢出
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
int Out_Seqque(cs *q)               //出队函数
{
    if(q->front==q->rear)           //判断队列是否为空
    {
        printf("队列为空\n");
        return -1;
    }

    else
    {
        q->front=(q->front+1)%MAX;
        return q->data[q->front];
    }
}
int Cin_Seqque(cs *q)                     //输入队列
{
    printf("请输入循环队列（长度小于10）:");
    int t;
    datatype e;
    do
    {
        scanf("%d",&e);
        t=Insert_Seqque(q,e);
        if(t==-1) return -1;
    }while(getchar()!='\n');            //输入回车后结束输入
    return 1;
}
void Cout_Seqque(cs *q)                 //输出队列
{
    if(q->front==q->rear)           //判断队列是否为空
    {
        printf("循环队列为空\n");
        return -1;
    }
    printf("循环队列为：");
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
    printf("菜单：\n0：退出程序\n1：判断队空\n2：入队\n3：出队\n");
    printf("************************\n功能选择为：");
    scanf("%d",&k);
    switch(k)
    {
        case 0: return 0;
        case 1:
            t=Jud_Seqque(q);
            if(t==1) printf("循环队列为空\n");
            else printf("循环队列不为空\n");
            break;
        case 2:
            printf("请输入入队元素:");
            scanf("%d",&e);
            t=Insert_Seqque(q,e);
            if(t==-1) printf("error\n");
            else Cout_Seqque(q);
            break;
        case 3:
            t=Out_Seqque(q);
            if(t==-1) printf("循环队列为空\n");
            else
            {
                printf("出队元素为：%d\n",t);
                Cout_Seqque(q);
            }
            break;
        default: printf("选择错误请重新选择\n"); goto A;
    }
    printf("\n\n输入回车继续");
    getchar();
    getchar();
    goto A;
}
