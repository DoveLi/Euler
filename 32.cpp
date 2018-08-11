/*************************************************************************
	> File Name: 32.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:08:34 2018
 ************************************************************************/

#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

int dnum[100000] = {0};

int digit(int x) {
    return floor(log10(x)) + 1;
}

int is_valid(int num, int *can) {
    while (num) {
        if (num % 10 == 0) return 0;
        if (can[num % 10]) return 0;
        can[num % 10] = 1;
        num /= 10;
    }
    return 1;
}

int main() {
    int ans = 0;
    for (int a = 2; 2 * digit(a) + digit(a * a) <= 9; a++) {
        for (int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
            if (digit(a) + digit(b) + digit(a * b) < 9) continue;
            int num[10] = {0};
            if (!is_valid(a, num)) continue;
            if (!is_valid(b, num)) continue;
            if (!is_valid(a * b, num)) continue;
            ans += (1 - dnum[a * b]) * (a * b);
            dnum[a * b] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
