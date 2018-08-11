/*************************************************************************
	> File Name: 38.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:36:40 2018
 ************************************************************************/

#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

int digit(int num) {
    return floor(log10(num)) + 1;
}

int is_valid(int x, int *num) {
    while (x) {
        if (x % 10 == 0) return 0;
        if (num[x % 10]) return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int main() {
    int ans = 0;
    for (int i = 1; i < 10000; i++) {
        int n = digit(i);
        int num[10] = {0};
        int temp_ans = i;
        if (!is_valid(i, num)) continue;
        for (int a = 2 * i; n < 9; a += i, n += digit(a)) {
            if (!is_valid(a, num)) break;
            printf("befor : temp_ans = %d a = %d\n", temp_ans, a);
            temp_ans = temp_ans * (int)pow(10, digit(a)) + a;
            printf("after : temp_ans = %d a = %d\n", temp_ans, a);
        }
        if (n == 9) {
            ans = (temp_ans > ans ? temp_ans : ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}
