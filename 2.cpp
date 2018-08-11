/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时01分03秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N 4000000
int main(){

    int64_t sum = 0;
    int64_t a = 0;
    int64_t b = 1;
    int64_t temp = 0;
    while(temp<=MAX_N){
        temp = a + b;
        a = b;
        b = temp;
        if(temp%2==0){
            sum +=temp; 
        }
    }


    printf("%"PRId64"\n",sum);
    return 0;
}
