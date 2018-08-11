
#include <stdio.h>
#include<inttypes.h>
#define MAX_N 2000000

int64_t prime[MAX_N + 5] = {0};

int main() {
    int64_t sum = 0;
    for (int64_t i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            sum +=i;
        }
        for (int64_t j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%"PRId64"\n",sum);
    return 0;
}
