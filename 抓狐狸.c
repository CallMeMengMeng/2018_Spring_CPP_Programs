#include<stdio.h>
#include<stdlib.h>

int main()
{
	char z;
	int pattern;                           //定义模式1，或2的标志变量
	int dong;                              //dong是狐狸实际的洞穴
	int cai,jing,i,j;                      //cai是猜的洞，jing是左移右移的标志变量
    int trace[1000] = {0};                 //定义轨迹数组
    int c;
    int times=5;
    printf("\t\t抓狐狸    \n");
	printf("游戏规则：   \n");
    printf("小狐狸随机在一个洞中，玩家每次选择一个洞进行抓狐狸，     \n");
    printf("若狐狸在该洞中，则抓狐狸成功游戏结束，若狐狸在该洞    \n");
    printf("的旁边，狐狸受到惊动，随机移动到附近的洞中；否则狐    \n");
    printf("狸不动，游戏继续。一次游戏中只有10次机会！要把握机会呀！\n");
   	printf("请在以下两个模式中选择一个： \n");
	printf("模式1：若四洞直线排列，则洞组成一个线段，分别为1,2,3,4。 \n");
    printf("模式2：若四洞环状排列，则洞组成一个圆形，分别为1,2,3,4。\n");


	do
	{
        printf("\n请选择模式：");
        scanf("%d",&pattern);
        if((pattern!=1)&&(pattern!=2))
         {
            printf("Input Error!");
            printf("\n请选择模式：");
            scanf("%d",&pattern);
         	//return 0;
         }
        system("CLS");                         //清屏函数
        srand( time(NULL) );
        dong = rand()%4+1;                     //初始化洞穴
        if(pattern==1)
        printf("直线模式：\n");
        if(pattern==2)
        printf("环形模式：\n");

        for (i = 0; i < 10; i++)               //开始循环
        {
            printf("%d您猜的洞是：",dong);
            scanf("%d",&cai);
            while(getchar()!='\n');
            trace[i] =dong;
            printf("aa \n");
            if(dong == cai)break;              //猜中退出循环
            if(pattern==1)
            {
                if(abs(dong-cai)==1)           //直线型结构
                {
                    jing=rand()%2;
                    if(jing==0)dong++;
                    if(jing==1)dong--;
                    if(dong==0)dong=2;
                    if(dong==5)dong=3;
                }
            }
            if(pattern==2)
            {
                if (abs(dong-cai)==1||abs(dong-cai)==3)//环形结构 考虑1与4相连
                {
                    jing=rand()%2;                     //随机左移或右移
                    if (jing==0)dong++;
                    if (jing==1)dong--;
                    if (dong==0)dong=4;                //1左移到4
                    if (dong==5)dong=1;                //4右移到1
                }
            }
        }

        printf("狐狸的移动轨迹是");
        for (j=0; trace[j]!=0 ;j++)          //显示踪迹
        {
            printf("%d>>> ",trace[j]);
            if(j>=10)
				break;
        }
        if(j<10)
		printf("恭喜你！狐狸被抓住了\n\n本局游戏中您猜对一共用了%d次,您还可以接着玩哦！O(∩_∩)O~~\n\n",j);
		else if(j>=10)
		 printf("狐狸最终还是溜走了，很遗憾~~~~再试一次吧~~\n");
        for(c=0;c<10;c++)                     //使数组归零
        {
            trace[c]=0;
        }
       times--;

	if(times!=0)
	{
	printf(" 您一共还有%d次机会，请问是否继续？(Y/N):",times);
	scanf("%c",&z);
	while(getchar()!='\n');
	if(z=='n'||z=='N')
	printf("游戏结束！\n");
	}
	if(times==0)
	{
		printf("\n很遗憾，您的机会已经用完了。\n");
		return 0 ;
	}
	}
	while(z=='y'||z=='Y');                   // 人机交互

    return 0;
}
