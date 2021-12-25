#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

char check_exist_out(char a[],char& c)     //input là mảng một chiều kí tự chứa một string
{                                          //output là wanrning nếu file đã tồn tại, là NULL nếu file chưa tồn tại
    // Chưa xử lí đầu ra c:     // không hiểu
    ifstream fs(a);
    if (fs.is_open()) {
        fs.close();
        cout <<"Warning: FILENAME already exists. Do you wish to overwrite (y,n)";
        cin>>c;
        return c;
        // retrun 0, 1
    }
    else
    {
        return '\0';
    }
}

bool check_type(string a)       //input là một string 
{                               //output là true nếu là morse, là false nếu là text 
    for( int i=0;i<a.size();i++)
    {
        if(a[i]!='.'&& a[i]!='-' && a[i]!='/'&&a[i]!=' ')
        {
            return false;
        }
    }
    return true;
}

// Input: a character + line mấy
// Output: true or false: có chuyển được hay không?
void check_text(string s)
{
    // Phải check từng dòng, không check cả file được
    // Chuối s đọc vào phải là từng dòng vì chúng ta không biết độ dài của s là bao nhiêu, thậm trí độ dài của file
    // Cách xử lí tốt nhất là check từng kí tự một
    char text[42] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' , 'j', 'k', 'l', 'm', 'n', 'o', 'p' , 'q', 'r', 's', 't',
                'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9', '.', '?', '-', ',', ':', '#'};
    int new_line = 1;
    for( int i=0;i<s.size();i++)
    {
        if(s[i]!=' '&&s[i]!='\n')
        {
            bool check = false;
            for(int j=0;j<42;j++)
            {
                if(s[i]==text[j])
                {
                    check = true;
                    break;
                }
            }
            if(check == false)
            {
                cout<<"Error: Unrecognised character "<<s[i]<<" on line "<<new_line<<endl;
            }
        }
        if(s[i]=='\n')
        {
            new_line++;
        }
    }
    
}

// Tương tự như check_test, xử lí chưa tối ưu
void check_morse(string s)
{
    string morse[42] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.---", "--..", "-----", ".----", "..---", 
                "...---", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "..--..", "-....-", "--..--", "---...", "........"};
    char a[100] = {'\0'};
    int index = 0;
    int new_line =1;
    for( int i=0;i<s.size();i++)
    {
        if(s[i]!=' '&&s[i]!='\n'&&s[i]!='/') 
        {
            a[index] = s[i];
            index++;
        }

        if(s[i]==' '||s[i]=='\n'||s[i]=='/')  
        {
            if(s[i]=='/')continue;
            if(s[i]==' '&&s[i-1]=='/')continue;
            bool check = false;
            a[index] ='\0';
            for(int j=0;j<42;j++)
            {
                if(a==morse[j])
                {
                    check = true;
                    break;
                }
            }
            if(check == false)
            {
                cout<<"Invalid Morse code "<<a<<" on line  "<<new_line<<endl;
            }
            if(s[i]=='\n')
            {
                new_line++;
            }
            index=0;

            int k=0;        // clear  a
            while(a[k]!='\0')
            {
                a[k] = '\0';
                k++;
            }                        
        }

        if(i==s.size()-1)
        {
            bool check = true;
            a[index] ='\0';
            for(int j=0;j<42;j++)
            {
                if(a==morse[j])
                {
                    check = false;
                }
                if(check == false)break;
            }
            if(check == true)
            {
                cout<<"Invalid Morse code "<<a<<" on line  "<<new_line<<endl;
            }
        }
    }
}

int main(int argc,char* argv[])
{
    /*
    dùng data chung do Đại tạo ra: Dictionary.h
    char text[42] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' , 'j', 'k', 'l', 'm', 'n', 'o', 'p' , 'q', 'r', 's', 't',
                'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9', '.', '?', '-', ',', ':', 'E'};
    char morse[42][10] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.---", "--..", "-----", ".----", "..---", 
                "...---", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "..--..", "-....-", "--..--", "---...", "........"};
    */

    string s;
    ifstream fin;
    fin.open(argv[1]);                               //open file
    if(!fin.is_open())  
	{
		cout<<"Error: FILENAME could not be opened.";
        return 0;
	}
    getline( fin, s, '\0');
    cout << s << endl;
    fin.close();                                        //close file

    if(check_type(s))    //check if file morse or text
    {
        check_morse(s);
    }
    else
    {
        check_text(s);
    } 


    


    char test_out;
    test_out = check_exist_out(argv[2], test_out);
    return 0;
}