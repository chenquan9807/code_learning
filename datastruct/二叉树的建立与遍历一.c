#include<stdio.h>
#include<stdlib.h>

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
void Preorder(bitree bt)                //前序遍历
{
    if(bt==NULL) return;
    printf("%c ",bt->data);
    Preorder(bt->lchild);
    Preorder(bt->rchild);
}
void Inorder(bitree bt)                 //中序遍历
{
    if(bt==NULL) return;
    Preorder(bt->lchild);
    printf("%c ",bt->data);
    Preorder(bt->rchild);
}
void Posorder(bitree bt)                //后序遍历
{
    if(bt==NULL) return;
    Preorder(bt->lchild);
    Preorder(bt->rchild);
    printf("%c ",bt->data);
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
