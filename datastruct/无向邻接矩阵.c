#include<stdio.h>
#define MAX 100
typedef struct
{
    char vexs[MAX];       //�����
    int arcs[MAX][MAX];  //�ڽӾ���
    int vex,arc;        //�������ͱ���
}Mgraph;
int LocateVex(Mgraph *G,char a)
{
    int i;
    for(i=0;i<G->vex;i++)
    {
        if(G->vexs[i]==a)
            return i;
    }
    printf("�����ڴ˶���\n");
    return -1;
}
void CreatMgraph(Mgraph *G)
{
    printf("����һ������ͼG\n");
    int i,j,k,m;
    char ch;
    char a,b;
    printf("�����붥�����ͱ����������ʽΪ�������� ������\n");
    scanf("%d%d",&i,&j);
    G->vex=i;
    G->arc=j;
    printf("�����붥����Ϣ��\n");
    getchar();
    for(i=0;i<G->vex;i++)
        scanf("%c",&(G->vexs[i]));
    for(i=0;i<G->vex;i++)
    for(j=0;j<G->vex;j++)
        G->arcs[i][j]=0;
    printf("������ÿ���߶�Ӧ������������Ϣ�������ʽΪ��a,b��:\n");
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
    printf("������Ҫ����ıߣ��������ʽΪ��a,b����\n");
    getchar();
    scanf("%c,%c",&a,&b);
    i=LocateVex(G,a);
    j=LocateVex(G,b);
    if(G->arcs[i][j]==1)
    {
        printf("�˱��Ѵ���\n");
        return ;
    }
    G->arcs[i][j]=1;
    G->arcs[j][i]=1;
}
void Delete_Mgraph(Mgraph *G)
{
    int i,j;
    char a,b;
    printf("������Ҫɾ���ıߣ��������ʽΪ��a,b����\n");
    getchar();
    scanf("%c,%c",&a,&b);
    i=LocateVex(G,a);
    j=LocateVex(G,b);
    if(G->arcs[i][j]==0)
    {
        printf("�˱߲�����\n");
        return ;
    }
    G->arcs[i][j]=0;
    G->arcs[j][i]=0;
}
void Out_Mgraph(Mgraph *G)
{
    int i,j;
    printf("����ͼG���ڽӱ�Ϊ��\n");
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
