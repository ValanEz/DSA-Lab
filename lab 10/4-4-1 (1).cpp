#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int n;
        cin >>n;
        vector <int> a(n);
        vector <bool> visited(n,false);
        int count=0;
        int i;
        for (i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for (i=n-1;i>=0;i--){
            if (visited[a[i]]){
                break;
            }
            visited[a[i]]=true;
            count++;
        }

        cout << (n-count) << endl;
    }
    return 0;
}