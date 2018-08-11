/*************************************************************************
	> File Name: 24.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 09:27:51 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int dnum[10] = {0};
int mnum[10] = {0};

void init() {
    mnum[0] = 1;
    for (int i = 1; i < 10; i++) mnum[i] = mnum[i - 1] * i;
    return ;
}

int get_num(int n, int k) {
    int ind = k / mnum[n] + 1;
    int i = 0, j = -1;
    do {
        j++;
        i += (1 - dnum[j]);
    } while (i < ind);
    dnum[j] = 1;
    return j;
}

int main() {
    init();
    int k = 1000000 - 1;
    for (int i = 0; i < 10; i++) {
        int temp = get_num(10 - i - 1, k);
        printf("%d", temp);
        mnum[10 - i - 1] && (k %= mnum[10 - i - 1]);
    }
    return 0;
}

