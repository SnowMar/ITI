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
    void printList(){
        LinkedListNode *current = this->head;
        while(current != NULL){
            cout<<current->data;
            current = current->next;
        }
    }

    void removeItem(int _data){
        LinkedListNode *current = this->head;

        for(; current->data != _data; current = current->next)
            cout<<"Worked";

        /*if(_data != current->data){
            current = current->next
        }*/

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
    test.removeItem(80);
    return 0;
}
