/*************************************************************************
	> File Name: 7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 16时25分58秒
 ************************************************************************/



#include<stdio.h>

int is_number(int n){
    for(int i = 2;i*i<=n;i++){
        if(n % i==0) return 0;
    }
    return 1;
}
    
    

int main(){

    int a = 0,num = 1;
    do{
        num += 1;
        while(!is_number(num)) num++;
        a +=1;
    }while(a<10001);
    printf("%d\n",num);

    return 0;
} 
 
