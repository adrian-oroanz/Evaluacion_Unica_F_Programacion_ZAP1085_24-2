// P18_Memoria_Dinamica.cpp
// Adrian Orozco Anzures
//

#include <iostream>
#include <locale>
#include <vector>
#include <random>
#include <algorithm>


void read_number(int32_t&, std::string);
void fixed_matrix_task(void);
void dynamic_matrix_task(void);
void fill_matrix(int32_t**, int32_t, int32_t);


int main(void)
{
    std::locale::global(std::locale("en_MX.UTF-8"));

    fixed_matrix_task();
    dynamic_matrix_task();

    return 0;
}


void fixed_matrix_task(void)
{
    int32_t fixed_matrix[2][3];

    std::cout << "Ingrese valores para la matriz 2x3:\n\n";

    for (int32_t i = 0; i < 2; i++)
    {
        for (int32_t ii = 0; ii < 3; ii++)
        {
            // This is the text that will be showed when asking the user
            // for a number at the [i][ii] position in the matrix.
            std::string in_text = "";

            in_text += '[';
            in_text += (i + '0');
            in_text += ',';
            in_text += (ii + '0');
            in_text += "] = ";

            read_number(fixed_matrix[i][ii], in_text);
        }
    }

    std::cout << std::endl;
}

void dynamic_matrix_task(void)
{
    int32_t m = 0,
            n = 0;

    read_number(n, "Ingresa la primera dimension de la matriz (n): ");
    read_number(m, "Ingreas la segunda dimension de la matriz (m): ");

    // Memory allocation of first dimension.
    int32_t** dynamic_matrix = new int32_t*[n];

    // Memory allocation of each row (2nd dimension).
    for (int32_t i = 0; i < m; i++)
        dynamic_matrix[i] = new int32_t[m];

    if (n <= 3 || m <= 3)
    {
        // TODO: Finish the matrix filling by the user.
    }
    else fill_matrix(dynamic_matrix, n, m);

    // Free the memory on each row.
    for (int32_t i = 0; i < m; i++)
        delete[] dynamic_matrix[i];

    // Free the memory of the matrix.
    delete[] dynamic_matrix;
}

void fill_matrix(int32_t** _Matrix, int32_t _M, int32_t _N)
{
    size_t matrix_size = _M * _N;

    // Stores all the indices of the matrix to shuffle them later.
    std::vector<int32_t> indices(matrix_size);

    for (int32_t i = 0; i < matrix_size; i++)
        indices[i] = i;

    // These are the random device and generator engines for pseudo random.
    std::random_device device;
    std::mt19937 generator(device());

    // Literally shuffles all the stored indices in a random order.
    std::shuffle(indices.begin(), indices.end(), generator);

    for (int32_t i = 0; i < matrix_size; i++)
    {
        int32_t rowIndex = indices[i] / _N;
        int32_t colIndex = indices[i] % _N;

        _Matrix[rowIndex][colIndex] = generator();
    }

    for (int32_t i = 0; i < _M; i++)
    {
        for (int32_t ii = 0; ii < _N; ii++)
        {
            std::cout << '[' << i << ',' << ii << "]: " << _Matrix[i][ii];
            std::cout << std::endl;
        }
    }
}

/*
Reads an int32 sized number from the standard input and validates that
the number can be used as an int32.
*/
void read_number(int32_t& _Number, std::string _InText)
{
    std::cout << _InText;

    // Calling the ! operator returns whether or not the read was successfull.
    while (!(std::cin >> _Number))
    {
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        std::cout << _InText;
    }
}
