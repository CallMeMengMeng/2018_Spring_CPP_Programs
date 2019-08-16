#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#define OK 1

typedef int Status;     /* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef char TElemType;

typedef struct BiTNode  /* 结点结构 */
{
   TElemType data;      /* 结点数据 */
   struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
}BiTNode,*BiTree;


/* 构造空二叉树T */
Status InitBiTree(BiTree *T)
{
    *T=NULL;
    return OK;
}

/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
void DestroyBiTree(BiTree *T)
{
    if(*T)
    {
        if((*T)->lchild) /* 有左孩子 */
            DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
        if((*T)->rchild) /* 有右孩子 */
            DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
        free(*T); /* 释放根结点 */
        *T=NULL; /* 空指针赋0 */
    }
}

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
void CreateBiTree(BiTree *T)
{
    TElemType ch;

    scanf("%c",&ch);

    if(ch=='#')      //#代表这个节点没有子树。
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));          //malloc生成一个内存空间并且强制转化为BiTree类型，类似new的作用。
        if(!*T)
            exit(OVERFLOW);
        (*T)->data=ch; /* 生成根结点 */
        CreateBiTree(&(*T)->lchild); /* 构造左子树 */
        CreateBiTree(&(*T)->rchild); /* 构造右子树 */      //函数参数的传递是单向值传递，当我们是需要改变一个指针的值时，就需要用二重指针做参。
                                                          //如果我们只传递进去一个一个指向节点的指针，调用结束后，这个指针的值是不会改变的。
    }
}

//前序遍历
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
    PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
    PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

int main()
{
    BiTree T;
    InitBiTree(&T);
    CreateBiTree(&T);
    PreOrderTraverse(T);
    return 0;
}
