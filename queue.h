//
// Created by lazy-cat on 2023/3/13.
//

#ifndef C_CLION_QUEUE_H
#define C_CLION_QUEUE_H

#include "biaotou.h"
//用双链表实现队列

//节点结构体的声明
struct Node{
    int id;//学号
    char name[20];//姓名
    struct Node* prev;//前驱指针
    struct Node* pnext;//后继指针
};
typedef struct Node Node;
//保存双链表属性的结构体
struct Queue{
    Node* head;//头指针保存头结点的地址 头插，head表示队列的队尾
    Node*end;//尾指针保存尾结点的地址  尾删，end表示队列的队头
};
typedef struct Queue Queue;

//队列的初始化
Queue* queue_init();

//双链表节点的初始化赋值
Node* create_node(int id, char* name);

//双链表节点的连接
void link_node(Node* n1, Node* n2);

//数据入队：头插
void queue_push(Queue* queue, int id, char* name);

//数据出队：尾删
void queue_pop(Queue* queue);

//判断队列是否为空
bool queue_isEmpty(Queue* queue);

#endif //C_CLION_QUEUE_H
