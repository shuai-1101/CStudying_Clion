#include "stack.h"
#include "biaotou.h"
#include "queue.h"
int main() {

/*    //初始化栈
    Stack* stack = stack_init();
    //入栈
    for (int i = 0; i < 10; ++i) {
        Push_Stack(stack,i*10);
    }
    //判断此时栈是否已经满了
    if (true == Stack_IsFull(stack)) {
        printf("栈已满!\n");
    }
    printf("此时栈顶元素为：%d\n", Stack_GetTop(stack));

    //数据出栈
    for (; (Stack_IsEmpty(stack)) != true;) {
         printf("%d ", Pop_Stack(stack));
    }
    //判断栈是否为空
    if(true == Stack_IsEmpty(stack)){
        printf("此时栈已空\n");
    }*/

    //队列：先入先出
    Queue* queue = queue_init();
    //插入数据
    queue_push(queue,1,"宋同学");
    queue_push(queue,21,"神圣的海旅");
    queue_push(queue,45,"墨味香");
    queue_push(queue,38,"我的名字");
    queue_push(queue,40,"善水人山");

    while (!queue_isEmpty(queue)){//如果队列不为空
        queue_pop(queue);//进入循环，数据出队，尾删
    }
    return 0;
}
