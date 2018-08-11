/*************************************************************************
	> File Name: a36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时59分15秒
 ************************************************************************/



#include<stdio.h>

#include<inttypes.h>

#define MAX_N 1000000

int64_t is_number(int64_t a,int64_t b){

    int64_t x = a;
    int64_t sum = 0;
    while(x){
        sum = sum * b+ x % b;
        x/=b;
 }

   return sum == a;

}

int main(){

    int64_t ans = 0;
    for(int64_t i = 1;i<=MAX_N;i++ ){

        if(is_number(i,10)&&is_number(i,2)) ans+=i;

    }
    printf("%"PRId64"\n",ans);

    return 0;
}
