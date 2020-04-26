#include<stdio.h>
#include<windows.h>
int main()
{
    int i,j;
    while(1){
        for(i=0;i<5;i++)
        printf("\n");

    printf("     ******       ******\n"
           "   **********   **********\n"
           " ************* *************\n");

    for(i=0;i<3;i++)
    {
        for(j=0;j<29;j++)
        {
            printf("*");

        }
        printf("\n");
    }

    for(i=0;i<7;i++)
    {
        for(j=0;j<2*(i+1)-1;j++)
        {
            printf(" ");
        }
            for(j=0;j<27-i*4;j++)
            {
                printf("*");

            }
            printf("\n");
    }


    Sleep(500);
    system("cls");
    for(i=0;i<10;i++)
        printf("\n");
    printf("       *********************\n"
           "       * ÐÁÓ¢½¡£¬ÎÒÏ²»¶Äã£¡*\n"
           "       *********************\n");
    Sleep(1000);
    system("cls");
    }
    return 0;
}
