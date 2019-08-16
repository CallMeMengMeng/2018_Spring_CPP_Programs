#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#define OK 1

typedef int Status;     /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef char TElemType;

typedef struct BiTNode  /* ���ṹ */
{
   TElemType data;      /* ������� */
   struct BiTNode *lchild,*rchild; /* ���Һ���ָ�� */
}BiTNode,*BiTree;


/* ����ն�����T */
Status InitBiTree(BiTree *T)
{
    *T=NULL;
    return OK;
}

/* ��ʼ����: ������T���ڡ��������: ���ٶ�����T */
void DestroyBiTree(BiTree *T)
{
    if(*T)
    {
        if((*T)->lchild) /* ������ */
            DestroyBiTree(&(*T)->lchild); /* ������������ */
        if((*T)->rchild) /* ���Һ��� */
            DestroyBiTree(&(*T)->rchild); /* �����Һ������� */
        free(*T); /* �ͷŸ���� */
        *T=NULL; /* ��ָ�븳0 */
    }
}

/* ��ǰ������������н���ֵ��һ���ַ��� */
/* #��ʾ������������������ʾ������T�� */
void CreateBiTree(BiTree *T)
{
    TElemType ch;

    scanf("%c",&ch);

    if(ch=='#')      //#��������ڵ�û��������
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));          //malloc����һ���ڴ�ռ䲢��ǿ��ת��ΪBiTree���ͣ�����new�����á�
        if(!*T)
            exit(OVERFLOW);
        (*T)->data=ch; /* ���ɸ���� */
        CreateBiTree(&(*T)->lchild); /* ���������� */
        CreateBiTree(&(*T)->rchild); /* ���������� */      //���������Ĵ����ǵ���ֵ���ݣ�����������Ҫ�ı�һ��ָ���ֵʱ������Ҫ�ö���ָ�����Ρ�
                                                          //�������ֻ���ݽ�ȥһ��һ��ָ��ڵ��ָ�룬���ý��������ָ���ֵ�ǲ���ı�ġ�
    }
}

//ǰ�����
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
    PreOrderTraverse(T->lchild); /* ��������������� */
    PreOrderTraverse(T->rchild); /* ���������������� */
}

int main()
{
    BiTree T;
    InitBiTree(&T);
    CreateBiTree(&T);
    PreOrderTraverse(T);
    return 0;
}
