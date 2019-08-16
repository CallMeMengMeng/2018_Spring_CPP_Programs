|//#include "consts.h"
#include <stdio.h>
#define MAXNUM 50
typedef struct
{
	int no;
	int ns;
	char x,y,z;
}Stack;

void Hanoi(Stack st[], int n, char a, char b, char c)
{
	int top = 1;
	int n1;
	char a1, b1, c1;
	st[top].no = 1;
	st[top].ns = n;
	st[top].x = a;
	st[top].y = b;
	st[top].z = c;
	while (top > 0)
	{
		if (st[top].no == 1)
		{
			n1 = st[top].ns;
			a1 = st[top].x;
			b1 = st[top].y;
			c1 = st[top].z;
			top--;
			top++;
			st[top].no = 1;
			st[top].ns = n1-1;
			st[top].x = b1;
			st[top].y = a1;
			st[top].z = c1;
			top++;
			st[top].no = 0;
			st[top].ns = n1;
			st[top].x = a1;
			st[top].y = c1;
			top++;
			st[top].no = 1;
			st[top].ns = n1-1;
			st[top].x = a1;
			st[top].y = c1;
			st[top].z = b1;
		}
		while (top > 0 && (st[top].no == 0 || st[top].ns == 1))
		{
			if (top > 0 && st[top].no == 0)
			{
				printf("\t将第%d个盘片从%c移动到%c\n",st[top].ns,st[top].x,st[top].y);
				top--;
			}
			if (top > 0 && st[top].ns == 1)
			{
				printf("\t将第%d个盘片从%c移动到%c\n",st[top].ns,st[top].x,st[top].z);
				top--;
			}
		}
	}
}

int main (int argc,char* argv[])
{
	int n = -1;
	Stack st[MAXNUM];
	printf("请输入汉诺塔中盘子个数：");
	scanf("%d",&n);
	printf("\nhanoi(%d)的移动过程为：\n",n);
	Hanoi(st,n,'x','y','z');
	return 0;
}
