/*
    !10001st Prime

    By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

    What is the 10 001st prime number?
*/

//Loopy way

#include <stdio.h>
#include <math.h>

int isPrime(int num){
    int isPrime = 1;
    int k = 3;
    while(k <= sqrt(num)){
        if(num % k == 0){
            return 0;
        }
        k+=2;
    }
    return 1;
}

int main(){
    int t; 
    scanf("%d",&t);
    int inp[t], ans[t];
    
    for(int a0 = 0; a0 < t; a0++)
        scanf("%d",(inp+a0)); 
    
    //To find the biggest value in the array to plan the size of the prime_array
    int biggest_num=inp[0];
    for(int i = 1; i < t; i++){
        if(biggest_num < inp[i])
            biggest_num=inp[i];
    }

    int count = 1, num = 3;    
    int prime_array[biggest_num+1];

    prime_array[count]=2;

    while(1){
        if(isPrime(num)==1){
            count++;
            prime_array[count]=num;

            if(count == biggest_num+1)
                break;
        }
        num+=2;
    }
    
    for(int a = 0; a < t; a++){
        int n=inp[a];
        ans[a]=prime_array[n];
    }

    for(int i = 0; i < t; i++)
        printf("%d\n",ans[i]);
}