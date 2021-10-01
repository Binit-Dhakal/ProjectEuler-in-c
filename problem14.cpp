//This was too hard for me. This used the concept of recursion(which i always used to skip), memoization
//Thanks to Tashaion for his answer. 
//https://www.hackerrank.com/contests/projecteuler/challenges/euler014/forum/comments/423706

#include <iostream>
#include <cstring>


#define N 5000001
typedef unsigned long long int ulli;

ulli *memorize = new ulli[N];

ulli chain_number(int num){
    
    if(num < N && memorize[num] != 0)
        return memorize[num];
    
    ulli temp = 0;
    //for even
    if(num % 2 == 0){
        temp = num / 2;
        memorize[num] = 1 + chain_number(temp);
        return memorize[num];
    }
    
    //for odd
    temp = 3 * num + 1;
    ulli count = 1;

    //we have done this to avoid the use of space not allocated by memorize array 
    while(temp >= N){
        // std::cout << temp << std::endl;
        if(temp % 2 == 0)
            temp /= 2;  
        else
            temp = temp * 3 + 1;
        count++;
    }

    memorize[num] = count + chain_number(temp);
    return memorize[num];
}

int main(){
    int t;
    std::cin >> t;

    int inp[t], ans[t];
    for(int i = 0; i < t; i++)
        std::cin >> inp[i];

    memset(memorize, 0, sizeof(memorize));
    memorize[1] = 1; // for 1 collatz chain is 1
    
   // Every multiple of 2 i.e 2*2 =4 and 4*2 = 8 so on will have one increasing chain number than its preceding
   // multiple of 2 number
    for(ulli i = 2, count = 1; i < N; i *= 2)
        memorize[i] = ++count;
        

    for(int i = 3; i < N; i++)
        chain_number(i);
    
    ulli *results = new ulli [N];
    results[1] = 1;

    for(int a = 2; a < N ; a++){
        if(memorize[a] >= memorize[results[a-1]])
            results[a] = a;
        else   
            results[a] = results[a-1];
    }

    for(int a = 0; a < t; a++ )
        ans[a] = results[inp[a]];

    delete[] results;
    delete[] memorize;

    for(int a = 0; a < t; a++)
        std::cout << ans[a] << std::endl;
}