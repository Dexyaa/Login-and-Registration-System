#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

namespace fs = std::filesystem;

//


int main(){
  vector<string> filesToCheck = {"database"};

  for(const auto &file : filesToCheck){
    if(!exists(file)){
      cout << "Doesn't exist\n";
      ofstream Database("database.txt");
    } else {
      cout << "The file exists" << endl;
    }
  }
  
}