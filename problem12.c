#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int triangle;
    int factor;
    struct node * next;
} node_t;

void append_list(node_t * ptr, int tri, int fact){
    node_t * temp = ptr;
    node_t * new_node = (node_t *) malloc(sizeof(node_t));

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    //filling data of new_node
    new_node -> triangle = tri;
    new_node -> factor = fact;
    new_node -> next = NULL;

    temp -> next = new_node;
}

int isPrime(int n){
    for(int i = 2; i <= sqrt(n) ; i++){
        if(n % i == 0) return 0;
    }

    return 1;
}

int checkUniqueFact( int unique_fact[], int n){
    int i = 0;
    int max = 1;
    while(unique_fact[i] != 0){
        
        if(unique_fact[i] == n ) return 0;
        max = (unique_fact[i] > max) ? unique_fact[i] : max;
        i++;
    }
    if(n < max) return 0;

    return 1;

}

void printList(node_t* head){
    
    node_t * temp = head;
    while( temp != NULL){
        printf("%d\t %d\n",temp->triangle, temp->factor);
        temp = temp -> next;
    }
}
 
void free_all(node_t * head){
    node_t * temp = NULL;

    while( head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }
}

int  find_factor(node_t * head, int n){
    node_t * temp = head;
    while( temp != NULL){
        if( (temp -> factor) > n){
            return temp -> triangle;
        }
        temp = temp -> next;
    }
    return 0;
}

int main(){
    int t;
    scanf("%d",&t);

    int inp[t], ans[t], max_fact = 1;
    for(int a = 0; a < t; a++ ){
        scanf("%d",(inp + a));
        max_fact = (inp[a] > max_fact) ? inp[a] : max_fact;       
    }

    //linked list
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    head -> triangle = 1;
    head -> factor = 1;
    head -> next = NULL;

    int * unique_fact = (int *) malloc(max_fact * sizeof(int));
    memset(unique_fact, 0, max_fact* sizeof(int));
    unique_fact[0] = 1;

    int tri, add = 2;
    int temp, uniq = 1;
    
    while( 1 ){
        tri = add*(add+1)/2;    // using sum formula n*(n+1)/2
        temp = tri;
        int count;
        int factor = 1;


        //https://www.wikiwand.com/en/Divisor_function#/Properties
        for(int i = 2; i <= temp; i++){
            if(temp % i == 0 && isPrime(i) == 1){ 
                count = 0;
                while(temp % i == 0 && temp != 1){
                    count++;
                    temp /= i;
                }
                factor *= (count+1);
            }
        }
        

        if (checkUniqueFact(unique_fact, factor) == 1){
            unique_fact[uniq] = factor;
            append_list(head, tri, factor);
            uniq++;
        }
        
        if( factor > max_fact)  break;
        
        add++;
    }

    free(unique_fact);
    // printList(head);
    
    int num ;
    for(int a = 0 ; a < t; a++ ){
        num = inp[a];
        ans[a] = find_factor(head, num);
    }

    for(int a = 0; a < t; a++){
        printf("%d\n", ans[a]);
    }

    free_all(head);
    return 0;
}