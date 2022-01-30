#include <iostream>
using namespace std;


int main(){
    int a = 5;
    int b (0);
    int c{5};
    int result;
    
    a = a + b;
    result = c - a;

    cout << result;

    return 0;
}