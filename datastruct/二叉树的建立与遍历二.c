#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct
{
    bitree ptr;
    int flag;
}stacknode;
typedef struct
{
    stacknode elm[MAX];
    int top;
}sqstack;
typedef struct btnode
{
    char data;
    struct btnode *lchild,*rchild;
}btnode,*bitree;
bitree Creatbintree()               //前序遍历创建二叉树
{
    char ch;
    bitree bt;
    scanf("%c",&ch);
    if(ch=='#') bt=NULL;
    else
    {
        bt=(btnode*)malloc(sizeof(btnode));
        bt->data=ch;
        bt->lchild=Creatbintree();
        bt->rchild=Creatbintree();
    }
    return bt;
}
typedef struct
{
    bitree data[MAX];
    int top;
}seqstack;
seqstack *Init_seqstack()
{
    seqstack *s;
    s=malloc(sizeof(seqstack));
    if(s) s->top=-1;
    return s;
}
int push(seqstack *s,bitree e)
{
    if(s->top==MAX-1) return 0;
    else
    {
        s->top++;
        s->data[s->top]=e;
        printf("in e=%c\n",e->data);
        return 1;
    }
}
bitree pop(seqstack *s)
{
    if(s->top==-1) return 0;
    else
    {
        bitree e;
        e=s->data[s->top];
        printf("out e2=%c\n",e->data);
        s->top--;
        return e;
    }
}
void Preorder(bitree bt)                //前序遍历
{
    bitree p;
    seqstack *s;
    s=Init_seqstack();
    p=bt;
    printf("p=%c",p->data);

    while(p!=NULL||s->top!=-1)
    {
        while(p!=NULL)
        {
            push(s,p);
            p=p->lchild;
        }
        if(s->top!=-1)
        {
            p=pop(s);
            printf("%c\n",p->data);
            p-p->rchild;
        }
    }
}
void Inorder(bitree bt)                 //中序遍历
{
        SqStack s;
    bitree  p;
    s=SqStack *Init();
    p=bt;
    while(p!=NULL||stackempty(s))
    {
        while(p!=NULL)
        {
            push(s,p);
            p=p->lchild;
        }
        if(!stackempty(s))
        {
            p=pop(s);
            printf("%d",p->data);
            p=p->rchild;
        }
    }
}
void Posorder(bitree bt)                //后序遍历
{
        SqStack s;
    stacknode x;
    s=SqStack *Init();
    p=bt;
    while(p!=NULL||!stackempty(s))
    {
        if(p!NULL)
        {
            x.ptr=p;
            x.flag=1;
            push(s,x);
            p=p->lchild;
        }
        else
        {
            x=pop(s);
            if(x.flag==1)
            {
                x.flag=2;
                p=x.ptr;
                push(s,x);
                p=p->lchild;
            }
            else
            {
                p=x.ptr;
                printf("%d",p->data);
                p=NULL;
            }
        }
    }
}
int main()
{
    bitree bt;
    printf("请按前序遍的次序历输入二叉树(空节点为#):\n");
    bt=Creatbintree();
    printf("前序遍历得到的次序\n");
    Preorder(bt);
    printf("\n中序遍历得到的次序\n");
    Inorder(bt);
    printf("\n后序遍历得到的次序\n");
    Posorder(bt);
    return 0;
}
