#include<stdio.h>
#define MAX 100
typedef struct
{
    char vexs[MAX];       //顶点表
    int arcs[MAX][MAX];  //邻接矩阵
    int vex,arc;        //顶点数和边数
}Mgraph;
int LocateVex(Mgraph *G,char a)
{
    int i;
    for(i=0;i<G->vex;i++)
    {
        if(G->vexs[i]==a)
            return i;
    }
    printf("不存在此顶点\n");
    return -1;
}
void CreatMgraph(Mgraph *G)
{
    printf("创建一个无向图G\n");
    int i,j,k,m;
    char ch;
    char a,b;
    printf("请输入顶点数和边数（输入格式为：顶点数 边数）\n");
    scanf("%d%d",&i,&j);
    G->vex=i;
    G->arc=j;
    printf("请输入顶点信息：\n");
    getchar();
    for(i=0;i<G->vex;i++)
        scanf("%c",&(G->vexs[i]));
    for(i=0;i<G->vex;i++)
    for(j=0;j<G->vex;j++)
        G->arcs[i][j]=0;
    printf("请输入每条边对应的两个顶点信息（输入格式为：a,b）:\n");
    for(k=0;k<G->arc;k++)
    {
        getchar();
        scanf("%c,%c",&a,&b);
        i=LocateVex(G,a);
        j=LocateVex(G,b);
        G->arcs[i][j]=1;
        G->arcs[j][i]=1;
    }
    return G;
}
void Insert_Mgraph(Mgraph *G)
{
    int i,j;
    char a,b;
    printf("请输入要插入的边：（输入格式为：a,b）：\n");
    getchar();
    scanf("%c,%c",&a,&b);
    i=LocateVex(G,a);
    j=LocateVex(G,b);
    if(G->arcs[i][j]==1)
    {
        printf("此边已存在\n");
        return ;
    }
    G->arcs[i][j]=1;
    G->arcs[j][i]=1;
}
void Delete_Mgraph(Mgraph *G)
{
    int i,j;
    char a,b;
    printf("请输入要删除的边：（输入格式为：a,b）：\n");
    getchar();
    scanf("%c,%c",&a,&b);
    i=LocateVex(G,a);
    j=LocateVex(G,b);
    if(G->arcs[i][j]==0)
    {
        printf("此边不存在\n");
        return ;
    }
    G->arcs[i][j]=0;
    G->arcs[j][i]=0;
}
void Out_Mgraph(Mgraph *G)
{
    int i,j;
    printf("无向图G的邻接表为：\n");
    for(i=0;i<G->vex;i++)
    {
        for(j=0;j<G->vex;j++)
        {
            printf("%3d",G->arcs[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    Mgraph G;
    CreatMgraph(&G);
    Out_Mgraph(&G);
    Insert_Mgraph(&G);
    Out_Mgraph(&G);
    Delete_Mgraph(&G);
    Out_Mgraph(&G);
    return 0;
}
