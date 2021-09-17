/*
    !Pythagorean Triplet


    A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a2 + b2 = c2

    For example, 32 + 42 = 9 + 16 = 25 = 52.

    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int t;
    scanf("%d",&t);

    int inp[t], ans[t];

    for(int i = 0; i < t; i++){
        ans[i] = -1;
        scanf("%d", (inp + i));
    }

    for(int a0 = 0; a0 < t; a0++){
        int N = inp[a0],a,b,c;
        for(int a = 3; a < N/3; a++ ){
            b = ( pow(N , 2) - 2 * a * N ) / (2 * (N - a));
            c = (N - a - b);

            if( pow(a,2) + pow(b,2) == pow(c,2)){
                if ((a * b * c) > ans[a0]){
                    ans[a0] = (a * b * c);
                }
            }
        }
    
    }

    for(int i = 0; i < t; i++){
        printf("%d\n", ans[i]);
    }
}

/*
    Help resource
        https://www.dropbox.com/s/kep0cbtbkdd011a/formula.png#
*/