// 000_P1_Hablar_Usuario.cpp
// Adrian Orozco Anzures
// Hablar con el usuario usando los metodos de IOStream
//

#include <iostream>
#include <locale>
#include <string>
#include <memory>
#include <unordered_map>
using namespace std;


int main()
{
    // Set the locale to es_MX
    locale::global(locale("es_MX.UTF-8"));

    unique_ptr<string> ptr_str    = make_unique<string>("Hello World!\n");
    unique_ptr<string> ptr_phrase = make_unique<string>("Seek the golden path\n");

    cout << *ptr_str << *ptr_phrase;

    unordered_map<string, string> alumni = {
        {"zap1085", "Adrián"}
    };

    for (pair<const string, string> item: alumni) {
        cout << item.second << " - " << item.first << '\n';
    }

    cout << "áéíóúñÑäëïöü\n";
    cout << endl;

    return 0;
}
