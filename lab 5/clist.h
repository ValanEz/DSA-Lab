#ifndef CLIST_H
#define CLIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Clist {
    struct node {
        int data;
        struct node* next;
    } *head, *tail;

public:
    Clist();
    void insert_beg(int);
    void insert_pos(int, int);
    void insert_end(int);
    int len_ll();
    int del_beg();
    int del_end();
    int del_pos(int);
    void display();
    int search(int);
};

#endif
