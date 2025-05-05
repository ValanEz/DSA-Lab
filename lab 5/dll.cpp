//program to implement doubly linked list 

#include<iostream>
using namespace std;

class Dlist{
     struct node{
        struct node* prev;
        int data;
        struct node* next;
     }*head,*tail;

     public:
       Dlist();
       void insert_beg(int);
       void insert_end(int);
       void insert_pos(int,int);
       int del_beg();
       int del_end();
       int del_pos(int);
       int len_ll();
       int search(int);
       void display();
};

int main(){
    Dlist d;
    int ch;
    int dat;
    int pos;
    int del_val;

    while(true){
        cout << "\nMenu\n";
        cout << "1.Insert at beginning\n";
        cout << "2.Insert at end\n";
        cout << "3.Insert at position\n";
        cout << "4.Delete from beginning\n";
        cout << "5.Delete from End\n";
        cout << "6.Delete from position\n";
        cout << "7.Search\n";
        cout << "8.Display\n";
        cout << "9.Exit\n";
        cout << "\nEnter your choice(1-9):";
        cin  >> ch;

        if(ch == 9){
            cout << "\nExiting Program...";
            break;
        }

        switch(ch){
            case 1:
              cout << "\nEnter the data to be inserted at the beginning of the list:";
              cin  >> dat;
              d.insert_beg(dat);
              break;

            case 2:
               cout << "\nEnter the data to be inserted at the end of the list:";
               cin  >> dat;
               d.insert_end(dat);
               break;

            case 3:
               cout << "\nEnter the data to be inserted:";
               cin  >> dat;
               cout << "\nEnter the position the data is to be inserted at:";
               cin  >> pos;

               if(pos == 0){
                 d.insert_beg(dat);
                 break;
               }

               else if(pos == d.len_ll()-1){
                  d.insert_end(dat);
                  break;
               }

               else{
                  d.insert_pos(dat,pos);
                  break;
               }

            case 4:
              del_val = d.del_beg();
              if(del_val == -1){
                 cout << "\nThe list is empty!!";
                 break;
              }
              else{
                 cout << "\nThe value that was deleted from the beginning of the list is : " << del_val;
                 break;
              }

            case 5:
               del_val = d.del_end();
               if(del_val == -1){
                  cout << "\nThe list is empty!!";
                  break;
               }  
               else{
                  cout << "\nThe value that was deleted from the end of the list is : " << del_val;
                  break;
               }

            case 6:
               cout << "\nEnter the position the data is to be deleted from:";
               cin  >> pos;
               
               if(pos == 0){
                  del_val = d.del_beg();
                  if(del_val == -1){
                     cout << "\nThe list is empty!!";
                     break;
                  }
                  else{
                     cout << "\nThe value that was deleted is : " << del_val;
                     break; 
                  }
               }

               else if(pos == d.len_ll()-1){
                 del_val = d.del_end();
                 if(del_val == -1){
                    cout << "\nThe list is empty!!";
                    break;
                 }
                 else{
                    cout << "\nThe value that was deleted is : " << del_val;
                    break; 
                 }
               }

               else{
                 del_val = d.del_pos(pos);
                 if(del_val == -1){
                    cout << "\nThe list is empty!!";
                    break;
                 }
                 else{
                    cout << "\nThe value that was deleted is : " << del_val;
                    break; 
                 }
               }

            case 7:
              int key,found;
              cout << "\nEnter the value to be searched for:";
              cin  >> key;
              
              found = d.search(key);

              if(found == -1){
                 cout << "\nThe given key element was not found in list!!";
                 break;
              }

              else{
                 cout << "The given element " << key << " was found at position: " << found;
                 break;
              }
              
            case 8:
              d.display();
              break;

            default:
              cout << "\nInvalid choice choose between(1-10)!!";
              break;  
        }
        
    }


}

Dlist::Dlist(){
    head = nullptr;
    tail = nullptr;
}

void Dlist::insert_beg(int ele){
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = ele;
    newnode->prev = nullptr;
    newnode->next = nullptr;

    if(head == nullptr){
        head = newnode;
        tail = newnode;
    }

    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void Dlist::display(){
    if(head == nullptr){
        cout << "\nThe list is empty!!";
        return;
    }
    else{
        cout << "\nThe linked list is:\n";
        struct node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL";
    }

}

void Dlist::insert_end(int ele){
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = ele;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if(head == nullptr){
        head = newnode;
        tail = newnode;
    }

    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void Dlist::insert_pos(int ele,int pos){
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = ele;
    newnode->prev = nullptr;
    newnode->next = nullptr;

    if(head == nullptr){
        head = newnode;
        tail = newnode;
    }
    else{
        struct node* temp = head;
        for(int i=0;i<pos;i++){
            temp = temp->next;
        }
        newnode->prev = temp->prev;
        newnode->next = temp;
        (temp->prev)->next = newnode;
        temp->prev = newnode;
    }
}

int Dlist::del_beg(){
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
        del_val = head->data;
        struct node* temp = head;
        head = temp->next;
        head->prev = nullptr;
        free(temp);

        return del_val;
    }
    
    

}

int Dlist::len_ll(){
    if(head == nullptr){
        return 0;
    }
    else{
        int len = 1;
        struct node* temp = head;
        while(temp->next != nullptr){
            len = len + 1;
            temp = temp->next;
        }
        return len;
    }

}

int Dlist::del_end(){
    if(tail == nullptr){
        return -1;
    }

    int del_val;

    if(head == tail){
        del_val = head->data;
        free(tail);
        tail = nullptr;
        head = nullptr;

        return del_val;
    }

    else{
        del_val = tail->data;
        tail = tail->prev;
        free(tail->next);
        tail->next = nullptr;
        
        return del_val;
    }
}

int Dlist::del_pos(int pos){
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
        struct node* temp = head;
        for(int i=0;i<pos;i++){
            temp = temp->next;
        }
        del_val = temp->data;
        (temp->prev)->next = temp-> next;
        (temp->next)->prev = temp->prev;
        free(temp);

        return del_val;  cout << "9.Reverse\n";
    }
}

int Dlist::search(int key){
    if(head == nullptr){
        return  -1;
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