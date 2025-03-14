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

// Funciones para manipular la lista enlazada
void push_front(unique_ptr<Node>& head, int value);
void push_back(unique_ptr<Node>& head, int value);
void insert(unique_ptr<Node>& head, int value, int position);
void erase(unique_ptr<Node>& head, int position);
void print_list(const unique_ptr<Node>& head);

#endif // LINKED_LIST_H