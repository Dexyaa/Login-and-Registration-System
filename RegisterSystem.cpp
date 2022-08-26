#include <iostream>
#include <fstream>
#include <string>


void Login();
void Register();
void eraseFileLine();
void DeleteAccount();

int main(){
    
    while(1){
        std::string choice;
        std::cout << "What would you like to do? Login or make an account are your choices" << "\n";
        std::cin >> choice;
        if(choice == "Login"){
            Login();
        } else if (choice == "Register"){
            Register();
        } else if(choice == "Delete"){
            DeleteAccount();
        }
         else {
            std::cout << "You didnt provide a valid input. The program will terminate";
            return 0; 
        }
        
    }
    
    return 0;
}


void Login(){
    bool entered = false;
    std::ifstream usersfile ("usersfile");
    usersfile.open("usersfile", std::ios::in);
    std::string username;
    std::string password;


    std::cout << "What is your username and password?" << "\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "\n";
    std::cout << "Password: ";
    std::cin >> password;


    if(usersfile.is_open()){
        std::string user;
        std::string pass;
        while(usersfile){
            std::getline(usersfile, user);
            if(user == username){
                std::getline(usersfile, pass);
                if(pass == password){
                    std::cout << "Successfully logged in" << "\n";
                    entered = true;
                    break;
                }
            }
        }
        if(entered == false){
            std::cout << "Username and password not found in file" << "\n";
        }
    } else {
        std::cout << "Could not enter file. Terminating Login." << "\n";
        
    }
    usersfile.close();
}

void Register(){
    std::ofstream usersfile ("usersfile");
    usersfile.open("usersfile", std::ios::app);
    std::string username;
    std::string password;
    std::cout << "What would you like your username and password to be?" << "\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "\n";
    std::cout << "Password: ";
    std::cin >> password;
    if(usersfile.is_open()){
        usersfile << username << std::endl;
        usersfile << password << std::endl;
    }
    std::cout << "Your username and password has been entered." << "\n";
    usersfile.close();

}

void eraseFileLine(std::string path, std::string eraseLine) {
    std::string line;
    std::ifstream fin;
    
    fin.open(path);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    std::ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        // write all lines to temp other than the line marked for erasing
        if (line != eraseLine)
            temp << line << std::endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char * p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}

void DeleteAccount(){
    std::fstream usersfile ("usersfile");
    usersfile.open("usersfile", std::ios::out | std::ios::in);
    std::string username;
    std::string password;
    std::cout << "Type in your username and password to verify identity." << "\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "\n";
    std::cout << "Password: ";
    std::cin >> password;

    if(usersfile.is_open()){
        bool entered = false;
        std::string user;
        std::string pass;
        while(usersfile){
            std::getline(usersfile, user);
            if(user == username){
                std::getline(usersfile, pass);
                if(pass == password){
                    eraseFileLine("usersfile", username);
                    eraseFileLine("usersfile", password);
                    std::cout << "Account successfully deleted";
                    entered = true;
                    break;
                }
            }
        }
        if(entered == false){
            std::cout << "Username and password not found in file" << "\n";
        }
    }

    usersfile.close();
}

