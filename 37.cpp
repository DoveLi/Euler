/*************************************************************************
	> File Name: 37.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:30:28 2018
 ************************************************************************/

#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 10000000

int prime[MAX_N + 5] = {0};

int is_valid(int num) {
    int n = floor(log10(num));
    int temp = num;
    while (temp) {
        if (prime[temp]) return 0;
        temp /= 10;
    }
    do {
        num %= (int)pow(10, n);
        if (prime[num]) return 0;
    } while (--n);
    return 1;
}

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

int main() {
    init();
    int n = 0, ans = 0, i = 11;
    while (n < 11) {
        if (is_valid(i)) {
            n += 1;
            ans += i;
        }
        i += 1;
    }
    printf("%d\n", ans);
    return 0;
}
