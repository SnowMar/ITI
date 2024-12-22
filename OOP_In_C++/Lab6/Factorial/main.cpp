#include <iostream>

using namespace std;

class factorial{

    public factorial : (){

        int factoFind(int n){
            if(n == 1){
                return 1;
            }else{
                return n * factoFind(n -1);
            }
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
