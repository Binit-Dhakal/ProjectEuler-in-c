#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);

    int inp[t],ans[t];
    for(int i = 0; i < t; i++){
        scanf("%d",&inp[i]);
    }

    for(int a = 0; a < t; a++){
        int upper_lim = inp[a];
        int i = upper_lim;

        while(1){
            int isAns=0;
            for(int j = 1; j <= upper_lim; j++){
                if(i % j != 0){
                    isAns=0;
                    break;
                }
                isAns=1;
            }

            if(isAns==1)
                break;
            
            i += upper_lim;
        }
        ans[a]=i;
    }
    
    for(int i = 0; i < t; i++)
        printf("%d\n",ans[i]);
    
    return 0;
}