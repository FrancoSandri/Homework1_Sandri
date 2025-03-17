#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <memory>

using namespace std;

// Estructura de un nodo de la lista.
struct Node {
    int value;
    unique_ptr<Node> next;

    Node(int val) : value(val), next(nullptr) {}
};

// Declaro las funciones para manipular la lista enlazada.
void create_node(unique_ptr<Node>& head, int value);
void push_front(unique_ptr<Node>& head, int value);
void push_back(unique_ptr<Node>& head, int value);
void insert(unique_ptr<Node>& head, int value, int position);
void erase(unique_ptr<Node>& head, int position);
void print_list(const unique_ptr<Node>& head);

#endif