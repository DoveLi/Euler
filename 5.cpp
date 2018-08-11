/*************************************************************************
	> File Name: 5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 16时15分32秒
 ************************************************************************/



#include<stdio.h>

#include<math.h>

int gcd(int a,int b){

    if(!b) return a;
    return gcd(b,a%b);



}

int main(){

    int ans = 1;
    for(int i = 1;i<=20;i++ ){
        if(ans%i==0) continue;
        else ans = ans*i/gcd(ans,i);
    }
    printf("%d\n",ans);

    return 0;
}
