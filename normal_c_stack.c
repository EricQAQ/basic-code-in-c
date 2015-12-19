//
// Created by EricZhang on 15/12/19.
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "normal_c_stack.h"

/***************泛型栈***********************************/

/*
 * 由于不确定入栈的数据的类型,是否包含动态申请内存(比如字符串),如果直接free()栈中的内存,
 * 并不能释放掉动态申请的内存,所以,我们需要新增函数来进行操作
 */
void StringFree(char *addr) {
    // 用来释放创建字符串动态申请的内存
    free(*(char **)addr);
}


void StackNew_(stack_ *s, int elementSize, void *freefunc(void *)) {
    /*
     * freefunc 是处理动态申请内存的函数,
     * 如果栈的元素的类型并不需要动态申请内存,比如int,double,float等,这个参数设置为NULL
     */
    s->elementSize = elementSize;
    s->logic_length = 0;
    s->alloc_length = 4;
    s->element = malloc(4 * s->elementSize);

    assert(s->element != NULL);
}

// 销毁栈
// 为了释放动态申请的空间,改进
void StackFree_(stack_ *s) {
    for(int i = 0; i < s->logic_length; i++) {
        // 根据每个元素(类型是地址),分别找到对应动态申请的内存,逐个释放
        s->freefunc((char *)s->element + i * s->elementSize);
    }
    free(s->element);
}

// 入栈
void StackPush_(stack_ *s, void *elementAddr) {
    if(s->logic_length == s->alloc_length) {
        s->alloc_length *= 2;
        s->element = realloc(s->element, s->alloc_length * s->elementSize);

        assert(s->element != NULL);
    }
    /*
     * 获得栈当前未写入的内存的地址
     * 由于不知道入栈的类型,已经所占内存的大小,所以不能使用上面入栈的方法.
     * 我们需要先找到栈当前第一个未写入的内存的地址,然后把内容拷贝到上面
     */
    void *target = (char *)s->element + s->logic_length * s->elementSize;   // 由于void * 不能做算术运算,所以需要转换
    memcpy(target, elementAddr, s->elementSize);
    s->logic_length++;
}

// 出栈
void StackPop_(stack_ *s, void *elementAddr) {
    /*
     * 把出栈的东西,放到elementAddr地址指向的内存中,就不用直接使用返回了
     * 这样可以避免在这个函数执行的时候动态申请内存(一般来说,申请者还需要自己去释放这块内存)
     */
    assert(s->logic_length > 0);

    void *source = (char *)s->element + (s->logic_length-1) * s->elementSize;
    memcpy(elementAddr, source, s->elementSize);
    s->logic_length--;
}