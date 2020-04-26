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
}//初始化顺序队列

int GetHead(SqQueue &Q,int e)
{
    if(!(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE) return 0;
    e=Q.base[Q.front];
    printf("返回队头元素%5d\n",e);
    return 0;
}//返回队头元素e
void PrintQueue(SqQueue &Q)
{
    int k;
    printf("顺序队列中的元素：\n");
    for(k=Q.front;k!=Q.rear;k++) printf("%5d",Q.base[k]);
    printf("\n");
}//遍历顺序队列
int QueueLength(SqQueue Q)
{
    int i;
    i=(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
    printf("队列长度%5d\n",i);
    if(i)
        printf("         队列非空");
    else
        printf("      队列为空");
    return 0;
}//判断队列是否为空
int EnQueue(SqQueue &Q,int e)
{
    if((Q.rear+1)%MAXQSIZE==Q.front) return 0;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return 0;
}//将元素e入队
int DeQueue(SqQueue &Q,int e)
{
    if(Q.front==Q.rear) return 0;
    e=Q.base[Q.front];
    printf("%5d\n",e);
    Q.front=(Q.front+1)%MAXQSIZE;
    return 0;
}// 删除元素e并返回其值

int main()
{
    int e,i,n;
    SqQueue Q;
    InitQueue(Q);
    printf("1—元素入队；2—元素出队；3—返回队头元素；4—队列空否0—结束运行\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("选择:       ");
    scanf("%d",&n);
    printf("\n");
    printf("\n");
    while(n!=0)
    {
        switch(n)
        {
            case 1:
                printf("入队元素:  ");
                scanf("%d",&e);
                EnQueue(Q,e);
                PrintQueue(Q);
                printf("\n");
                printf("\n");
                break;
            case 2:
                printf("出队元素:  ");
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
        printf("选择:       ");
        scanf("%d",&n);
        printf("\n");
        printf("\n");
    }
    //printf("大家好好做实验，别跑的那么快！\n");
}
