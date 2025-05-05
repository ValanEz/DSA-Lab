#include <stdio.h>
using namespace std;
int main(){
    int tc;
    printf("enter number of test cases:");
    scanf("%d", &tc);

    for (int i=0; i<tc;i++){
        int n;
        printf("Enter size of sequence: ");
        scanf("%d", &n);

        int a[n];
        printf("Enter sequence: ");
        for (int j=0;j<n;j++){
            scanf("%d", &a[j]);
        }

        int largest= a[0];
        int slargest=-868658;
        int c=0;
        int q;
        for (int j=0;j<n;j++){
            if (a[j]>largest){
                largest=a[j];
                q=j;
            }
        }

        for (int j=0;j<n;j++){
            if (j==q){
                continue;
            }
            else{
                if (a[j]>slargest && a[j]<largest){
                    slargest=a[j];
                    c=1;
                }
                if (a[j]==slargest){
                    c=1;
                }
            }
        }
        if (c==0){
            slargest=largest;
        }
        for (int j=0;j<n;j++){
            if (a[j]!=largest){
                printf("%d ", a[j]-largest);
            }
            else{
                printf("%d ", a[j]-slargest);
            }
        }

        printf("\n");
        printf("%d", slargest);
    }
}