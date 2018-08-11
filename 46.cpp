/*************************************************************************
	> File Name: 46.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 09:58:14 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        return 0;
    }
    return 1;
}

int is_valid(int num) {
    for (int i = 1; i * i * 2 <= num; i++) {
        if (is_prime(num - i * i * 2)) return 1;
    }
    return 0;
}

int main() {
    for (int i = 3; i; i += 2) {
        if (is_prime(i) || is_valid(i)) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}
