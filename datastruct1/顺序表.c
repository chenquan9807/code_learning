#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int datatype;
typedef struct
{
    datatype data[MAXSIZE];
    int len;
}Seqlist;                               //��data��len��װ��һ���ṹ��
Seqlist *Init_Seqlist()
{
    Seqlist *L;
    L=malloc(sizeof(Seqlist));
    L->len=-1;
    return L;
}                                       //˳���ĳ�ʼ��
int Insert_Seqlist(Seqlist *L,int i,datatype e)
{
    int j;
    if(L->len==MAXSIZE-1)
    {
        printf("�������\n");
        return -1;
    }                                   //�ų�˳�������
    if(i<1||i>L->len+2)
    {
        printf("λ�ô���\n");
        return 0;
    }                                   //�ų�λ�ô���
    for(j=L->len;j>=i-1;j--)
        L->data[j+1]=L->data[j];        //���ݲ���
    L->data[i-1]=e;
    L->len++;
    printf("������˳���\n");
    for(j=0;j<=L->len;j++)
    {
        printf("%d ",L->data[j]);
    }                                   //˳������
    return 1;
}
int Dele_Seqlist(Seqlist *L,int i)
{
    int j;
    if(L->len==-1)
    {
        printf("������\n");
        return -1;
    }
    if(i<1||i>L->len+1)                //���ձ�ɾ��λ�õĺϷ���
    {
        printf("�����ڵ�%d��Ԫ��\n",i);
        return 0;
    }
    for(j=i;j<=L->len;j++)
        L->data[j-1]=L->data[j];       //ɾ��λ�ú��˳�����ǰ��һλ
    L->len--;
    for(j=0;j<=L->len;j++)
    {
        printf("%d ",L->data[j]);
    }                                  //ɾ���ɹ�
    return 1;
}
int Locate_Seqlist(Seqlist *L,datatype e)
{
    int i=0;
    while(i<=L->len&&L->data[i]!=e)
        i++;                           //λ�ò���
    if(i>L->len)
        return -1;                     //����ʧ��
    else return i;                     //���ش���λ��
}
int Get_Seqlist(Seqlist *L,int i)
{
    if(i<1||i>L->len+1)                //������λ�õĺϷ���
    {
        printf("�����ڵ�%d��Ԫ��\n",i);
        return 0;                      //����ʧ��
    }
    else
        return L->data[i-1];           //���ҳɹ�����������
}
int main()
{
	int a,e,i,j,n,k;
    Seqlist *L=Init_Seqlist();
    L->len=-1;
    printf("������˳�����n(n<=10)\n");
    scanf("%d",&n);
    printf("������˳���\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&L->data[j]);
        L->len++;
    }                                                   //��������
 A:
    printf("˳���Ϊ\n");
    for(j=0;j<=L->len;j++)
    {
        printf("%d ",L->data[j]);
    }
    printf("\n****************************\n");
    printf("��������Ӧ�����֣���ɲ�����\n1���������\n2��ɾ������\n3����ֵ����\n4��ȡ����Ԫ��\n5������\n");
    printf("****************************\n����ѡ��Ϊ��");
    scanf("%d",&a);
    switch(a)
    {
		case 1:
			{
				printf("�������������e��");
				scanf("%d",&e);
				printf("����������%d����λ��i����iλ����",e);
				scanf("%d",&i);
				k=Insert_Seqlist(L,i,e);
				break;                                         //���ݲ����ʵ��
			}
        case 2:
            {
                printf("������ɾ���ڼ�λԪ�أ�i��ֵ����");
                scanf("%d",&i);
                k=Dele_Seqlist(L,i);
                break;                                     // ����ɾ����ʵ��
            }
        case 3:
            {
                printf("�������������e��");
                scanf("%d",&e);
                k=Locate_Seqlist(L,e);
                if(k==-1)
                    printf("˳�����û��Ԫ��%d\n",e);
                else
                    printf("%d��Ϊ˳����%dλԪ��\n",e,k+1);
                break;                                  //��ֵ���ҵ�ʵ��
            }
        case 4:
            {
                printf("��������ȡԪ��λ��i����iλ����");
                scanf("%d",&i);
                k=Get_Seqlist(L,i);
                if(k!=0)
                    printf("��%dΪԪ��Ϊ%d\n",i,k);
                break;                               //��ȡԪ�ص�ʵ��
            }
		case 5: return 0;
        default :
            {
                printf("����ѡ�����������ѡ��\n");
                break;
            }
    }
    getchar();
    printf("\n����س������");
    getchar();
    system("cls");
    goto A;
}
