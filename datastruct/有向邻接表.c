#include<stdio.h>
#define MAX 100
typedef struct node
{
    int adjvex;
    struct node *nextadj;
}Edgenode;
typedef struct vnode
{
    char vertex;
    Edgenode *firstedge;
}Vernode;
typedef Vernode Adjlist[MAX];
typedef struct
{
    Adjlist adjlist;
    int vexnum,arcnum;
}Algraph;
void CreatAlgraph(Algraph *G)
{
    int i,j,k;
    Edgenode *s;
    printf("请输入顶点数和边数：\n");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    printf("请输入顶点信息：\n");
    for(i=0;i<G->vexnum;i++)
    {
        scanf("%c",&(G->adjlist[i].vertex));
        G->adjlist[i].firstedge=NULL;
    }
    printf("请输入边的信息:\n");
    for(k=0;k<G->arcnum;k++)
    {
        scanf("%d%d",&i,&j);
        s=(Edgenode *)malloc(sizeof(Edgenode));
        s->adjvex=j;
        s->nextadj=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=s;
    }
}
void Delete(Algraph *G)
{
    int i,j;
    printf("请输入删除 边的信息:\n");
    scanf("%d%d",&i,&j);
    Edgenode *s;
    s=(Edgenode *)malloc(sizeof(Edgenode));
    s=G->adjlist[i].firstedge;
    s=s->nextadj;
    G->adjlist[i].firstedge=s;
}
void Add(Algraph *G)
{
    int i,j;
    Edgenode *s;
    printf("请输入边的信息:\n");
    scanf("%d%d",&i,&j);
    s=(Edgenode *)malloc(sizeof(Edgenode));
    s->adjvex=j;
    s->nextadj=G->adjlist[i].firstedge;
    G->adjlist[i].firstedge=s;

}
int main()
{
    Algraph G;
    CreatAlgraph(&G);
    Add(&G);
    Delete(&G);
    return 0;
}
