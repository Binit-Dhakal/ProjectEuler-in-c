/*
    !Sum Square Difference
    The sum of the squares of the first ten natural numbers is,
            1^2+2^2+3^2+......
    The square of the sum of the first ten natural numbers is,
            (1+2+3+4+.....)^2
    Hence the difference between the sum of the squares of the first ten natural numbers 
    and the square of the sum is.

    Find the difference between the sum of the squares of the first one hundred natural 
    numbers and the square of the sum.
*/

#include <stdio.h>
#include <math.h>

int main(){
    long int t; 
    scanf("%ld",&t);
    long int inp[t],ans[t];
    
    for(long int a0 = 0; a0 < t; a0++){
        long int n; 
        scanf("%ld",&n);
        inp[a0]=n;
    }

    long int n, square_sum, sum_square;

    for(long int a = 0; a < t; a++){
        n=inp[a];
        square_sum = n*(n+1)*(2*n+1)/6;     //1^2+2^2+3^2+.....
        sum_square = pow(n*(n+1)/2,2);      //(1+2+3+4+5+.....)^2

        ans[a] = (sum_square>square_sum)?(sum_square-square_sum):(square_sum-sum_square);
    }

    for(long int i = 0; i < t; i++)
        printf("%ld\n",ans[i]);

    return 0;
}
