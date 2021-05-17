#include<stdio.h>
typedef int datatype;
typedef char Datatype;
typedef struct  Bithrnode
{
    Datatype data;
    struct Bithrtree *lchild;
    struct Bithrtree *rchild;
    int ltag,rtag;
}Bithrtree;
Bithrtree *current=NULL;
Bithrtree *CreatBithrtree()
{
    Bithrtree *t;
    Datatype ch;
    scanf("%c",&ch);
    if(ch=='#')
        exit(0);
    if(ch=='@')
        t=NULL;
    else
    {
        t=(Bithrtree *)malloc(sizeof(Bithrtree));
        if(!t) return -1;
        t->data=ch;
        t->ltag=0;
        t->rtag=0;
        t->lchild=CreatBithrtree();
        t->rchild=CreatBithrtree();
    }
    return t;
}
void Inthree(Bithrtree *p)
{
    if(p!=NULL)
    {
        Inthree(p->lchild);
        if(p->lchild==NULL)
            p->ltag=1;
        if(p->rchild==NULL)
            p->rtag=1;
        if(current!=NULL)
        {
            if(current->rtag==1)
                current->rchild=p;
            if(p->ltag==1)
                p->lchild=current;
        }
        current=p;
        Inthree(p->rchild);
    }
}
void Inorder(Bithrtree *t)
{
    while (t!=NULL)
    {
        while(t->ltag==0)
            t=t->lchild;
        if(t==NULL)
            return;
        printf("%c",t->data);
        while(t->rtag==1&&t->rchild!=NULL)
        {
            t=t->rchild;
            printf("%c",t->data);
        }
        t=t->rchild;
    }
    printf("\n\t\t");
}
int main()
{
    Bithrtree *tree;
    printf("请输入先序序列二叉树\n");
    tree=CreatBithrtree();
    Inthree(tree);
    printf("按中序序列输出二叉树\n");
    Inorder(tree);
    return 0;
}




