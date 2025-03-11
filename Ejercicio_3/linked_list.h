#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int value;
    unique_ptr<Node> next;

    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList();
    void push_front(int value);
    void push_back(int value);
    void insert(int value, int position);
    void erase(int position);
    void print_list();
    
private:
    unique_ptr<Node> head;
};

#endif 
