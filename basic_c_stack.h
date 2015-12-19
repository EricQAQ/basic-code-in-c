//
// Created by EricZhang on 15/12/19.
//

#ifndef BASIC_CODE_IN_C_BASIC_C_STACK_H
#define BASIC_CODE_IN_C_BASIC_C_STACK_H

/**************非泛型栈****************************************/
/*
 * 装int型的栈
 */
typedef struct stack {
    int *element;
    int logic_length;   // 栈的逻辑大小
    int alloc_length;   // 实际申请内存的大小
}stack;

// 创建栈
void StackNew(stack *s);

// 销毁栈
void StackFree(stack *s);

// 入栈
void StackPush(stack *s, int value);

// 出栈
int StackPop(stack *s);
/*************************************************************/

#endif //BASIC_CODE_IN_C_BASIC_C_STACK_H
