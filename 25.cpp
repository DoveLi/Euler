/*************************************************************************
	> File Name: 25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 19时31分09秒
 ************************************************************************/
#include <stdio.h>
int max(int a, int b) {
    return a>b?a:b;
}
int min(int a, int b) {
    return a>b?b:a;
}
int fib[100005][1005] = {0};
int main() {
    fib[0][0] = fib[0][1] = 1;
    fib[1][0] = fib[1][1] = 1;
    int count = 2;
    while (true) {
        fib[count % 3][0] = max(fib[(count + 1) % 3][0], fib[(count + 2) % 3][0]);
        int temp = max(fib[(count + 1)% 3][0], fib[(count + 2) % 3][0]);
        for (int i = 1; i <= temp; ++i) {
            fib[count % 3][i] = fib[(count + 1) % 3][i] + fib[(count + 2) % 3][i]; 
        }
        for (int i = 1; i <= fib[count % 3][0]; ++i) {
            if (fib[count % 3][i] < 10) continue;
            fib[count % 3][i + 1] += fib[count % 3][i] / 10;
            fib[count % 3][i] = fib[count % 3][i] % 10;
            fib[count % 3][0] += (i == fib[count % 3][0]);
        }
        if (fib[count % 3][0] >= 1000) {
            printf("%d\n", count - 1);
            break;
        }
        count++;
    }
}
