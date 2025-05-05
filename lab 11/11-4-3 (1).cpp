#include <iostream>
using namespace std;
#include <list>
const int tsize=10;
class HashTable{
    private:
    list <int>table[tsize];
    public:
    int hash(int key){
        return key%tsize;
    }
    void insert(int key){
        int ind=hash(key);
        for (int val :table[ind]){
            if (val==key){
                cout << "Value exists \n";
                return;
            }
        }
        table[ind].push_back(key);
        cout << "inserted at " << ind << "\n";
    }
    void remove(int key){
        int ind = hash(key);
        auto& chain=table[ind];
        for (auto it = chain.begin();it!=chain.end();it++){
            if (*it == key){
                chain.erase(it);
                cout << "deleted " << key << " from " << ind << endl;
                return;
            }
        }
        cout << " value not found \n";
    }
    void search (int key){
        int ind = hash(key);
        for (int val: table[ind]){
            if (val==key){
                cout << "Key found at " << ind << endl;
                return;
            }
        }
        cout << "Value not found \n";
    }
    void display(){
        int i=0;
        while (i<tsize){
            cout << i << ":";
            for (int val :table[i]){
                cout << val << " -> ";
            }
            cout << "NULL \n";
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