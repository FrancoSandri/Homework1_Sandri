#include "linked_list.h"

void push_front(unique_ptr<Node>& head, int value) {
    unique_ptr<Node> new_node = make_unique<Node>(value);
    new_node->next = move(head);
    head = move(new_node);
}

void push_back(unique_ptr<Node>& head, int value) {
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

void insert(unique_ptr<Node>& head, int value, int position) {
    if (position == 0) {
        push_front(head, value);
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
        push_back(head, value);
        return;
    }

    unique_ptr<Node> new_node = make_unique<Node>(value);
    new_node->next = move(temp->next);
    temp->next = move(new_node);
}

void erase(unique_ptr<Node>& head, int position) {
    if (!head) return;

    if (position == 0) {
        head = move(head->next);
        return;
    }

    Node* temp = head.get();
    Node* prev = nullptr;
    int index = 0;

    while (temp->next) {
        if (index == position - 1) { 
            temp->next = move(temp->next->next);
            return;
        }
        prev = temp;
        temp = temp->next.get();
        index++;
    }

    if (prev) {
        cout << "Posición fuera de rango, eliminando el último nodo." << endl;
        prev->next = nullptr;
    }
}

void print_list(const unique_ptr<Node>& head) {
    Node* temp = head.get();
    while (temp) {
        cout << temp->value;
        if (temp->next) cout << " -> ";
        temp = temp->next.get();
    }
    cout << endl;
}

int main() {
    unique_ptr<Node> head = nullptr;

    push_front(head, 10);
    push_front(head, 20);
    push_front(head, 30);
    cout << "Lista después de push_front: ";
    print_list(head);

    push_back(head, 40);
    push_back(head, 50);
    cout << "Lista después de push_back: ";
    print_list(head);

    insert(head, 25, 2);
    insert(head, 60, 10);
    cout << "Lista después de insert(): ";
    print_list(head);

    erase(head, 2);
    erase(head, 10); 
    cout << "Lista después de erase(): ";
    print_list(head);

    return 0;
}