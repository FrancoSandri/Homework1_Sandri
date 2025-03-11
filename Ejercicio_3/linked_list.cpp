#include "linked_list.h"

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::push_front(int value) {
    unique_ptr<Node> new_node = make_unique<Node>(value);
    new_node->next = move(head);
    head = move(new_node);
}

void LinkedList::push_back(int value) {
    unique_ptr<Node> new_node = make_unique<Node>(value);
    if (!head) {
        head = move(new_node);
        return;
    }
    Node* temp = head.get();
    while (temp->next) {
        temp = temp->next.get();
    }
    temp->next = move(new_node);
}

void LinkedList::insert(int value, int position) {
    if (position == 0) {
        push_front(value);
        return;
    }

    Node* temp = head.get();
    int index = 0;

    while (temp && index < position - 1) {
        temp = temp->next.get();
        index++;
    }

    if (!temp) {
        cout << "Posición fuera de rango, insertando al final." << endl;
        push_back(value);
        return;
    }

    unique_ptr<Node> new_node = make_unique<Node>(value);
    new_node->next = move(temp->next);
    temp->next = move(new_node);
}

void LinkedList::erase(int position) {
    if (!head) return;

    if (position == 0) {
        head = move(head->next);
        return;
    }

    Node* temp = head.get();
    int index = 0;

    while (temp->next && index < position - 1) {
        temp = temp->next.get();
        index++;
    }

    if (!temp->next) {
        cout << "Posición fuera de rango, eliminando el último nodo." << endl;
        return;
    }

    temp->next = move(temp->next->next);
}

void LinkedList::print_list() {
    Node* temp = head.get();
    while (temp) {
        cout << temp->value;
        if (temp->next) cout << " -> ";
        temp = temp->next.get();
    }
    cout << endl;
}

int main() {
    LinkedList list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    cout << "Lista después de push_front: ";
    list.print_list();

    list.push_back(40);
    list.push_back(50);
    cout << "Lista después de push_back: ";
    list.print_list();

    list.insert(25, 2); // Debe insertarse entre 20 y 10
    list.insert(60, 10); // Fuera de rango, se agrega al final
    cout << "Lista después de insert(): ";
    list.print_list();

    list.erase(2); // Borra el nodo con valor 25
    list.erase(10); // Fuera de rango, borra el último nodo
    cout << "Lista después de erase(): ";
    list.print_list();

    return 0;
}
