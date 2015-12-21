//
// Created by EricZhang on 15/12/15.
//
#include <stdio.h>
#include "quick_sort.h"

int sort(int s[], int start, int end) {
    int i = start, j = end;
    int pivot = s[i];

    while (i < j) {
        // 从右向左扫描
        while (i < j && s[j] > pivot) {
            j--;
        }
        if (i < j) {
            s[i] = s[j];
            i++;
        }

        // 从左向右扫描
        while (i < j && s[i] <= pivot) {
            i++;
        }
        if (i < j) {
            s[j] = s[i];
            j--;
        }
    }
    s[i] = pivot;
    return i;
}

void quick_sort(int s[], int start, int end) {
    if (start < end) {
        int point = sort(s, start, end);
        quick_sort(s, start, point - 1);
        quick_sort(s, point + 1, end);
    }
}
