#include <iostream>
#include <string>
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
        cout << "That's why you have no friends bitch.\n";
    }
    else if (a == 1) {
        cout << "You are a winner. \n";
    }
    else {
        cout << "Fair enough. \n";
    }
    int n = 10;

    while (n > 0){
        cout << n << " : ";
        n--;
    }

    string pin;

    do {
        cout << "Enter the correct pin: " << endl;
        getline(cin, pin);
        cout << "The pin you entered: " + pin + " was incorrect." << endl;

    } while (pin != "1024");
    

    return 0;
}