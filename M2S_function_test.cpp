#include <iostream>
#include "Morse2String.h"
using namespace std;

int main(){
    string msg = ".-- .... .- - /.... .- - .... /--. --- -.. /.-- .-. --- ..- --. .... -";
    string *input = &msg;
    string* english = decrypt(input);
    cout << *english << '\n';
    delete english; // return the memory to the operating system.
    system("pause");
    return 0;

}