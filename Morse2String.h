#include "Dictionary.h"
#include <iostream>
#include <string>
using namespace std;
// function for decrypting. Input: Adress of the message (string*). Output: Adress of the text.
string* decrypt(string* input){
    *input += " "; //extra space added at the end to access the last morse code
    string* output = new string; 
    if (!output)
    {
        return NULL;
    }
    string temp;
    for (int i = 0; i < input->length(); i++)
    {
        if (input->at(i) != ' ' && input->at(i) != '/'){ // Check space and slash.
            temp += input->at(i); //storing morse code of a single character
        }
        else if (input->at(i) == '/'){//in case of forward-slash
            *output += ' '; // append ' ' to the output string.
        }        
        else if(input->at(i) == ' '){ //in case of space         
            *output += Morse2Char(temp); // search the dictionary for matching character.
            temp.clear(); // clear the temporary variable.
        }
    }
    return output;
}