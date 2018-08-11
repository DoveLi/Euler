/*************************************************************************
	> File Name: 43.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:50:29 2018
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cinttypes>
using std::cin;
using std::cout;
using std::endl;

int64_t num(int *num, int a, int b) {
    int64_t ret = 0;
    for (int i = a; i <= b; i++) {
        ret = ret * 10 + num[i];
    }
    return ret;
}

int main() {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int prime[8] = {0, 2, 3, 5, 7, 11, 13, 17};
    int64_t ans = 0;
    do {
        int flag = 1;
        for (int i = 1; i < 8 && flag; i++) {
            if (num(a, i, i + 2) % prime[i]) flag = 0;
        }
        if (flag) {
            ans += num(a, 0, 9);
        }
    } while (std::next_permutation(a, a + 10));
    printf("%" PRId64 "\n", ans);
    return 0;
}
