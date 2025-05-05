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
    void insert (int key){
        int ind = hash(key);
        int i=0;
        while (i<tsize){
            int probe = (ind+ i*i)%tsize;
            if (table[probe]==emp || table[probe]==del){
                table[probe]=key;
                cout << "inserted at " << probe << "\n";
                return;
            }
            else if (table[probe]==key){
                cout << "Key already exists \n";
                return;
            }
            i++;
        }
        cout << "Table full \n";
    }
    void remove(int key){
        int ind = hash(key);
        int i=0;
        while (i<tsize){
            int probe= (ind + i*i)%tsize;
            if (table[probe]==key){
                cout << key << " deleted from index " << probe << "\n";
                table[probe]=del;
                return;
            }
            i++;
        }
        cout << "Value not found \n";
    }
    void search (int key){
        int ind=hash(key);
        int i=0;
        while (i<tsize){
            int probe=(ind + i*i)%tsize;
            if (table[probe]==key){
                cout << key<< " found at index " << probe << "\n";
                return;
            }
            i++;
        }
        cout << "value not found \n";
    }
    void display(){
        int i=0;
        while (i<tsize){
            cout << i << ":";
            cout << table[i] << "\n";
            i++;
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