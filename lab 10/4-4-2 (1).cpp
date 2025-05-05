#include <iostream>
#include <vector>
using namespace std;
#include <string>
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >>n;
        vector <string> word1(n);
        vector <string> word2(n);
        vector <string> word3(n);
        int i;
        for (i=0;i<n;i++){
            cin >> word1[i];
        }
        for (i=0;i<n;i++){
            cin >> word2[i];
        }
        for (i=0;i<n;i++){
            cin >> word3[i];
        }
        int p1point=0;
        int p2point=0;
        int p3point=0;
        for (i=0;i<n;i++){
            string word= word1[i];
            bool written2=false;
            bool writted3=false;
            for (int j=0;j<n;j++){
                if (word2[j]==word){
                    written2=true;
                    break;
                }
            }
            for (int j=0;j<n;j++){
                if (word3[j]==word){
                    writted3=true;
                    break;
                }
            }
            if (written2 && writted3){
                continue;
            }
            else if(written2 || writted3){
                if (written2){
                    p1point+=1;
                    p2point+=1;
                }
                else if (writted3){
                    p1point+=1;
                    p3point+=1;
                }
            }
            else{
                p1point+=3;
            }
        }
        for (i=0;i<n;i++){
            string word= word2[i];
            bool written1=false;
            bool writted3=false;
            for (int j=0;j<n;j++){
                if (word1[j]==word){
                    written1=true;
                    break;
                }
            }
            for (int j=0;j<n;j++){
                if (word3[j]==word){
                    writted3=true;
                    break;
                }
            }
            if (written1){
                continue;
            }
            else if (writted3){
                p2point+=1;
                p3point+=1;
            }
            else{
                p2point+=3;
            }
        }
        for(i=0;i<n;i++){
            string word= word3[i];
            bool written1=false;
            bool writted2=false;
            for (int j=0;j<n;j++){
                if (word1[j]==word){
                    written1=true;
                    break;
                }
            }
            for (int j=0;j<n;j++){
                if (word2[j]==word){
                    writted2=true;
                    break;
                }
            }
            if (!written1 && !writted2){
                p3point+=3;
            }
        }
        cout << p1point<<" " << p2point << " " << p3point << endl;
    }
}