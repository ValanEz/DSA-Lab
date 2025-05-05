//program to implement circular linked list using c++

#include<iostream>
using namespace std;

class Clist{
    struct node{
        int data;
        struct node* next;
    }*head,*tail;

    public:
      Clist();
      void insert_beg(int);
      void insert_pos(int,int);
      void insert_end(int);
      int len_ll();
      int del_beg();
      int del_end();
      int del_pos(int);
      void display();
      int search(int);
};

int main(){
    Clist c;
    int ch;
    while(true){
        cout << "\nMenu\n";
        cout << "1.Insertion at beginning\n";
        cout << "2.Insertion at position\n";
        cout << "3.Insertion at End\n";
        cout << "4.Deletion from beginning\n";
        cout << "5.Deletion from End\n";
        cout << "6.Deletion from position\n";
        cout << "7.Search\n";
        cout << "8.Display\n";
        cout << "9.Exit\n";
        cout << "Enter your choice (1-9):";
        cin  >> ch;

        if(ch == 9){
            cout << "\nExiting Program..\n";
            break;
        }

        switch(ch){
            case 1:
               int dat_beg;
               cout << "\nEnter the data to be inserted at the beginning:";
               cin  >> dat_beg;
               c.insert_beg(dat_beg);
               break;

            case 2:
              int dat_pos,pos;
              cout << "\nEnter the data to be inserted into list:";
              cin  >> dat_pos;
              cout << "\nEnter the position the data is to be inserted at:";
              cin  >> pos;
              
              if(pos == 0){
                 c.insert_beg(dat_pos);
                 break;
              }

              else if(pos == c.len_ll()-1){
                 c.insert_end(dat_pos);
                 break;
              }

              else{
                  c.insert_pos(dat_pos,pos);
                  break;
              }

            case 3:
              int dat_end;
              cout << "\nEnter the data to be inserted at the end of list:";
              cin  >> dat_end;
              c.insert_end(dat_end);
              break; 
              
            case 4:
              int del_val;
              del_val = c.del_beg();
              if(del_val == -1){
                 cout << "\nThe list is empty!!";
                 break;
              }  
              else{
                 cout << "The value that was deleted from the beginning of the list is : " << del_val;
                 break;
              }

            case 5:
              int del_val_end_;
              del_val_end_ = c.del_end();
              
              if(del_val_end_ == -1){
                 cout << "\nThe list is empty!!";
                 break;
              }

              else{
                  cout << "\nThe value that was deleted from the end of the list is : " << del_val_end_;
                  break;
              }

            case 6:
              int del_pos,del_val_end;
              cout << "\nEnter the position the data is to be deleted from:";
              cin  >> del_pos;
              if(del_pos == 0){
                 del_val_end = c.del_beg();
                 if(del_val_end == -1){
                    cout << "\nThe list is empty!!";
                    break;
                 }
                 else{
                    cout << "\nThe value that was deleted is : " << del_val_end;
                    break;
                 }
              }

              else if(del_pos == c.len_ll()-1){
                 del_val_end = c.del_end();
                 if(del_val_end == -1){
                    cout << "\nThe list is empty!!";
                    break;
                 }
                 else{
                     cout << "\nThe value that was deleted is : " << del_val_end;
                     break;
                 }
              }

              else{
                 del_val_end = c.del_pos(del_pos);
                 if(del_val_end == -1){
                     cout << "\nThe List is empty!!";
                     break;
                 }
                 else{
                     cout << "The value that was deleted from position " << del_pos << " is : " << del_val_end;
                     break;
                 }
              }

              case 7:{
                int key;
                cout << "\nEnter the element to be searched for:";
                cin  >> key;
                int found = c.search(key);
                if(found == -1){
                    cout << "\nThe given element could not be found";
                    break;
                }
                else{
                    cout << "The element " << key << " was found at position " << found;
                    break;
                }
            }
                
             case 8:
              c.display();
              break;

            default:
               cout << "\nEnter a valid choice(1-9)!!";
               break;    
        }
    }
}

Clist::Clist(){
    head = nullptr;
    tail = nullptr;
}

void Clist::insert_beg(int ele){
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = ele;
    newnode->next = nullptr;

    if(head == nullptr){
        head = newnode;
        tail = newnode;
        newnode->next = head;
    }

    else{
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }

}

void Clist::display(){
    if(head == nullptr){
        cout << "\nThe list is empty!!";
        return;

    }
    else{
      cout << "\nThe linked list is:\n";
      struct node* temp = head;
      while(temp->next != head){
        cout << temp->data << "->";
        temp = temp->next;
      }
      cout << temp->data << "->" << head->data;
    }
}

void Clist::insert_pos(int ele,int pos){
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = ele;
    newnode->next = nullptr;

    if(head == nullptr){
        head = newnode;
        tail = newnode;
        newnode->next = head;
    }
    else{
        struct node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void Clist::insert_end(int ele){
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = ele;
    newnode->next = nullptr;

    if(head == nullptr){
        head = newnode;
        tail = newnode;
        newnode->next = head;
    }

    else{
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }

}

int Clist::del_beg(){
    if(head == nullptr){
        return -1;
    }

    int del_val;

    if(len_ll() == 1){
        del_val = head->data;
        free(head);
        head = nullptr;
        tail = nullptr;

        return del_val;
    }

    else{
        struct node* temp = head;
        del_val = head->data;
        head = head->next;
        tail->next = head;
        free(temp);

        return del_val;
    }
}

int Clist::len_ll(){
    if(head == nullptr){
        return 0;
    }
    int len = 1;
    struct node* temp = head;
    while(temp->next != head){
        len = len + 1;
        temp = temp->next;
    }
    return len;
}

int Clist::del_end(){
    if(tail == nullptr){
        return -1;
    }

    int del_val;

    if(len_ll() == 1){
        del_val = tail->data;
        free(tail);
        tail = nullptr;
        head = nullptr;

        return del_val;
    }

    else{
        del_val = tail->data;
        struct node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        struct node* del_node = tail;
        tail = temp;
        tail->next = head;
        free(del_node);

        return del_val;
    }
}

int Clist::del_pos(int pos){
    if(head == nullptr){
        return -1;
    }

    int del_val;

    if(head == tail){
        del_val = head->data;
        free(head);
        head = nullptr;
        tail = nullptr;

        return del_val;
    }

    else{
        struct node* temp1 = head;
        for(int i=0;i<pos-1;i++){
            temp1 = temp1->next;
        }
        struct node* temp2 = temp1->next;
        del_val = temp2->data;
        temp1->next = temp2->next;

        free(temp2);
        return del_val;   
    }
}

int Clist::search(int key){
    if(head == nullptr){
        return -1;
    }

    else{
        struct node* temp = head;
        for(int i=0;i<len_ll();i++){
            if(temp->data == key){
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }
}