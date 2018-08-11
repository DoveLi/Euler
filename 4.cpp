/*************************************************************************
	> File Name: 4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时29分40秒
 ************************************************************************/



#include<stdio.h>

int is_palindromi(int n){
    int num = 0;
    int x = n;
    while(x){
        num = num * 10 +x % 10;
        x = x/10;
    
}
    return n == num;
}


int main(){
    
    int ans = 0;
    for(int i = 100;i<1000;i++){
        for(int j = i;j<1000;j++){
          if(i*j<=ans) continue; 
            if(!is_palindromi(i*j)) continue;
            ans = i * j;
            
    }


}
    printf("%d\n",ans);
    return 0;
}
