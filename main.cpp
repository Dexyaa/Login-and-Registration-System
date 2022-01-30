#include <iostream>
#include <string>
#include <
using namespace std;


int main(){
    int a = 5;
    int b (0);
    int c{5};
    int result;
    string mystring;
    mystring = "hello";
    
    a = a + b;
    result = c - a;

    cout << result << endl;
    cout << mystring << endl;

    cout << "What is your name?" << endl;
    getline(cin, mystring);
    cout << "My name is " << mystring << ".\n" << endl;
    cout << "Type in your favorite number";
    cin >> a;
    cout << "Your favorite number is " << a << ".\n";

    if(a == 0){
        cout << "That's why you have no friends bitch.";
    else if (a == 1)
        cout << "You are a winner";
    else
        cout << "Fair enough";
    

    return 0;
}