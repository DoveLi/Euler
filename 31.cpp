/*************************************************************************
	> File Name: 31.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:06:07 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int dp[300] = {0};
int w[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
    dp[0] = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = w[i]; j <= 200; j++) {
            dp[j] += dp[j - w[i]];
        }
    }
    printf("%d\n", dp[200]);
    return 0;
}
