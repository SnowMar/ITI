#include <iostream>

using namespace std;

class LinkedListNode{

public:
    int data;
    LinkedListNode *next;


    LinkedListNode(int _data){
        this->data = _data;
        this->next = NULL;
    }
};


class linkedList{

public:
    LinkedListNode *head = NULL;
    LinkedListNode *tail = NULL;

    void insertLast(int _data){
        LinkedListNode *newNode = new LinkedListNode(_data);
        if(this->head == NULL){
            this->head = newNode;
            this->tail = newNode;
        }
        else{
            this->tail->next =newNode;
            this->tail = newNode;
        }
    }

    LinkedListNode *findNode(LinkedListNode *nodeTobeFound){
        LinkedListNode *current = this->head;
        while(current != NULL && current->data != nodeTobeFound->data){
                current = current->next;
                return current->data;
        }
        return NULL;
    }

    void insertAfter(LinkedListNode *node, int _data){
        LinkedListNode *newNode = new LinkedListNode(_data);
        findNode(node);

        newNode->next = node->next;
        node->next = newNode;
    }

    void printList(){
        LinkedListNode *current = this->head;
        while(current != NULL){
            cout<<current->data<<"->";
            current = current->next;
        }
        cout<<endl;
    }

    void removeItem(int _data){
        LinkedListNode *current = this->head;
        LinkedListNode *previous = NULL;

        while(current != NULL && current->data != _data){
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        delete current;
    }

};

class iteratorForList{

};


int main()
{
    linkedList test;
    test.insertLast(5);
    test.insertLast(3);
    test.insertLast(60);
    test.insertLast(70);
    test.insertLast(80);
    test.printList();
    test.removeItem(60);
    test.printList();
    test.insertAfter(test.findNode(70),75);
    test.printList();
    return 0;
}
