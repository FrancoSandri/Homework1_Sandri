#include "ejercicio3.h"

// Creo y devuelvo un nuevo nodo con el valor dado.
unique_ptr<Node> create_node(int value) {
    return make_unique<Node>(value);
}


// Añade un nodo al inicio de la lista.
// Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
// Si la lista no está vacía, el nuevo nodo se convierte en la cabeza y apunta al nodo anterior.

void push_front(unique_ptr<Node>& head, int value) {
    // Creo un nuevo nodo con el valor dado.
    unique_ptr<Node> new_node = create_node(value);
    // El nuevo nodo apunta al nodo actual de la cabeza.
    new_node->next = move(head);
    head = move(new_node);
}

// Añade un nodo al final de la lista.
// Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
// Si la lista no está vacía, recorro la lista hasta el último nodo y añado el nuevo nodo al final.

void push_back(unique_ptr<Node>& head, int value) {
    // Creo un nuevo nodo con el valor dado.
    unique_ptr<Node> new_node = create_node(value);
    Node* temp = head.get();

    // Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
    if (!temp) {
        head = move(new_node);
        return;
    }
    // Recorro la lista hasta el último nodo.
    while (temp->next) {
        // Si el nodo actual no es el último, avanzo al siguiente nodo.
        temp = temp->next.get();
    }
    // Añado el nuevo nodo al final de la lista.
    temp->next = move(new_node);
}

// Inserta un nodo en una posición específica de la lista.
// Si la posición es 0, el nuevo nodo se añade al inicio de la lista.
// Si la posición es mayor que la longitud de la lista, el nuevo nodo se añade al final de la lista.
// Si la posición es válida, se recorre la lista hasta la posición deseada y se inserta el nuevo nodo.

void insert(unique_ptr<Node>& head, int value, int position) {
    // Si la posición es 0, el nuevo nodo se añade al inicio de la lista.
    if (position == 0) {
        push_front(head, value);
        return;
    }

    Node* temp = head.get();
    int index = 0;
    // Recorro la lista hasta la posición deseada.
    while (temp && index < position - 1) {
        temp = temp->next.get();
        index++;
    }
    // Si la posición es mayor que la longitud de la lista, el nuevo nodo se añade al final de la lista.
    if (!temp) {
        cout << "Posición fuera de rango, insertando al final." << endl;
        push_back(head, value);
        return;
    }

    // Inserto el nuevo nodo en la posición deseada.
    unique_ptr<Node> new_node = create_node(value);
    // El nuevo nodo apunta al siguiente nodo del nodo actual.
    new_node->next = move(temp->next);
    // El nodo actual apunta al nuevo nodo.
    temp->next = move(new_node);
}

// Elimina un nodo en una posición específica de la lista.
// Si la posición es 0, se elimina el primer nodo de la lista.
// Si la posición es mayor que la longitud de la lista, se elimina el último nodo de la lista.
// Si la posición es válida, se recorre la lista hasta la posición deseada y se elimina el nodo.

void erase(unique_ptr<Node>& head, int position) {
    // Si la lista está vacía, no se puede eliminar ningún nodo.
    if (!head) return;

    // Si la posición es 0, se elimina el primer nodo de la lista.
    if (position == 0) {
        head = move(head->next);
        return;
    }

    Node* temp = head.get();
    Node* prev = nullptr;
    int index = 0;

    // Recorro la lista hasta la posición deseada.
    while (temp->next) {
        if (index == position - 1) { 
            temp->next = move(temp->next->next);
            return;
        }
        // Guardo el nodo actual como el nodo anterior.
        prev = temp;
        // Avanzo al siguiente nodo.
        temp = temp->next.get();
        index++;
    }
    // Si la posición es mayor que la longitud de la lista, se elimina el último nodo de la lista.
    if (prev) {
        cout << "Posición fuera de rango, eliminando el último nodo." << endl;
        prev->next = nullptr;
    }
}

// Imprime los valores de la lista enlazada.
// Recorre la lista desde la cabeza hasta el último nodo, imprimiendo los valores de cada nodo.
// Si el nodo actual tiene un nodo siguiente, imprime una flecha "->" para indicar la conexión.
// Si el nodo actual es el último nodo, imprime una nueva línea.
// Si la lista está vacía, no imprime nada.

void print_list(const unique_ptr<Node>& head) {
    Node* temp = head.get();
    // Recorro la lista desde la cabeza hasta el último nodo.
    while (temp) {
        cout << temp->value;
        // Si el nodo actual tiene un nodo siguiente, imprimo una flecha "->".
        if (temp->next) cout << " -> ";
        temp = temp->next.get();
    }
    cout << endl;
}

int main() {
    // Creo una lista enlazada vacía.
    unique_ptr<Node> head = nullptr;

    // Añado nodos a la lista enlazada. Usando push front.
    push_front(head, 10);
    push_front(head, 20);
    push_front(head, 30);
    // Imprimo la lista después de añadir nodos.
    cout << "Lista después de push_front: ";
    print_list(head);

    // Añado más nodos a la lista enlazada. Esta vez usando push back.
    push_back(head, 40);
    push_back(head, 50);
    // Imprimo la lista después de añadir más nodos.
    cout << "Lista después de push_back: ";
    print_list(head);
    
    // Inserto nodos en posiciones específicas de la lista.
    insert(head, 25, 2);
    // Inserto fuera de rango para que se añada al final.
    insert(head, 60, 10);
    // Imprimo la lista después de insertar nodos.
    cout << "Lista después de insert(): ";
    print_list(head);

    // Elimino nodos en posiciones específicas de la lista.
    erase(head, 2);
    // Elimino fuera de rango para que se elimine el último nodo.
    erase(head, 10); 
    // Imprimo la lista después de eliminar nodos.
    cout << "Lista después de erase(): ";
    print_list(head);

    return 0;
}