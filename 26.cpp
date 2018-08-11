/*************************************************************************
	> File Name: 26.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 09:38:20 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int dnum[1000] = {0};

int get_length(int d) {
    int y = 1, n = 1;
    memset(dnum, 0, sizeof(dnum));
    while (y && dnum[y] == 0) {
        dnum[y] = n;
        y = y * 10 % d;
        n += 1;
    }
    return y ? n - dnum[y] : 0;
}

int main() {
    int ans, max_length = 0;
    for (int i = 1; i < 1000; i++) {
        int length = get_length(i);
        if (length > max_length) {
            max_length = length;
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
