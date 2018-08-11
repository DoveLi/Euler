/*************************************************************************
	> File Name: 15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 17时01分52秒
 ************************************************************************/



#include<stdio.h>

#include<inttypes.h>

int main(){

    int64_t ans = 1;
    int64_t sum = 20;
    for(int64_t i = 40;i>20;i--){
        ans *=i;
        while(ans%sum==0&&sum!=1){
            ans = ans/sum;
            sum--;
        }

             
        }
    printf("%"PRId64"\n",ans);
    }

