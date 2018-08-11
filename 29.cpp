/*************************************************************************
	> File Name: 29.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 09:41:47 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 10000

int *result[MAX_N] = {0};
int cnt = 0;

int find(int *num) {
    for (int i = 0; i < cnt; i++) {
        if (memcmp(result[i], num, sizeof(int) * (num[0] + 1))) continue;
        return 1; 
    }
    return 0;
}

int *get(int a, int b) {
    int *temp = (int *)calloc(sizeof(int), 300);
    temp[0] = temp[1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1; j <= temp[0]; j++) temp[j] *= a;
        for (int j = 1; j <= temp[0]; j++) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (temp[0] == j);
        }
    }
    return temp;
}

int main() {
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            int *temp = get(i, j);
            if (find(temp)) continue;
            result[cnt++] = temp;
        }
    }
    printf("%d\n", cnt); 
    return 0;
}
