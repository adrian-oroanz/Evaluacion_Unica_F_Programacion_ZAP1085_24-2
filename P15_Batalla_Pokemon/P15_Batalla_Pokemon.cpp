// P15_Batalla_Pokemon.cpp
// Adrian Orozco Anzures
// Simulador de una batalla de pokemon en consola
//

#include <iostream>
#include <locale>
#include <string>
#include <ctime>
#include "mokepon.h"


typedef char char8_t;


std::wstring player_name;


void read_mokepon_name(void);
void show_main_menu(void);
void show_battle_menu(void);


int32_t main(void)
{
    std::locale::global(std::locale("es_MX.UTF-8"));

    read_mokepon_name();
    show_main_menu();

    return 0;
}


/*
Reads input from the user and assigns it to the "player_name" variable.
*/
void read_mokepon_name(void)
{
    system("cls");

    player_name.clear();

    std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
    std::wcout << L"Ingresa el nombre de tu pokemón: ";

    std::wcin.clear();
    std::wcin.ignore(1i64, '\n');

    std::getline(std::wcin, player_name);
}

/*
The main menu is the actual entry point of the program.
The user can select 4 options to interact with the system.
*/
void show_main_menu(void)
{
    const char8_t EXIT_CASE = 'C';
    char8_t option = '\0';

    while (option != EXIT_CASE)
    {
        system("cls");

        std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"Menú de opciones:\n\n[A] Comenzar\n[B] Renombrar\n[C] Salir\n";
        std::wcout << L"\nIngresa una opción: ";

        option = std::cin.get();
        option = std::toupper(option);

        switch (option)
        {
        case 'A':
            show_battle_menu();
            break;
        case 'B':
            read_mokepon_name();
            break;
        default:
            break;
        }
    }
}

void show_battle_menu(void)
{
    mokepon player(player_name),
            opponent;

    const char8_t EXIT_CASE = 'D';
    char8_t option = '\0';

    while (option != EXIT_CASE)
    {
        system("cls");

        std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"Menú de opciones:\n\n[A] Atacar\n[B] Defender\n[C] Curar\n[D] Huir\n";

        option = std::cin.get();
        option = std::toupper(option);

        switch (option)
        {
        case 'A':
            break;
        case 'B':
            break;
        case 'C':
            break;
        default:
            break;
        }
    }
}
