/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时09分18秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 600851475143

#include<inttypes.h>

int main(){
    
    int64_t ans ;
    int64_t sum = MAX_N;
    for(int64_t i = 2;i*i<=sum;i++){
        while(sum % i == 0){
            sum/=i;
            ans = i;
        }
    
    }
    if(sum !=0) ans = sum;
    printf("%"PRId64"\n",ans);


    return 0;
}
