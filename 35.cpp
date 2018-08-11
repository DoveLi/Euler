/*************************************************************************
	> File Name: 35.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:23:18 2018
 ************************************************************************/

#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 10000000

int prime[MAX_N + 5] = {0};

void init() {
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = 2 * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}

int digit(int x) {
    return floor(log10(x)) + 1;
}

int is_valid(int num) {
    if (prime[num]) return 0;
    int n = digit(num) - 1;
    int mod_num = pow(10, n);
    for (int i = 0; i < n; i++) {
        num = (num % mod_num) * 10 + num / mod_num;
        if (prime[num]) return 0;
    }
    return 1;
}

int main() {
    init();
    int ans = 0;
    for (int i = 2; i <= 1000000; i++) {
        ans += is_valid(i);
    }
    printf("%d\n", ans);
    return 0;
}
