//
// Created by lazy-cat on 2023/3/13.
//
#include "biaotou.h"
#include "queue.h"

//队列的初始化
Queue* queue_init(){
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    assert(temp);
    temp->head = temp->end = NULL;
    return temp;
}

//双链表节点的初始化赋值
Node* create_node(int id, char* name){
    Node* temp = (Node*) malloc(sizeof(Node));
    assert(temp);
    temp->id = id;
    strcpy(temp->name, name);
    temp->prev = temp->pnext = NULL;
    return temp;
}

//双链表节点的连接
void link_node(Node* n1, Node* n2){
    n1->pnext = n2;
    n2->prev = n1;
}

//数据入队：头插
void queue_push(Queue* queue, int id, char* name){
    //判断队列是否为空
    if(NULL == queue->head){
        queue->head = create_node(id, name);//头指针指向新节点
        queue->end = queue->head;//队列中唯一数据，所以既是队头也是哦队尾
    } else {
        Node* temp = create_node(id, name);//临时指针temp，指向新节点
        link_node(temp, queue->head);//新节点作为头部插入
        queue->head = temp;//头指针指向新节点，插入数据进去之后，就是新的队尾
    }
}

//数据出队：尾删
void queue_pop(Queue* queue){
    assert(!queue_isEmpty(queue));//断言：如果队列不为空，程序继续往下执行
    //要删除尾部节点
    if(NULL != queue->end->prev){//假设尾部节点被删除之后，链表中还有数据
        Node* temp = queue->end;//定义临时指针，暂时保存尾结点的地址
        queue->end = temp->prev;//尾指针保存上一个节点的地址
        queue->end->pnext = NULL;//新的尾结点的后继指针指向空
        printf("学号：%d  姓名：%s\n",temp->id, temp->name);
        free(temp);
    } else {//说明尾部节点被删除之后，链表中没有元素了
        printf("学号：%d  姓名：%s\n",queue->end->id, queue->end->name);
        free(queue->end);//释放当前尾结点的空间
        queue->end = queue->head = NULL;//队列中唯一一个节点被删除，所以队头和队尾都为空
    }
}

//判断队列是否为空
bool queue_isEmpty(Queue* queue){
    return (queue->head == NULL);//头指针指向空，说明此时队列为空，返回true；否则返回false，说明队列不空
}