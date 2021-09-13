/*
    If we list all the natural numbers below 10 that are multiples of 3 or 5, 
    we get 3, 5, 6 and 9. The sum of these multiples is 23.

    Find the sum of all the multiples of 3 or 5 below 1000.
*/
/*
!My first try:
    #include<stdio.h>

    #define N 10

    int main(){
        int sum=0;
        for (int i=3;i<N;i++){
            if((i % 3 == 0) && (i % 5 == 0))
                sum+=i;

            else if(i%3==0)
                sum+=i;

            else if(i%5==0)
                sum+=i;
        }

        printf("The sum is %d\n",sum);
    }
*/

// Little bit googling
/*
!Second technique
#include<stdio.h>
#define N 1000
int main(){
    int sum=0;
    for(int i=0;i<N;i++){
        if( i % 3 == 0 || i % 5 == 0)
            sum+=i;
    }

}
*/

// ! Math Way without loop
//https://codereview.stackexchange.com/questions/102673/project-euler-1-multiples-of-3-and-5
#include<stdio.h>

int main(){
    /*
        using formula n(n+1)/2 to find the sum of numbers upto n.
    */
   int N=1000-1;
   int div3,div5,divbo;

    div3=3*((N/3)*(N/3+1)/2);
    div5=5*((N/5)*(N/5+1)/2);

    //To cancel out the sum produced by both numbers like to 15 and 30 and so on
    //The numbers that divide both 3 and 5 are precisely the number that divides 3*5/gcd(3,5)=15
    divbo=15*((N/15)*(N/15+1)/2);

    int sum=div3+div5-divbo;
    printf("The sum is %d",sum);
}