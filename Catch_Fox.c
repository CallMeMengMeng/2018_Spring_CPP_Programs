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
    printf("\t\tץ����\n");
	printf("��Ϸ����\n");
    printf("С���������һ�����У����ÿ��ѡ��һ��������ץ���꣬\n");
    printf("�������ڸö��У���ץ����ɹ���Ϸ�������������ڸö�\n");
    printf("���Աߣ������ܵ�����������ƶ��������Ķ��У������\n");
    printf("�겻������Ϸ������������������ģʽ��ѡ��һ����\n\n");
	printf("ģʽ1�����Ķ�ֱ�����У������һ���߶Σ��ֱ�Ϊ1,2,3,4��\n");
    printf("ģʽ2�����Ķ���״���У������һ��Բ�Σ��ֱ�Ϊ1,2,3,4��\n");
	do
	{
        printf("\n��ѡ��ģʽ��");
        scanf("%d",&pattern);
        system("CLS");                         //��������
        srand( time(NULL) );
        dong = rand()%4+1;                     //��ʼ����Ѩ

        for (i = 0; i < 10; i++)               //��ʼѭ��
        {
            printf("%d���µĶ��ǣ�",dong);
            scanf("%d",&cai);
            while(getchar()!='\n');
            trace[i] =dong;
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
            else
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
        for (j=0; trace[j]!=0 ;j++)
        {
            printf("%d>>> ",trace[j]);        //��ʾ�ټ�
        }
		printf("������%d��\n",j);
        for(c=0;c<10;c++)                     //ʹ�������
        {
            trace[c]=0;
        }
        printf(" �����Ƿ������(Y/N):");
        scanf("%c",&z);
        while(getchar()!='\n');
        if(z=='n'||z=='N')printf("��Ϸ������\n");
	}
	while(z=='y'||z=='Y');                   // �˻�����

    return 0;
}
