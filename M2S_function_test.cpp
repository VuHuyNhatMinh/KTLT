#include <iostream>
#include <fstream>
#include "Morse2String.h"
using namespace std;

int main(){
    string msg = ".-. . - .-. . .- - / .-- .- ... / -. --- - / -... ..- .. .-.. - / .- ... / .- -. / . ... -.-. .- .--. . / ..-. .-. --- -- / .-- --- .-. -.- .-.-.- / .. -. / .---- ----. ..--- ..--- --..-- / .-- .... . -. / .--- ..- -. --. / -... --- ..- --. .... - / - .... . / .--. .-. --- .--. . .-. - -.-- --..-- / .... . / -.-. --- ..- .-.. -.. / -. --- - / .- ..-. ..-. --- .-. -.. / - --- / - .- -.- . / .- / ...- .- -.-. .- - .. --- -. .-.-.- / --- -. .-.. -.-- / --- -. . / -.-- . .- .-. / . .- .-. .-.. .. . .-. --..-- / .. -. / .---- ----. ..--- .---- --..-- / .... . / .... .- -.. / .--. ..- -... .-.. .. ... .... . -.. / .--. ... -.-- -.-. .... --- .-.. --- --. .. -.-. .- .-.. / - -.-- .--. . ... --..-- / .- / ... . -- .. -. .- .-.. / -... --- --- -.- / - .... .- - / ... --- .-.. .. -.. .. ..-. .. . -.. / -- .- -. -.-- / -.. .. ..-. ..-. . .-. . -. -.-. . ... / - .... .- - / .... .- -.. / -... . . -. / .-.. --- -. --. / -.. . ...- . .-.. --- .--. .. -. --. / -... . - .-- . . -. / .--- ..- -. --. ... / - .... .. -. -.- .. -. --. / .- -. -.. / - .... . / .. -.. . .- ... / --- ..-. / .... .. ... / --- -. . - .. -- . / ..-. .-. .. . -. -.. / .- -. -.. / -- . -. - --- .-. --..-- / ... .. --. -- ..- -. -.. / ..-. .-. . ..- -.. .-.-.- / - --- / -.. .. ... .- --. .-. . . / .-- .. - .... / ..-. .-. . ..- -.. / .. -. / - .... . / .---- ----. ..--- ----- ... / .-- .- ... / .- / -... --- .-.. -.. / -- --- ...- . .-.-.- / - --- / -... .- -.-. -.- / ..- .--. / .... .. ... / -... --- --- -.- --..-- / .--- ..- -. --. / -. . . -.. . -.. / - --- / ... - .- -.-- / ... .... .- .-. .--. / .- -. -.. / .--. .-. --- -.. ..- -.-. . / .- / ... - .-. . .- -- / --- ..-. / ... -- .- .-. - / .- .-. - .. -.-. .-.. . ... / .- -. -.. / -... --- --- -.- ... / ..-. ..- .-. - .... . .-. / ... ..- .--. .--. --- .-. - .. -. --. / .- -. -.. / . ... - .- -... .-.. .. ... .... .. -. --. / .- -. .- .-.. -.-- - .. -.-. .- .-.. / .--. ... -.-- -.-. .... --- .-.. --- --. -.-- --..-- / - .... . / . ...- . -. - ..- .- .-.. / -. .- -- . / ..-. --- .-. / .... .. ... / -. . .-- / ... -.-. .... --- --- .-.. / --- ..-. / - .... --- ..- --. .... - .-.-.- / .--- ..- -. --. ... / .-.. . -.-. - ..- .-. . ... / .- -. -.. / -.-. --- ..- -. ... . .-.. .. -. --. / .--. .-. .- -.-. - .. -.-. . / -.- . .--. - / .... .. -- / -... ..- ... -.-- / .. -. / --.. ..- .-. .. -.-. .... - .... .. ... / .. ... / -.-. .-.. . .- .-. .-.-.- / -... ..- - / .... . / .-- .- ... -. - / ... .- - .. ... ..-. .. . -.. / .-- .. - .... / -... ..- ... -.-- -. . ... ... / .- .-.. --- -. . .-.-.- / .... . / .-- .- -. - . -.. / - --- / -.-. .... .- -. --. . / - .... . / .-- .- -.-- / .-- . / ..- -. -.. . .-. ... - --- --- -.. / - .... . / ..- -. -.-. --- -. ... -.-. .. --- ..- ... --..-- / .- -. -.. / - .... .. ... / --. --- .- .-.. / .-. . --.- ..- .. .-. . -.. / -.. . . .--. . .-. --..-- / -- --- .-. . / -.-. .- .-. . ..-. ..- .-.. / - .... --- ..- --. .... - / - .... .- -. / .... . / -.-. --- ..- .-.. -.. / -- .- -. .- --. . / .- -- .. -.. / .... .. ... / .... . -.-. - .. -.-. / -.-. .. - -.-- / .-.. .. ..-. . ... - -.-- .-.. . .-.-.- / .--- ..- -. --. / .-. . - .-. . .- - . -.. / - --- / -... --- .-.. .-.. .. -. --. . -. --..-- / -. --- - / - --- / . ... -.-. .- .--. . / .... .. ... / .--. .-. --- ..-. . ... ... .. --- -. .- .-.. / .-.. .. ..-. . --..-- / -... ..- - / .. -. ... - . .- -.. / - --- / .- -.. ...- .- -. -.-. . / .. - .-.-.- / -.-. .- .-. .-.. / .--- ..- -. --. / .-- . -. - / --- -. / - --- / -... . -.-. --- -- . / --- -. . / --- ..-. / - .... . / -- --- ... - / .. -. ..-. .-.. ..- . -. - .. .- .-.. / - .... .. -. -.- . .-. ... / --- ..-. / - .... . / - .-- . -. - .. . - .... / -.-. . -. - ..- .-. -.-- .-.-.- / - .... . .-. . / .- .-. . --..-- / --- ..-. / -.-. --- ..- .-. ... . --..-- / -- .- -. -.-- / .-. . .- ... --- -. ... / ..-. --- .-. / .... .. ... / . ...- . -. - ..- .- .-.. / ... ..- -.-. -.-. . ... ... .-.-.- / .. -. / - .... .. ... / -... --- --- -.- --..-- / .... --- .-- . ...- . .-. --..-- / .. -- / .. -. - . .-. . ... - . -.. / .. -. / .... .. ... / -.-. --- -- -- .. - -- . -. - / - --- / - .... . / ..-. --- .-.. .-.. --- .-- .. -. --. / ... -.- .. .-.. .-.. --..-- / .-- .... .. -.-. .... / .- .-.. -- --- ... - / -.-. . .-. - .- .. -. .-.. -.-- / .--. .-.. .- -.-- . -.. / .- / -.- . -.-- / .-. --- .-.. . / .. -. / .... .. ... / .- -.-. -.-. --- -- .--. .-.. .. ... .... -- . -. - ... ---... / -.. . . .--. / .-- --- .-. -.- / .. ... / -. . -.-. . ... ... .- .-. -.-- / - --- / .-- .-. .. -. --. / . ...- . .-. -.-- / .-.. .- ... - / -.. .-. --- .--. / --- ..-. / ...- .- .-.. ..- . / --- ..- - / --- ..-. / -.-- --- ..- .-. / -.-. ..- .-. .-. . -. - / .. -. - . .-.. .-.. . -.-. - ..- .- .-.. / -.-. .- .--. .- -.-. .. - -.-- .-.-.- / .-- . / -. --- .-- / -.- -. --- .-- / ..-. .-. --- -- / -.. . -.-. .- -.. . ... / --- ..-. / .-. . ... . .- .-. -.-. .... / .. -. / -... --- - .... / .--. ... -.-- -.-. .... --- .-.. --- --. -.-- / .- -. -.. / -. . ..- .-. --- ... -.-. .. . -. -.-. . / - .... .- - / - .... . / ... - .- - . / --- ..-. / -- . -. - .- .-.. / ... - .-. .- .. -. / - .... .- - / .- -.-. -.-. --- -- .--. .- -. .. . ... / -.. . . .--. / .-- --- .-. -.- / .. ... / .- .-.. ... --- / -. . -.-. . ... ... .- .-. -.-- / - --- / .. -- .--. .-. --- ...- . / -.-- --- ..- .-. / .- -... .. .-.. .. - .. . ... .-.-.- / -.. . . .--. / .-- --- .-. -.- --..-- / .. -. / --- - .... . .-. / .-- --- .-. -.. ... --..-- / .-- .- ... / . -..- .- -.-. - .-.. -.-- / - .... . / - -.-- .--. . / --- ..-. / . ..-. ..-. --- .-. - / -. . . -.. . -.. / - --- / ... - .- -. -.. / --- ..- - / .. -. / .- / -.-. --- --. -. .. - .. ...- . .-.. -.-- / -.. . -- .- -. -.. .. -. --. / ..-. .. . .-.. -.. / .-.. .. -.- . / .- -.-. .- -.. . -- .. -.-. / .--. ... -.-- -.-. .... .. .- - .-. -.-- / .. -. / - .... . / . .- .-. .-.. -.-- / - .-- . -. - .. . - .... / -.-. . -. - ..- .-. -.--";
    string *input = &msg;
    string* english = new string;
    english = decrypt(input);
    ofstream f;
    f.open("result.txt");
    f << *english << '\n';
    delete english; // return the memory to the operating system.
    f.close();
    system("pause");
    return 0;
}