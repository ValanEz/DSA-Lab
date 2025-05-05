#include <iostream>
using namespace std;
const int tsize= 10;
const int emp=-1;
const int del=-2;
class HashTable{
    private:
    int table[tsize];
    public:
    HashTable(){
        for (int i=0;i<tsize; i++){
            table[i]=emp;
        }
    }
    int hash(int key){
        return key%tsize;
    }
    void insert(int key){
        int ind=hash(key);
        int startind=ind;
        int i=0;
        while (table[ind]!=emp && table[ind]!=del){
            if (table[ind]==key){
                cout << "key exists already \n";
                return;
            }
            ind=(startind+ (++i)) % tsize;
            if (ind==startind){
                cout << "table full \n";
                return;
            }
        }
        table[ind]=key;
        cout << "Inserted at " << ind << "\n";
        return;

    }
    void remove(int key){
        int ind=hash(key);
        int startind=ind;
        int i=0;
        while (table[ind]!=emp && table[ind]!=del){
            if (table[ind]==key){
                cout << "Given key deleted at " << ind << " index \n";
                table[ind]=del;
                return;
            }
            ind=(startind+ (++i))%tsize;
            if (ind==startind){
                cout <<" Value not found \n";
                return;
            }
        }
    }
    void search(int key){
        int ind=hash(key);
        int startind=ind;
        int i=0;
        while (table[ind]!=emp && table[ind]!=del){
            if (table[ind]==key){
                cout << "given key found at index " << ind << "\n";
                return;
            }
            ind = (startind + (++i))%tsize;
            if (ind==startind){
                cout <<"Value not found \n";
                return;
            }
        }
    }
    void display(){
        for (int i =0; i<tsize;i++){
            cout << i<< ":";
            cout << table[i] << "\n";
        }
    }
};
int main(){
    int ch=0;
    HashTable ht;
    while (ch!=5){
        cout << "Enter 1 to insert, 2 to remove, 3 to search, 4 to display, 5 to exit:";
        cin >>ch;
        if (ch==1){
            int key;
            cout << "enter key to be inserted:";
            cin >> key;
            ht.insert(key);
        }
        if (ch==2){
            int key;
            cout << "Enter key to be removed:";
            cin >> key;
            ht.remove(key);
        }
        if (ch==3){
            int key;
            cout << "Enter key to be searched:";
            cin >> key;
            ht.search(key);
        }
        if (ch==4){
            ht.display();
        }
        if (ch==5){
            break;
        }

    }
}