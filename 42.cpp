/*************************************************************************
	> File Name: 42.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 09:53:00 2018
 ************************************************************************/

#include <iostream>
#include "42.h"
using std::cin;
using std::cout;
using std::endl;

int func(int n) {
    return n * (n + 1) / 2;
}

int binary_search(int (*func)(int), int n, int x) {
    int head = 0, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        if (func(mid) < x) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }
    return 0;
}

int calc_val(const char *str) {
    int ret = 0;
    for (int i = 0; str[i]; i++) {
        ret += str[i] - 'A' + 1;
    }
    return ret;
}

int main() {
    int n = sizeof(str) / 50;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int val = calc_val(str[i]);
        ans += binary_search(func, 100, val);
    }
    printf("%d\n", ans);
    return 0;
}
