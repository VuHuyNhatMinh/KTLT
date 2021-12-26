#include <iostream>
#include "Morse2String.h"
#include <fstream>
using namespace std;

int main(){
    FILE* inputFile = fopen("data.txt", "r");
    if(inputFile == NULL) {
      perror("Error opening file");
      return(-1);
    }
    char temp[2];
    string* input = new string;
     while (fgets (temp, 2, inputFile)!=NULL)
    {
      
      /* writing content to stdout */
      *input += temp;
   
    }
    string* english = decrypt(input);
    ofstream myfile;
    myfile.open ("result.txt");
    myfile << *english;
    myfile.close();
    delete english; // return the memory to the operating system.
    delete input;
    system("pause");
    return 0;
}