#include <iostream>
using namespace std;

class list {
    struct node {
        int data;
        struct node *next;
    } *head, *tail;

public:
    list();
    void InsertEnd(int);
    void insertbeg(int);
    void display();
    void insertpos(int, int);
    int delbeg();
    int delend();
    int delpos(int);
    int search(int);
};

int main() {
    list l1;
    while (1) {
        int ch1;
        printf("1. Insert at beg\n");
        printf("2. Insert at end \n");
        printf("3. Insert position \n");
        printf("4. Delete beg \n");
        printf("5. Delete End \n");
        printf("6. Delete position \n");
        printf("7. Search \n");
        printf("8. Display\n");
        printf("9. End \n ");
        printf("Enter your choice:");
        scanf("%d", &ch1);
        printf("\n");

        if (ch1 == 1) {
            int num;
            printf("Enter number:");
            scanf("%d", &num);
            l1.insertbeg(num);
        }
        if (ch1 == 2) {
            int num;
            printf("Enter number:");
            scanf("%d", &num);
            l1.InsertEnd(num);
        }
        if (ch1 == 3) {
            int num, pos;
            printf("Enter number:");
            scanf("%d", &num);
            printf("Enter pos:");
            scanf("%d", &pos);
            l1.insertpos(num, pos);
        }
        if (ch1 == 4) {
            int ch = l1.delbeg();
            if (ch == -1) {
                printf("List is empty");
            } else {
                printf("Deleted element: %d \n", ch);
            }
        }
        if (ch1 == 5) {
            int ch = l1.delend();
            if (ch == -1) {
                printf("List is empty");
            } else {
                printf("Deleted element: %d \n", ch);
            }
        }
        if (ch1 == 6) {
            int pos, ch;
            printf("Enter position:");
            scanf("%d", &pos);
            ch = l1.delpos(pos);
            if (ch == -1) {
                printf("Empty list");
            } else {
                printf("Deleted element: %d \n", ch);
            }
        }
        if (ch1 == 7) {
            int num, ch;
            printf("Enter value to be searched:");
            scanf("%d", &num);
            ch = l1.search(num);
            if (ch == -1) {
                printf("Empty list");
            } else if (ch == -2) {
                printf("Value not found");
            } else {
                printf("Position of value: %d \n", ch);
            }
        }
        if (ch1 == 8) {
            l1.display();
        }
        if (ch1 == 9) {
            break;
        }
    }
    return 0;
}

list::list() {
    head = NULL;
    tail = NULL;
}

void list::insertbeg(int num) {
    struct node *newnode = (struct node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = head;
    head = newnode;
    if (tail == NULL) {
        tail = newnode;
    }
}

void list::InsertEnd(int num) {
    struct node *newnode = (struct node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void list::insertpos(int num, int pos) {
    struct node *newnode = (struct node *)malloc(sizeof(node));
    newnode->data = num;
    if (pos == 0 || head == NULL) {
        newnode->next = head;
        head = newnode;
        if (tail == NULL) {
            tail = newnode;
        }
        return;
    }
    struct node *temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    if (newnode->next == NULL) {
        tail = newnode;
    }
}

void list::display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int list::delbeg() {
    if (head == NULL) {
        return -1;
    }
    struct node *temp = head;
    int num = temp->data;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
    return num;
}

int list::delend() {
    if (head == NULL) {
        return -1;
    }
    struct node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    int num = temp->data;
    if (prev == NULL) {
        head = NULL;
        tail = NULL;
    } else {
        prev->next = NULL;
        tail = prev;
    }
    free(temp);
    return num;
}

int list::delpos(int pos) {
    if (head == NULL) {
        return -1;
    }
    struct node *temp = head, *prev = NULL;
    if (pos == 0) {
        int num = temp->data;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        free(temp);
        return num;
    }
    for (int i = 0; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return -1;
    }
    prev->next = temp->next;
    if (temp->next == NULL) {
        tail = prev;
    }
    int num = temp->data;
    free(temp);
    return num;
}

int list::search(int num) {
    struct node *temp = head;
    int c = 0;
    if (temp == NULL) {
        return -1;
    }
    while (temp != NULL) {
        if (temp->data == num) {
            return c;
        }
        c++;
        temp = temp->next;
    }
    return -2;
}
