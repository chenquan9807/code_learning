#include<stdio.h>
#include<stdlib.h>

typedef struct btnode
{
    char data;
    struct btnode *lchild,*rchild;
}btnode,*bitree;
bitree Creatbintree()               //ǰ���������������
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
void Preorder(bitree bt)                //ǰ�����
{
    if(bt==NULL) return;
    printf("%c ",bt->data);
    Preorder(bt->lchild);
    Preorder(bt->rchild);
}
void Inorder(bitree bt)                 //�������
{
    if(bt==NULL) return;
    Preorder(bt->lchild);
    printf("%c ",bt->data);
    Preorder(bt->rchild);
}
void Posorder(bitree bt)                //�������
{
    if(bt==NULL) return;
    Preorder(bt->lchild);
    Preorder(bt->rchild);
    printf("%c ",bt->data);
}
int main()
{
    bitree bt;
    printf("�밴ǰ���Ĵ��������������(�սڵ�Ϊ#):\n");
    bt=Creatbintree();
    printf("ǰ������õ��Ĵ���\n");
    Preorder(bt);
    printf("\n��������õ��Ĵ���\n");
    Inorder(bt);
    printf("\n��������õ��Ĵ���\n");
    Posorder(bt);
    return 0;
}
