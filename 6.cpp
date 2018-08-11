/*************************************************************************
	> File Name: 6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时03分34秒
 ************************************************************************/




#include<stdio.h>
int main(){

    int sum1=0;
    int sum2=0;
    for(int i = 1;i<=100;i++ ){

      sum1 +=i; 
    }
    for(int j = 1;j<=100;j++){
        sum2 +=j*j;
    }

    printf("%d\n",sum1*sum1-sum2);
    return 0;
}
