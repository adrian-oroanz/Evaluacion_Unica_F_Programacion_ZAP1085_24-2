// P15_Batalla_Pokemon.cpp
// Adrian Orozco Anzures
// Simulador de una batalla de pokemon en consola
//

#include <iostream>
#include <locale>
#include <string>
#include <random>
#include "mokepon.h"


typedef char char8_t;


mokepon player, opponent;
bool    is_round_over = false;


void read_mokepon_name(void);
void show_main_menu(void);
void show_battle_menu(void);
void show_attacks_menu(void);
void show_special_menu(void);
void show_round_result(void);
void finish_round(void);


int32_t main(void)
{
    std::locale::global(std::locale("es_MX.UTF-8"));

    std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
    std::wcout << L"Ingresa el nombre de tu pokemón: ";

    std::getline(std::wcin, player.name);

    show_main_menu();

    std::system("pause");

    return 0;
}


/*
Reads input from the user and assigns it to the "player_name" variable.
*/
void read_mokepon_name(void)
{
    std::system("cls");

    player.name.clear();

    std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
    std::wcout << L"Ingresa el nombre de tu pokemón: ";

    std::wcin.clear();
    std::wcin.ignore(1i64, '\n');

    std::getline(std::wcin, player.name);
}

/*
It's like a title screen or something.
*/
void show_main_menu(void)
{
    const char8_t EXIT_CASE = 'C';
    char8_t option = '\0';

    while (true)
    {
        system("cls");

        std::wcout << L"-= BATALLA POKEMÓN =-\n\n";

        if (!player.is_alive())
        {
            std::wcout << L"* GAME OVER *\n\n";
            return;
        }

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
        case EXIT_CASE:
            return;
        default:
            break;
        }
    }
}

/*
Here is where the mokepon battle takes place.
*/
void show_battle_menu(void)
{
    const char8_t EXIT_CASE = 'C';
    char8_t option = '\0';

    if (!opponent.is_alive())
        opponent = mokepon(player);

    while (true)
    {
        system("cls");

        std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"* " << player.name << L" --- HP: " << player.get_health_points() << L" ~ ATT: " << player.get_attack_points() << L" ~ DEF: " << player.get_defense_points() << " ~ " << mokepon::element_to_string(player.type) << L"\n";
        std::wcout << L"* " << opponent.name << L" --- HP: " << opponent.get_health_points() << L" ~ ATT: " << opponent.get_attack_points() << L" ~ DEF: " << opponent.get_defense_points() << " ~ " << mokepon::element_to_string(opponent.type) << L"\n\n";
        std::wcout << L"Menú de opciones:\n\n[A] Atacar\n[B] Especial\n[C] Huir\n";
        std::wcout << L"\nIngresa una opción: ";

        option = std::cin.get();
        option = std::toupper(option);

        if (option == EXIT_CASE)
			return;

        if (option == 'A')
            show_attacks_menu();
        else if (option == 'B')
            show_special_menu();
        else
            continue;

        if (is_round_over)
            show_round_result();

        if (!player.is_alive() || !opponent.is_alive())
			break;
    }
}

/*
Lists the attacks that the player can use.
*/
void show_attacks_menu(void)
{
    const char8_t EXIT_CASE = '0';
    char8_t option = '\0';

    while (true)
    {
        std::system("cls");

        std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"Lista de ataques:\n\n";

        for (uint16_t i = 0; i < mokepon::MAX_ATTACKS; ++i)
        {
            mokepon::attack& attack = player.get_attack(i);

            std::wcout << L"[" << i + 1 << L"] " << attack.name << L" ~ ATT: " << attack.damage << L" ~ " << mokepon::element_to_string(attack.type) << L"\n";
        }

        std::wcout << L"[0] Regresar\n";
        std::wcout << L"\nIngresa una opción: ";

		option = std::cin.get();
		option = std::toupper(option);

        if (option == EXIT_CASE)
			return;

        uint16_t attack_index = (option - '0') - 1;

        if (attack_index < mokepon::MAX_ATTACKS)
        {
            uint16_t damage = player.use_attack(opponent, attack_index);

            std::wcout << std::endl;
            std::wcout << L"* " << player.name << L" ataca a " << opponent.name << L" con " << player.get_attack(attack_index).name << L"...\n";
            std::wcout << L"* ¡" << opponent.name << L" recibe " << damage << L" puntos de daño!\n\n";

            std::system("pause");

            break;
        }
    }

    finish_round();
}

/*
Lists the special moves that the player can use.
*/
void show_special_menu(void)
{
    int16_t points = 0;
    char8_t option = '\0';
    bool option_is_valid = false;

    while (!option_is_valid)
    {
		std::system("cls");

		std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
        std::wcout << L"Menú de opciones:\n\n[A] Enfurecer (+ATT)\n[B] Defender (+DEF)\n[C] Curar\n[D] Regresar\n";
        std::wcout << L"\nIngresa una opción: ";

        option = std::cin.get();
        option = std::toupper(option);
        option_is_valid = true;

        switch (option)
        {
        case 'A':
            points = player.use_enrage();

            std::wcout << std::endl;
            std::wcout << L"* " << player.name << L" concentra toda su ira en el enemigo...\n";
            std::wcout << L"* ¡" << player.name << L" aumenta su ataque en " << points << L" puntos!\n\n";

			break;
        case 'B':
            points = player.use_defend();

            std::wcout << std::endl;
            std::wcout << L"* " << player.name << L" se prepara para el siguiente ataque...\n";
            std::wcout << L"* ¡" << player.name << L" aumenta su defensa en " << points << L" puntos!\n\n";

            break;
        case 'C':
            points = player.use_heal();

            std::wcout << std::endl;
            std::wcout << L"* " << player.name << L" se rehusa a perder...\n";
            std::wcout << L"* ¡" << player.name << L" recupera " << points << L" puntos de salud!\n\n";

            break;
        case 'D':
            // Just return to the previous menu.
			return;
        default:
            option_is_valid = false;
            break;
        }
    }

    std::system("pause");

    finish_round();
}

void show_round_result(void)
{
    is_round_over = false;

    std::system("cls");

    std::wcout << L"-= BATALLA POKEMÓN =-\n\n";
    std::wcout << L"* " << player.name << L" --- HP: " << player.get_health_points() << L" ~ ATT: " << player.get_attack_points() << L" ~ DEF: " << player.get_defense_points() << " ~ " << mokepon::element_to_string(player.type) << L"\n";
    std::wcout << L"* " << opponent.name << L" --- HP: " << opponent.get_health_points() << L" ~ ATT: " << opponent.get_attack_points() << L" ~ DEF: " << opponent.get_defense_points() << " ~ " << mokepon::element_to_string(opponent.type) << L"\n\n";

    if (!player.is_alive())
    {
		std::wcout << L"¡" << player.name << L" ha sido derrotado!\n";
		std::wcout << L"¡" << opponent.name << L" ha ganado la batalla!\n\n";
	}
    else if (!opponent.is_alive())
    {
		std::wcout << L"¡" << opponent.name << L" ha sido derrotado!\n";
		std::wcout << L"¡" << player.name << L" ha ganado la batalla!\n\n";
	}
    else
    {
		std::wcout << L"¡La batalla continúa!\n\n";
	}

    std::system("pause");
}

/*
Here is where the opponent attacks the player and the round ends.
Attacks are regenerated after the round ends.
*/
void finish_round(void)
{
    is_round_over = true;

    player.generate_attacks();

    if (!opponent.is_alive())
        return;

    std::random_device device;
    std::mt19937 random(device());

    uint16_t attack_index = random() % mokepon::MAX_ATTACKS;
    uint16_t damage = opponent.use_attack(player, attack_index);

    std::wcout << std::endl;
    std::wcout << L"* " << opponent.name << L" ataca a " << player.name << L" con " << opponent.get_attack(attack_index).name << L"...\n";
    std::wcout << L"* ¡" << player.name << L" recibe " << damage << L" puntos de daño!\n\n";

    std::system("pause");

    opponent.generate_attacks();
}
