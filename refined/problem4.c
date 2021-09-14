/*
    !Largest Palindrome product

    A palindromic number reads the same both ways. The largest palindrome made from the product of 
    two 2-digit numbers is 9009 = 91 × 99.
    Find the largest palindrome made from the product of two 3-digit numbers.
*/

//Loopy way

#include<stdio.h>

int isPalin(int n){
    int fut = n, rem = 0;
    
    while(n != 0){
        rem = rem * 10 + n % 10;
        n = n / 10;
    }

    if (fut==rem){
        return 1;
    }

    return 0;
}

int main(){
    int t;
    scanf("%d",&t);

    int arr[t];
    for(int i = 0; i < t; i++){
        scanf("%d",(arr+i));
    }

    int lim, ans_arr[t];
    for(int a = 0; a < t; a++){
        lim=arr[a];
        int num, largest=-1;
        for(int i=100;i<=999;i++){
            for(int j=i;j<=999;j++){
                num=i*j;
                if(isPalin(num)==1 && num<lim){
                    if(largest < num)
                        largest=num;
                }
            }
        }

        ans_arr[a]=largest;
    }

    for(int i=0;i < t; i++)
        printf("%d\n",ans_arr[i]);
}

