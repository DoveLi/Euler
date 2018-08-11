/*************************************************************************
	> File Name: 44.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 三  8/ 1 10:58:32 2018
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using std::cin;
using std::cout;
using std::endl;

int64_t P(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int binary_search(int64_t (*func)(int64_t), int64_t n, int64_t x) {
    int head = 0, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        if (func(mid) < x) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }
    return 0;
}

int main() {
    int64_t j = 2, D = INT64_MAX;
    while (P(j) - P(j - 1) < D) {
        int64_t k = j - 1;
        while (k > 0 && P(j) - P(k) < D) {
            int64_t numa = P(j) + P(k);
            int64_t numb = P(j) - P(k);
            if (binary_search(P, 10 * j, numa) && binary_search(P, j, numb)) {
                D = numb;
                printf("find %" PRId64 " %" PRId64 "\n", j, k);
                break;
            }
            k--;
        }
        j++;
    }
    printf("%" PRId64 "\n", D);
    return 0;
}
