#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义邻接表
typedef struct node
{
 	int  adjvex;
 	int  w;
 	struct node *nextedge;
 }edgenode;
typedef struct
{
      char     data;
      int      id;
      edgenode  *firstedge;
 }vexnode;

void CreateGraph(vexnode* Graph,int vexnumber,int arcnumber)
{
     int i = 0, j = 0, k = 0;
	 int begin,end,duttem;
	 char ch;
     edgenode *p;
     for(i=0;i<vexnumber;i++)
	 {
         Graph[i].id =0;
         Graph[i].firstedge =NULL;
	 }
	 printf("请输入这个图中的各个顶点的值:\n");
     for(i=0;i<vexnumber;i++)
	 {
          scanf("%s",&ch);
			  Graph[i].data=ch;
	}
    printf("请输入图中弧的起始点及权值:其格式为<起点,终点,权值>\n");
    for(k=0;k<arcnumber;k++)
  	{
        scanf("%d,%d,%d",&begin,&end,&duttem);
        p=(edgenode*)malloc(sizeof(edgenode));
        p->adjvex =end-1;
        p->w =duttem;
        Graph[end-1].id ++;
        p->nextedge =Graph[begin-1].firstedge ;
        Graph[begin-1].firstedge =p;
	}
}
int SearchMapPath(vexnode* Graph,int vexnumber,int arcnumber)
{
	    int totaltime=0;
		int m=0;
    	int i,j,k,t;
		char sv[100];
        int front,rear;
		int *topology_queue,*vl,*ve,*el,*ee;
		front=rear=-1;
		t=0;
        topology_queue=(int*)malloc(vexnumber*sizeof(int));
        vl=(int*)malloc(vexnumber*sizeof(int));
        ve=(int*)malloc(vexnumber*sizeof(int));
        el=(int*)malloc(arcnumber*sizeof(int));
        ee=(int*)malloc(arcnumber*sizeof(int));
        edgenode *p;
        for(i=0;i<vexnumber;i++)
				ve[i]=0;
         for(i=0;i<vexnumber;i++)
	   	 {
               if(Graph[i].id==0)
			   topology_queue[++rear]=i;
			   m++;
		}
        while(front!=rear)
	  	{
           front++;
           j=topology_queue[front];
		   m++;
           p=Graph[j].firstedge ;
           while(p)
		   {
            k=p->adjvex ;
            Graph[k].id --;
            if(ve[j]+p->w >ve[k])
               ve[k]=ve[j]+p->w ;
            if(Graph[k].id ==0)
				topology_queue[++rear]=k;
            p=p->nextedge ;
		   }
		}
		if(m<vexnumber)
       	{
            printf("\n本程序所建立的图有回路不可计算出关键路径\n");
            printf("将退出本程序\n");
            return 0;
       }
       totaltime=ve[vexnumber-1];
       for(i=0;i<vexnumber;i++)
             vl[i]=totaltime;
       for(i=vexnumber-2;i>=0;i--)
	   {
             j=topology_queue[i];
             p=Graph[j].firstedge;
             while(p)
			 {
               k=p->adjvex ;
               if((vl[k]-p->w )<vl[j])
               vl[j]=vl[k]-p->w;
               p=p->nextedge;
			 }
		}
    	printf("| 起点 | 终点 | 最早开始时间 | 最迟开始时间 | 差值 | 是否为关键路径 \n");
		i=0;
    	for(j=0;j<vexnumber;j++)
		{
    		p=Graph[j].firstedge;
       		while(p)
		  	{
          		k=p->adjvex;
          		ee[++i]=ve[j];
          		el[i]=vl[k]-p->w;
 				printf("| %4c | %4c | %12d | %12d | %4d |",Graph[j].data ,Graph[k].data ,ee[i],el[i],el[i]-ee[i]);
          		if(el[i]==ee[i])
				{
          			printf(" 此弧为关键活动 ");
		  			sv[t]=Graph[j].data;t++;
		  		}
          		printf("\n");
          		p=p->nextedge;
	   		}
		}
	  	printf("关键路径节点为：");
	  	sv[t]=Graph[vexnumber-1].data;
	  	for(i=0;i<=t;i++)
		{
		   printf("%c",sv[i]);
		   if(sv[i]!=Graph[vexnumber-1].data)
		    	printf("--->");
		}
	  	printf("\n");
	  	printf("关键路径长度为：%d个单位时间\n",totaltime);
      	return 1;
}
int main( )
{
        int vexnumber,arcnumber,totaltime=0;
        printf("请输入这个图中的节点数:");
        scanf("%d",&vexnumber);
        printf("请输入这个图中的弧数:");
        scanf("%d",&arcnumber);
        vexnode* Graph=(vexnode*)malloc(vexnumber*sizeof(vexnode));
	    CreateGraph(Graph,vexnumber,arcnumber);
        SearchMapPath(Graph,vexnumber,arcnumber);
		return 0;
}