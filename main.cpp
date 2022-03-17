#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;


int c;
void login();
void registers();


int main(){
  cout << "Welcome to the login page" << endl;
  cout << "What would you like to do?" << endl;
  cout << "1) Login" << endl;
  cout << "2) Register" << endl;
  cout << "3) Leave" << endl;


  cin >> c;

  switch(c){
    case 1:
      login();
      break;
    case 2:
      registers();
      break;
    case 3:
      return EXIT_SUCCESS;
      break;
    default:
      cout << "Select a number between 1 to 3";
      main();
  }

  void login(){
    string username, password;
    cout << "Enter your username and password" << endl;
    cin >> username;
    cin >> password;

    cout << "hi" << endl;
  }

  void registers(){
    string username, password;
    cout << "hi" << endl;
  }
}