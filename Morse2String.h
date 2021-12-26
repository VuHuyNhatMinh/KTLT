/* Author: Nguyen Dinh Quoc Dai 20191724*/
#include "Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

// Decrypt no dynamic mem
string Decrypt(string input){
    input += " "; //extra space added at the end to access the last morse code
    string output ; 
    string temp;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ' && input[i] != '/' && input[i] != '\n'){ // Check space, "new line" (\n) and slash.
            temp += input[i]; //storing morse code of a single character
        }
        else if (input[i] == '/'){//in case of forward-slash
            output += ' '; // append ' ' to the output string.
        }        
        else if(input[i] == ' ' || input[i] == '\n'){ //in case of space or '\n'       
            if (temp != "")
            {
                output += Morse2Char(temp); // search the dictionary for matching character.
                temp.clear(); // clear the temporary variable.
            }
            if(input[i] == '\n'){output += '\n';} // in case of '\n' append '\n' to output.
        }
    }
    return output;
}
