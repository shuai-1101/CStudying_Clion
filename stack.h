//
// Created by lazy-cat on 2023/3/13.
//
#pragma once
#ifndef C_CLION_STACK_H //如果没有定义这个宏，程序第一次进入.h文件的时候，是没有定义的，
// 会把下面的代码全部执行一遍，到#endif结束。当第二次进入这个头文件时，这个宏被编译了，条件编译
//语句不成立，跳过
#define C_CLION_STACK_H

#include "biaotou.h"

#define SIZE 10 //数组大小的确定

//用数组的方式实现栈
struct Stack{ //结构体是保存栈的信息
    int data[SIZE]; //data是存放数据的空间
    int top; //top表示栈顶元素的下标
};
typedef struct Stack Stack;
//初始化栈
Stack* stack_init();

//入栈：把数据存放到空间中
void Push_Stack(Stack* stack, int value);

//出栈：把栈顶的元素删除
int Pop_Stack(Stack* stack);

//判断当前空间是否已经满了，还能不能存放数据进去
bool Stack_IsFull(Stack* stack);

//判断当前的空间是否为空
bool Stack_IsEmpty(Stack* stack);

//获取此时栈顶存放的数据
int Stack_GetTop(Stack* stack);

#endif //C_CLION_STACK_H
