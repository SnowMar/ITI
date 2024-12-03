#include <iostream>

using namespace std;

class Stack{
    private:
        int ssize;
        int *sp;
        int top;

    public:
        Stack(int n = 10){
            top = 0;
            ssize = n;
            sp = new int[ssize];
        }
        ~Stack(){
            delete []sp;
            cout<<"\nEverything is deleted";
        }

        void push(int);
        int pop();
};

void Stack::push(int n){
    if(top==ssize){
        cout<<"\nStack Is Full"<<endl;
    }
    else{
        sp[top] = n;
        top++;
    }
}

int Stack::pop(){
    int retVal;

    if(top==0){
        cout<<"\nStack is empty"<<endl;
        retVal = -1;
    }
    else{
        top--;
        retVal = sp[top];
    }
    return retVal;
}

int main()
{
    cout<<"\nEnter In Stack"<<endl;

    Stack s1(5);
    s1.push(5);
    s1.push(14);
    s1.push(20);
    cout<<s1.pop();


    return 0;
}
