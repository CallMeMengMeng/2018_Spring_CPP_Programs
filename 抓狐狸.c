#include<stdio.h>
#include<stdlib.h>

int main()
{
	char z;
	int pattern;                           //����ģʽ1����2�ı�־����
	int dong;                              //dong�Ǻ���ʵ�ʵĶ�Ѩ
	int cai,jing,i,j;                      //cai�ǲµĶ���jing���������Ƶı�־����
    int trace[1000] = {0};                 //����켣����
    int c;
    int times=5;
    printf("\t\tץ����    \n");
	printf("��Ϸ����   \n");
    printf("С���������һ�����У����ÿ��ѡ��һ��������ץ���꣬     \n");
    printf("�������ڸö��У���ץ����ɹ���Ϸ�������������ڸö�    \n");
    printf("���Աߣ������ܵ�����������ƶ��������Ķ��У������    \n");
    printf("�겻������Ϸ������һ����Ϸ��ֻ��10�λ��ᣡҪ���ջ���ѽ��\n");
   	printf("������������ģʽ��ѡ��һ���� \n");
	printf("ģʽ1�����Ķ�ֱ�����У������һ���߶Σ��ֱ�Ϊ1,2,3,4�� \n");
    printf("ģʽ2�����Ķ���״���У������һ��Բ�Σ��ֱ�Ϊ1,2,3,4��\n");


	do
	{
        printf("\n��ѡ��ģʽ��");
        scanf("%d",&pattern);
        if((pattern!=1)&&(pattern!=2))
         {
            printf("Input Error!");
            printf("\n��ѡ��ģʽ��");
            scanf("%d",&pattern);
         	//return 0;
         }
        system("CLS");                         //��������
        srand( time(NULL) );
        dong = rand()%4+1;                     //��ʼ����Ѩ
        if(pattern==1)
        printf("ֱ��ģʽ��\n");
        if(pattern==2)
        printf("����ģʽ��\n");

        for (i = 0; i < 10; i++)               //��ʼѭ��
        {
            printf("%d���µĶ��ǣ�",dong);
            scanf("%d",&cai);
            while(getchar()!='\n');
            trace[i] =dong;
            printf("aa \n");
            if(dong == cai)break;              //�����˳�ѭ��
            if(pattern==1)
            {
                if(abs(dong-cai)==1)           //ֱ���ͽṹ
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
                if (abs(dong-cai)==1||abs(dong-cai)==3)//���νṹ ����1��4����
                {
                    jing=rand()%2;                     //������ƻ�����
                    if (jing==0)dong++;
                    if (jing==1)dong--;
                    if (dong==0)dong=4;                //1���Ƶ�4
                    if (dong==5)dong=1;                //4���Ƶ�1
                }
            }
        }

        printf("������ƶ��켣��");
        for (j=0; trace[j]!=0 ;j++)          //��ʾ�ټ�
        {
            printf("%d>>> ",trace[j]);
            if(j>=10)
				break;
        }
        if(j<10)
		printf("��ϲ�㣡���걻ץס��\n\n������Ϸ�����¶�һ������%d��,�������Խ�����Ŷ��O(��_��)O~~\n\n",j);
		else if(j>=10)
		 printf("�������ջ��������ˣ����ź�~~~~����һ�ΰ�~~\n");
        for(c=0;c<10;c++)                     //ʹ�������
        {
            trace[c]=0;
        }
       times--;

	if(times!=0)
	{
	printf(" ��һ������%d�λ��ᣬ�����Ƿ������(Y/N):",times);
	scanf("%c",&z);
	while(getchar()!='\n');
	if(z=='n'||z=='N')
	printf("��Ϸ������\n");
	}
	if(times==0)
	{
		printf("\n���ź������Ļ����Ѿ������ˡ�\n");
		return 0 ;
	}
	}
	while(z=='y'||z=='Y');                   // �˻�����

    return 0;
}
