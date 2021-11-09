#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
/*
### 线性表
基本操作：
InitList(&L):初始化
Length(L):求表长
LocateElem(L,e)：按值查找
GetElem(L,i):按位查找
ListInsert(&L,i,e):插入
ListDelete(&L,i):按位删除
PrintList(L):输出
Empty(L):判空
DestroyList(&L):销毁
*/

//定义链表
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode,*LinkList;
//同时使用了typedef,相当于先定义一个struct LNode的结构体；
//然后重命名：
//typedef struct LNode LNode;
//typedef struct LNode *LinkList;
//强调是一个单链表  LinkLisk
//强调是一个节点    LNode*

//头插法插入
LinkList List_HeadInsert(LinkList L) { 
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;//L-data 是一个乱数，因此输出的时候不用输出
    scanf("%d", &x);
    while(x!=(-1)){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//尾插法插入
LinkList List_TailInsert(LinkList L) {
    LNode *s, *r=L;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x!=(-1)){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r ->next = s;
        r = s;
        scanf("%d", &x);
    }
    s->next = NULL;
    return L;
}

//按序号查找节点值,返回第i个的值,包含头节点
LNode *GetElem(LinkList L,int i){
    int j = 1;
    LNode *p = L->next;
    if(i<0){
        return NULL;
    }
    if(i==0)
        return L;
        while(p!=NULL && j<i){
            p = p->next;
            j++;
        }
        return p;
}

//按值查找，返回指针，未找到返回NULL
LNode *LocateElem(LinkList L, int e){
    LNode *p = L->next;
    while(p!=NULL&&p->data!=e){//跳出循环时，p要么指向e，要么指向NULL；
        p = p->next;
    }
    return p;
}

//插入节点操作
bool ListInsert(LinkList L,int i,int e){
    if(i<1)
        return false;
    LNode *s, *p;
    p = GetElem(L, i-1);
    if(p==NULL)
        return false;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除节点操作
bool ListDelete(LinkList L, int i){
    if(i<1)
        return false;
    LNode *s, *p;
    p = GetElem(L, i - 1);
    if(p->next==NULL)
        return false;
    s = p->next;
    p->next = p->next->next;
    free(s);
    return true;
}

//求表长
int Length(LinkList L){
    LNode *p = L->next;
    int i = 0;
    for (; p != NULL;i++,p=p->next)
        ;
    return i;
}

//打印L的所有元素
void PrintList(LinkList L) {
    L = L->next;
    while (L!= NULL) {
		printf("%d ", L->data);
		L = L->next;
	}
}

//建立一个带头节点的单链表，元素是1-i,返回指针
LinkList CreatList(LinkList L, int n){
    LNode *s;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i=n;i>0;i--){//头插法，i--
        s = (LinkList)malloc(sizeof(LNode));
        s->data = i;
        s->next = L->next;
        L->next = s;
    }
    return L;
}


//逆序打印单链表,带头
void R_Print(LinkList L){
    if(L->next!=NULL)
        R_Print(L->next);
    if(L!=NULL)
        printf("%d ", L->data);
}

//逆序打印单链表,不带头
void R_Printf(LinkList L){
    if(L!=NULL)
        R_Print(L->next);
}


//删除最小值
bool DeleteMin(LinkList L){
    if(L->next==NULL)
        return false;
    LNode *pre_min = L, *p = L->next;
    while(p->next!=NULL){
        if(pre_min->next->data>p->next->data)
            pre_min = p;
        p = p->next;
    }
    p = pre_min->next;
    if(p->next==NULL)
        pre_min->next = NULL;
    else
        pre_min->next = p->next;
    free(p);
    return true;
}
//删除最大值
bool DeleteMax(LinkList L){
    if(L->next==NULL)
        return false;
    LNode *pre_min = L, *p = L->next;
    while(p->next!=NULL){
        if(pre_min->next->data<p->next->data)
            pre_min = p;
        p = p->next;
    }
    p = pre_min->next;
    if(p->next==NULL)
        pre_min->next = NULL;
    else
        pre_min->next = p->next;
    free(p);
    return true;
}
