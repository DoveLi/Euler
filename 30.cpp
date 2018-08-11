/*************************************************************************
	> File Name: 30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时24分34秒
 ************************************************************************/



#include<stdio.h>

#include<math.h>

#include<inttypes.h>

#define MAX_N 295245
int64_t is_number(int64_t n ){

    int64_t a = n;
    int64_t ans = 0;
    int sum = 0;
    while(a){
        sum = a%10;
        ans +=(int64_t) pow(sum,5);
        a/=10;
    }
       return n == ans;
}

int main(){

    int64_t answer = 0;
    for(int64_t i = 2;i<=MAX_N;i++){
        if(!is_number(i)) continue;
       else  answer+=i;
    }
    printf("%"PRId64"\n",answer);

    return 0;
}
