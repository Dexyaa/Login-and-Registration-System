#include <iostream>
#include <fstream>
using namespace std;


int c;
void login();
void registers();
string fileName = "myFile.txt";

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


}


void login(){
  string username, password;
  string usernameindatabase, passwordindatabase;
  cout << "Enter your username and password" << endl;
  cin >> username;
  cin >> password;

  ifstream file;
  file.open(fileName, ios::trunc | ios::in);

  file >> usernameindatabase;
  file >> passwordindatabase;

  
  if(username == usernameindatabase && password == passwordindatabase){
    cout << "You have logged in" << endl;
  } else {
    cout << "Incorrect username and password" << endl;
    main();
  }

}

void registers(){
  cout << "Register by entering your username and password" << endl;
  string username, password;
  cin >> username;
  cin >> password;

  cout << "Successfully entered the username and password" << endl;

  ofstream file;
  file.open(fileName, ios::trunc | ios::out);
  if(!file){
    cerr << "Cannot open the file" << "\n";
    exit(1);
  }

  file << username << endl;
  file << password << endl;

  file.close();

  main();
}