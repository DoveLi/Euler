/*************************************************************************
	> File Name: 33.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:16:11 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int ansa = 1, ansb = 1;
    for (int i = 10; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            int a[2] = {i / 10, i % 10}, b[2] = {j / 10, j % 10};
            int flag = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (a[k] == 0 || a[k] != b[l]) continue;
                    int rest_a = a[1 - k], rest_b = b[1 - l];
                    if (rest_b * i == rest_a * j) {
                        ansa *= i;
                        ansb *= j;
                        printf("%d/%d\n", i, j);
                    }
                }
            }
        }
    }
    printf("%d\n", ansb / gcd(ansa, ansb));
    return 0;
}
