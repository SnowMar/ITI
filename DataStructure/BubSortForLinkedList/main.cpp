#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to bubble sort the doubly linked list
void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data of adjacent nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to print the doubly linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to push a new node at the front
void push(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

int main() {
    Node* head = nullptr;
    push(head, 5);
    push(head, 1);
    push(head, 4);
    push(head, 2);
    push(head, 8);

    cout << "Original List: ";
    printList(head);

    bubbleSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
