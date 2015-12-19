//
// Created by EricZhang on 15/12/19.
//

#ifndef BASIC_CODE_IN_C_NORMAL_C_STACK_H
#define BASIC_CODE_IN_C_NORMAL_C_STACK_H

/***************泛型栈***********************************/
typedef struct stack_ {
    void *element;
    int elementSize;    // 需要知道element类型的大小
    int logic_length;
    int alloc_length;
    void (*freefunc)(void *); // 解决释放动态申请空间的问题, 指向一个函数
}stack_;

// 创建栈
void StackNew_(stack_ *s, int elementSize, void (*freefunc)(void *));

// 销毁栈
void StackFree_(stack_ *s);

// 入栈
void StackPush_(stack_ *s, void *elementAddr);

// 出栈
void StackPop_(stack_ *s, void *elementAddr);

#endif //BASIC_CODE_IN_C_NORMAL_C_STACK_H
