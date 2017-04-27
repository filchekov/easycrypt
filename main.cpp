/* autor perfect filchekov@mail.ru
   material received from site: http://www.konvenat.ru/stati/spravochniki/57-prostye-shifry-i-ikh-deshifrovka
*/
#include <iostream>
#include <string>
//#include <Windows.h>

using namespace std;

string crypt_sequence = "klmnoabcde"; /* only ten letter */
string source_string = "hello crypt";

string crypt(const string & source_string){
    string result;
    char digit_to_letters[3], tmp;

    for (auto it = source_string.begin(); it != source_string.end(); it++){
         itoa(*it, digit_to_letters, 10);
         result += digit_to_letters;
         result += " ";
    }

    for (auto it = result.begin(); it != result.end(); it++){
        for (size_t ic = 0; ic < crypt_sequence.size(); ic++){
            itoa(ic, &tmp, 10);

            if (*it == tmp)
                *it = crypt_sequence[ic];
        }
    }

    return result;
}

string encrypt(string source_string){
    char tmp;
    string result, buf;
    int code;

    for (size_t i = 0; i < source_string.size(); i++){
        for (size_t ic = 0; ic < crypt_sequence.size(); ic++){
            if (crypt_sequence[ic] == source_string[i]){
                itoa(ic, &tmp, 10);
                source_string[i] = tmp;
            }
        }
    }

    for (size_t i = 0; i < source_string.size(); i++){
        if (source_string[i] != ' ')
            buf += source_string[i];
        else {
            code = atoi(buf.c_str());
            result += (char)code;
            buf = "";
        }
    }

    return result;
}

int main(int argc, char *argv[]){
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);

    string out = crypt(source_string);

    cout << "crypt: " << out << endl;
    cout << "encrypt: " << encrypt(out) << endl;


    return 0;
}
