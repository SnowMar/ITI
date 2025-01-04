#include <iostream>
using namespace std;

class linkedListNode{
    public:

    int data;
    linkedListNode *next;

    linkedListNode(int _data){
        this->data = _data;
        this-> next = NULL;
    }
};

class linkedListIterator{};

class linkedList{
public:
    linkedListNode *head = NULL;
    linkedListNode *tail = NULL;

    void insertNode(){
        if(){

        }
    }
};

int main(){
    linkedListNode* node1 = new linkedListNode(5);

    // Create another node with data value 10
    linkedListNode* node2 = new linkedListNode(10);

    linkedListNode* node3 = new linkedListNode(30);

    node1->next = node2;

    node2->next = node3;

    // Access and print data
    cout << "Node 1 data: " << node1->data << endl;
    cout << "Node 2 data: " << node1->next->data << endl;
    cout << "Node 3 Data  " << node1->next->next->data<<endl;
    // Free memory
    delete node1;
    delete node2;

    return 0;

}
