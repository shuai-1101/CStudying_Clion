//
// Created by lazy-cat on 2023/3/13.
//
#include "stack.h"
#include "biaotou.h"

//实现函数的定义

//初始化栈
Stack* stack_init(){
    //定义临时指针，指向申请出来的结构体空间
    Stack* temp=(Stack*) malloc(sizeof(Stack));
    //断言：判断括号中的值是否为真，为真则继续执行下面代码，否则程序终止
    assert(temp);
    temp->top=-1;//-1表示什么数据都没有，如果存放一个数据，top++
    return temp;
}

//入栈：把数据存放到空间中
void Push_Stack(Stack* stack, int value){
    //判断此时空间是否已满
    assert(!Stack_IsFull(stack));//表达式逻辑为真，程序继续执行，表达式逻辑为假则终止
    stack->top++;
    stack->data[stack->top] = value; //将数据写入数组
}

//出栈：把栈顶的元素删除，并返回栈顶元素
int Pop_Stack(Stack* stack){
    //判断此时栈是否为空
    assert(!Stack_IsEmpty(stack));
    return (stack->data[stack->top--]);//后置--  先返回此时栈顶的元素，下标top--
}

//判断当前空间是否已经满了，还能不能存放数据进去
bool Stack_IsFull(Stack* stack){
    return ((stack->top+1) >= SIZE);//表达式返回true，说明空间已满
}

//判断当前的空间是否为空
bool Stack_IsEmpty(Stack* stack){
    return ((stack->top) == -1);
}

//获取此时栈顶存放的数据
int Stack_GetTop(Stack* stack){
    return stack->data[stack->top];
}
