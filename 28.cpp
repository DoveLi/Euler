/*************************************************************************
	> File Name: 28.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时07分13秒
 ************************************************************************/



#include<stdio.h>



int main(){

    int sum = 0;
    for(int i = 3;i <=1001;i+=2){

        sum +=4*i*i-6*i+6;
    }

    printf("%d\n",sum+1);

    return 0;
}
