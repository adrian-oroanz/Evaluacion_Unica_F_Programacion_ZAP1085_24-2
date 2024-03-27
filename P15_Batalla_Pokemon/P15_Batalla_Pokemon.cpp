// P15_Batalla_Pokemon.cpp
// Adrian Orozco Anzures
// Simulador de una batalla de pokemon en consola
//

#include <iostream>
#include <locale>
#include <string>
#include "mokepon.h"


typedef char char8_t;


mokepon player, opponent;


void read_mokepon_name(void);
void show_main_menu(void);
void show_battle_menu(void);
void show_attacks_menu(void);
void show_special_menu(void);


int32_t main(void)
{
    std::locale::global(std::locale("es_MX.UTF-8"));

    std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
    std::wcout << L"Ingresa el nombre de tu pokemón: ";

    std::getline(std::wcin, player.name);

    show_main_menu();

    return 0;
}


/*
Reads input from the user and assigns it to the "player_name" variable.
*/
void read_mokepon_name(void)
{
    system("cls");

    player.name.clear();

    std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
    std::wcout << L"Ingresa el nombre de tu pokemón: ";

    std::wcin.clear();
    std::wcin.ignore(1i64, '\n');

    std::getline(std::wcin, player.name);
}

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
    const char8_t EXIT_CASE = 'C';
    char8_t option = '\0';

    if (!opponent.is_alive())
        opponent = mokepon{ player };

    while (option != EXIT_CASE)
    {
        system("cls");

        std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"* " << player.name << L" --- HP: " << player.get_health_points() << L" ~ ATT: " << player.get_attack_points() << L" ~ DEF: " << player.get_defense_points() << L"\n";
        std::wcout << L"* " << opponent.name << L" --- HP: " << opponent.get_health_points() << L" ~ ATT: " << opponent.get_attack_points() << L" ~ DEF: " << opponent.get_defense_points() << L"\n\n";
        std::wcout << L"Menú de opciones:\n\n[A] Atacar\n[B] Especial\n[C] Huir\n";
        std::wcout << L"\nIngresa una opción: ";

        option = std::cin.get();
        option = std::toupper(option);

        switch (option)
        {
        case 'A':
            show_attacks_menu();
            break;
        case 'B':
            show_special_menu();
            break;
        default:
            break;
        }
    }
}

void show_attacks_menu(void)
{
    char8_t option = '\0';

    while (true)
    {
        system("cls");

        std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"Lista de ataques:\n\n";

        for (uint16_t i = 0; i < mokepon::MAX_ATTACKS; ++i)
        {
            mokepon::attack& attack = player.get_attack(i);

            std::wcout << L"[" << i + 1 << L"] " << attack.name << L" ~ " << attack.damage << L" ~ " << mokepon::element_to_string(attack.type) << L"\n";
        }

        std::wcout << L"[0] Regresar\n";
        std::wcout << L"\nIngresa una opción: ";

		option = std::cin.get();
		option = std::toupper(option);

        if (option == '0')
			return;

        uint16_t attack_index = (option - '0') - 1;

        if (attack_index < mokepon::MAX_ATTACKS)
        {
            player.use_attack(opponent, attack_index);
            return;
        }
    }
}

void show_special_menu(void)
{
    char8_t option = '\0';

    while (true)
    {
		system("cls");

		std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"Menú de opciones:\n\n[A] Enfurecer (+ATT)\n[B] Defender (+DEF)\n[C] Curar\n[D] Regresar\n";
        std::wcout << L"\nIngresa una opción: ";

        option = std::cin.get();
        option = std::toupper(option);

        switch (option)
        {
        case 'A':
            player.use_enrage();
			return;
        case 'B':
            player.use_defend();
            return;
        case 'C':
            player.use_heal();
            return;
        case 'D':
			return;
        default:
            break;
        }
    }
}
