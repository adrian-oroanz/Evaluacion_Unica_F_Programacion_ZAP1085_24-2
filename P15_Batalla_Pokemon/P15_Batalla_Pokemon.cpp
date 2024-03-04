// P15_Batalla_Pokemon.cpp
// Adrian Orozco Anzures
// Simulador de una batalla de pokemon en consola
//

#include <iostream>
#include <locale>
#include <string>
#include "mokepon.h"


mokepon player, opponent;


void main_menu(void);
void attack_menu(void);
void special_menu(void);


int32_t main(void)
{
    std::locale::global(std::locale("es_MX.UTF-8"));

    wstring name;

    std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
    std::wcout << L"Ingresa el nombre de tu pokemón: ";

    std::getline(std::wcin, name);

    player.name = name;

    main_menu();

    return 0;
}


void main_menu(void)
{
    int32_t option = '\0';

    while (option != 'D')
    {
        system("cls");

        std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"Menú de opciones:\n\n[A] Atacar\n[B] Especial\n[C] Regenerar\n[D] Huir (Finalizar)\n";
        std::wcout << L"\nIngresa una opción: ";

        option = std::cin.get();
        option = std::toupper(option);

        switch (option)
        {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        default:
            break;
        }
    }
}
