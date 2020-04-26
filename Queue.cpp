#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100
typedef struct
{
    int *base;
    int front;
    int rear;
}SqQueue;
int InitQueue(SqQueue &Q)
{
    Q.base=(int*)malloc(MAXQSIZE*sizeof(int));
    if(!Q.base)exit(0);
    Q.front=Q.rear=0;
    return 0;
}//��ʼ��˳�����

int GetHead(SqQueue &Q,int e)
{
    if(!(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE) return 0;
    e=Q.base[Q.front];
    printf("���ض�ͷԪ��%5d\n",e);
    return 0;
}//���ض�ͷԪ��e
void PrintQueue(SqQueue &Q)
{
    int k;
    printf("˳������е�Ԫ�أ�\n");
    for(k=Q.front;k!=Q.rear;k++) printf("%5d",Q.base[k]);
    printf("\n");
}//����˳�����
int QueueLength(SqQueue Q)
{
    int i;
    i=(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
    printf("���г���%5d\n",i);
    if(i)
        printf("         ���зǿ�");
    else
        printf("      ����Ϊ��");
    return 0;
}//�ж϶����Ƿ�Ϊ��
int EnQueue(SqQueue &Q,int e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front) return 0;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return 0;
}//��Ԫ��e���
int DeQueue(SqQueue &Q,int e)
{
    if(Q.front==Q.rear) return 0;
    e=Q.base[Q.front];
    printf("%5d\n",e);
    Q.front=(Q.front+1)%MAXQSIZE;
    return 0;
}// ɾ��Ԫ��e��������ֵ

int main()
{
    int e,i,n;
    SqQueue Q;
    InitQueue(Q);
    printf("1��Ԫ����ӣ�2��Ԫ�س��ӣ�3�����ض�ͷԪ�أ�4�����пշ�0����������\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("ѡ��:       ");
    scanf("%d",&n);
    printf("\n");
    printf("\n");
    while(n!=0)
    {
        switch(n)
        {
            case 1:
                printf("���Ԫ��:  ");
                scanf("%d",&e);
                EnQueue(Q,e);
                PrintQueue(Q);
                printf("\n");
                printf("\n");
                break;
            case 2:
                printf("����Ԫ��:  ");
                DeQueue(Q,e);
                PrintQueue(Q);
                printf("\n");
                printf("\n");
                break;
            case 3:
                GetHead(Q,e);
                printf("\n");
                printf("\n");
                break;
            case 4:
                QueueLength(Q);
                printf("\n");
                printf("\n");
                break;
        }
        printf("ѡ��:       ");
        scanf("%d",&n);
        printf("\n");
        printf("\n");
    }
    //printf("��Һú���ʵ�飬���ܵ���ô�죡\n");
}
