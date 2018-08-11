/*************************************************************************
	> File Name: 39.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 09:48:21 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 1000

int ans[MAX_N] = {0};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    for (int n = 2; n * n <= 1000; n++) {
        for (int m = 1; m < n; m++) {
            if (gcd(n, m) != 1) continue;
            int a = n * n - m * m;
            int b = 2 * n * m;
            int c = n * n + m * m;
            if (gcd(a, gcd(b, c)) != 1) continue;
            printf("gcd(%d, %d, %d) = %d\n", a, b, c, gcd(a, gcd(b, c)));
            for (int k = 1; k * (a + b + c) <= 1000; k++) {
                ans[k * (a + b + c)] += 1;
            }
        }
    }
    int p, max_num = 0;
    for (int i = 1; i <= 1000; i++) {
        if (ans[i] > max_num) {
            max_num = ans[i];
            p = i;
        }
    }
    printf("%d\n", p); 
    return 0;
}
