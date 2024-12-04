#include <iostream>
#include "Stack.h"

using namespace std;

void viewContent(Stack x){
    int t = x.top;
    while(t!=0){
        cout<<x.sp[--t]<<endl;
    }
}

/*void viewContentByRef(const Stack& x) {
    int t = x.top;
    while (t != 0) {
        cout << x.sp[--t] << endl;
    }
}*/
int main()
{
    Stack s(3);
    s.push(10);
    s.push(20);
    s.push(30);
    viewContent(s);
    cout<<"By Refrence===================="<<endl;
    //viewContentByRefrence(s);
    return 0;
}
