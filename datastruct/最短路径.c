#include<stdio.h>
#define SIZE 110
#define INF 1000000;
int map[SIZE][SIZE];  //�ڽӾ���洢
int len[SIZE];  	//d[i]��ʾԴ�㵽i�����ľ���
int visit[SIZE];  //�ڵ��Ƿ񱻷���
int n,m;

int dijkstra(int from, int to){	//��Դ�㵽Ŀ���

    int i;

    for(i = 1 ; i <= n ; i ++){	//��ʼ��
        visit[i] = 0;	//һ��ʼÿ���㶼û������
        len[i] = map[from][i];	//�ȼ���Դ�㵽������ľ���
    }

    int j;
    for(i = 1 ; i < n ; ++i){	//�Գ�Դ���ÿһ���������̼���
        int min = INF;  //��¼��Сlen[i]
        int pos;  //��¼Сlen[i] �ĵ�

        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && min > len[j]){
                pos = j;
                min = len[j];
            }
        }
        visit[pos] = 1;
        for(j = 1 ; j <= n ; ++j){
            if(!visit[j] && (len[j] > (len[pos] +map[pos][j]))){ //���j�ڵ�û�б����ʹ�&&j�ڵ㵽Դ�ڵ�����·��>pos�ڵ㵽Դ�ڵ�����·��+pos�ڵ㵽j�ڵ��·��
                len[j] = len[pos] + map[pos][j];	//����j�ڵ㵽Դ�ڵ�����·��
            }
        }
    }

    return len[to];
}

int main () {
    int i,j;
    printf("���붥�����ͱ���(nm)\n");
    scanf("%d%d",&n,&m);	//��������
    for(i = 1 ; i <= n ; ++i){	//��һ��ʼÿ���㶼���ɴ�
        for(j = 1 ; j <= n ; ++j){
            map[i][j] = INF;
        }
    }
	int a,b,c;	//��������
	printf("����ߵĶ���Ͷ�Ӧ��Ȩֵ(abc)\n");
    for(i = 1 ; i <= m ; ++i){
        scanf("%d%d%d",&a,&b,&c);
        map[a][b] = map[b][a] = c;
    }
    int temp = INF;
	for(i = 1 ; i <= n ; ++i){
		for(j = 1 ; j <= n ; ++j){
			if(map[i][j] == temp)
				map[i][j] = map[j][i];
		}
	}
	printf("��������Ҷ���\n");
	scanf("%d%d",&i,&j);
    int ans=dijkstra(i,j);
    printf("��̾���Ϊ��%d\n",ans);
    return 0;
}
