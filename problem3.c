/*
    The prime factors of 13195 are 5,7,13 and 29
    What is the largest prime factor of a given number N?
*/

#include <math.h>
#include <stdio.h>

int check_prime_factor(long int num){
    for(long int i = 2; i <= sqrt(num); i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int t;
    scanf("%d",&t);
    long int num[t], ans_arr[t];
    //Input Part
    for(int a = 0; a < t; a++){
        long n; 
        scanf("%ld",&n);
        num[a]=n;
    }

    //Main logic
    for(int a = 0; a < t; a++){
        long int n = num[a];
        long int temp = n;
        if(check_prime_factor(n) == 0){
            for(long int i = 2;i <= (n/2); i++){    
                if( n % i == 0 && check_prime_factor(i)==1){  
                    while( temp % i == 0)
                        temp /= i;
        
                    if(check_prime_factor(temp) == 1)
                        if(temp == 1){
                            temp*=i;
                        }
                        break;
                }
            }
        }
        ans_arr[a] = temp;
    }   
    
    for(int i=0;i<t;i++)
        printf("%ld\n",ans_arr[i]);
    
    return 0;
}