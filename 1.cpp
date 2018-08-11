/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 12时42分06秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int sum3 = 0;
    int sum5 = 0;
    int sum15 = 0;
    for(int i = 1;i<1000;i++){
    if(i%3==0) sum3+=i;
        if(i%5==0) sum5+=i;
        if(i%15==0) sum15+=i;
    }
    printf("%d\n",sum3+sum5-sum15);
}
