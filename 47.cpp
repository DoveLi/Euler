/*************************************************************************
	> File Name: 47.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:02:12 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 5000000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = 2 * i; j <= MAX_N; j += i) {
            prime[j] += 1;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 2; i <= MAX_N;) {
        int j, flag = 1;
        for (j = 0; j < 4 && flag; j++) {
            if (prime[i + j] != 4) flag = 0;
        }
        if (flag) {
            printf("%d", i);
            break;
        }
        i += j;
    }
    return 0;
}
