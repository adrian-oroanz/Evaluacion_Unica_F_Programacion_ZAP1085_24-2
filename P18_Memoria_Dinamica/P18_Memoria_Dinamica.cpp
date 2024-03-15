// P18_Memoria_Dinamica.cpp
// Adrian Orozco Anzures
// Uso de memoria dinamica para matrices
//

#include <iostream>
#include <locale>
#include <vector>
#include <random>
#include <algorithm>


void read_number(int32_t&, std::string);
void fixed_matrix_task(void);
void dynamic_matrix_task(void);
void random_matrix_fill(int32_t**, int32_t, int32_t);
void manual_matrix_fill(int32_t**, int32_t, int32_t);


int main(void)
{
    std::locale::global(std::locale("en_MX.UTF-8"));

    fixed_matrix_task();
    dynamic_matrix_task();

    return 0;
}


void fixed_matrix_task(void)
{
    int32_t fixed_matrix[2][3]{};

    std::cout << "Ingrese valores para la matriz 2x3:\n\n";

    // Prompts the user to fill every cell of the matrix.
    for (int32_t i = 0; i < 2; i++)
    {
        for (int32_t ii = 0; ii < 3; ii++)
        {
			std::string in_text = "";

			in_text += '[';
			in_text += (i + '0');
			in_text += ',';
			in_text += (ii + '0');
			in_text += "] = ";

			read_number(fixed_matrix[i][ii], in_text);
		}

        std::cout << std::endl;
	}

    std::cout << std::endl;
}

void dynamic_matrix_task(void)
{
    int32_t cols = 0,
            rows = 0;

    read_number(rows, "Ingresa la primera dimension de la matriz (m): ");
    read_number(cols, "Ingreas la segunda dimension de la matriz (n): ");

    std::cout << std::endl;

    // Memory allocation of first dimension.
    int32_t** dynamic_matrix = new int32_t*[rows];

    // Memory allocation of each row (2nd dimension).
    for (int32_t i = 0; i < rows; i++)
        dynamic_matrix[i] = new int32_t[cols];

    if (rows > 3 || cols > 3)
		random_matrix_fill(dynamic_matrix, rows, cols);
	else
		manual_matrix_fill(dynamic_matrix, rows, cols);

    // Free the memory of the multidimensional array.
    for (int32_t i = 0; i < rows; i++)
		delete[] dynamic_matrix[i];

    delete[] dynamic_matrix;
}

void manual_matrix_fill(int32_t** _Matrix, int32_t _Rows, int32_t _Cols)
{
    // Prompts the user to fill every cell of the matrix.
    for (int32_t i = 0; i < _Rows; i++)
    {
        for (int32_t ii = 0; ii < _Cols; ii++)
        {
            std::string in_text = "";

            in_text += '[';
            in_text += (i + '0');
            in_text += ',';
            in_text += (ii + '0');
            in_text += "] = ";

            read_number(_Matrix[i][ii], in_text);
        }

        std::cout << std::endl;
    }
}

void random_matrix_fill(int32_t** _Matrix, int32_t _Rows, int32_t _Cols)
{
    size_t matrix_size = _Rows * _Cols;

    // Stores all the indices of the matrix to shuffle them later.
    std::vector<int32_t> indices(matrix_size);

    for (int32_t i = 0; i < matrix_size; i++)
        indices[i] = i;

    // These are the random device and generator engines for pseudo random.
    // Straight up witchcraft from the C++ developers.
    std::random_device device;
    std::mt19937 generator(device());

    // Literally shuffles all the stored indices in a random order.
    std::shuffle(indices.begin(), indices.end(), generator);

    // Assigns a random number from 1 to 100 on a random index.
    // Using indices arithmetic to get the row and column index.
    for (int32_t i = 0; i < matrix_size; i++)
    {
        int32_t row_index = indices[i] / _Cols,
				col_index = indices[i] % _Cols;

		_Matrix[row_index][col_index] = (generator() % 100) + 1;
    }

    // Prints the matrix.
    for (int32_t i = 0; i < _Rows; i++)
    {
        for (int32_t ii = 0; ii < _Cols; ii++)
        {
            std::cout << "[" << i << ", " << ii << "]: " << _Matrix[i][ii];
            std::cout << '\n';
        }
        
        std::cout << std::endl;
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
