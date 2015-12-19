//
// Created by EricZhang on 15/12/19.
//

#include <stdlib.h>
#include <assert.h>
#include "basic_c_stack.h"

/**************非泛型栈****************************************/

void StackNew(stack *s) {
    s->logic_length = 0;
    s->alloc_length = 4;
    s->element = malloc(4 * sizeof(int));

    assert(s->element != NULL);     // 判断内存是否分配成功
}

void StackFree(stack *s) {
    free(s->element);
}

void StackPush(stack *s, int value) {
    // 判断分配的内存是否够用(栈是否已满)
    if(s->logic_length == s->alloc_length) {
        s->alloc_length *= 2;
        s->element = realloc(s->element, s->alloc_length* sizeof(int));     // 扩充栈的内存

        assert(s->element != NULL);     // 判断是否扩充成功
    }

    s->element[s->logic_length] = value;
    s->logic_length++;
}

int StackPop(stack *s) {
    assert(s->logic_length > 0);    // 判断栈是否为空

    s->logic_length--;      // 注意别直接减, 要不然没法返回被推出栈的值
    return s->element[s->logic_length];
}
