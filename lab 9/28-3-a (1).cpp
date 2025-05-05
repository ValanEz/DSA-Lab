#include <stdio.h>
using namespace std;
int main(){
    int tc;
    printf("Enter test cases: ");
    scanf("%d", &tc);

    for (int i=0; i<tc;i++){
        int k,q;
        printf("Enter k and q: ");
        scanf("%d %d", &k,&q);

        int ka[k], qa[q];

        printf("Enter sequence k: ");
        for (int j=0;j<k;j++){
            scanf("%d", &ka[j]);
        }

        printf("Enter sequence q: "); 
        for (int j=0;j<q;j++){
            scanf("%d", &qa[j]);
        }

        for (int j=0;j<q;j++){
            int w=qa[j];
            if (w==1){
                printf("1 ");
            }
            else if(w>ka[0]){
                printf("%d ", ka[0]-1);
            }
            else if (w<ka[0]){
                printf("%d ", w);
            }
        }
        
        printf("\n");
    }
}