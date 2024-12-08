#ifndef STACK_H
#define STACK_H


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
            std::cout<<"\nEverything is deleted";
        }

        void push(int);
        int pop();
        friend void viewContent(Stack x);
        //void viewContentByRef(Stack &x);
};

void Stack::push(int n){
    if(top==ssize){
        std::cout<<"\nStack Is Full\n";
    }
    else{
        sp[top] = n;
        top++;
    }
}

int Stack::pop(){
    int retVal;

    if(top==0){
        std::cout<<"\nStack is empty\n";
        retVal = -1;
    }
    else{
        top--;
        retVal = sp[top];
    }
    return retVal;
}

#endif // STACK_H





