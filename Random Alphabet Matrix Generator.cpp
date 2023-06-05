#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));  // Seed the random number generator with the current time!

    int rows,cols;

    std::cout << "Enter rows and columns(eg:10 or 10x10) or press inter: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.empty())  // Check if the user did not enter any value
    {
        rows = 10;
        cols = 10;
    }
    else
    {
        std::stringstream ss(input);
        char separator;
        ss >> rows;

        if (!ss)  // Check if the input is valid
        {
            std::cout << "Invalid input.\n";
            return 1;
        }

        if (ss >> separator >> cols && separator == 'x')
        {
            // Both rows and cols are entered correctly
        }
        else
        {
            cols = rows;  // Set cols equal to rows
        }
    }

    char matrix[rows][cols];

    // Fill the matrix with random alphabets
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int randomNumber = rand() % 26;  // Generate a random number from 0 to 25
            matrix[i][j] = 'a' + randomNumber;  // Map the number to the corresponding alphabet
        }
    }

    // Print the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j > 0)
            {
                std::cout << " | ";
            }
            std::cout << matrix[i][j];
        }
        std::cout << "\n";

        // Print the separator row
        for (int j = 0; j < cols * 4 - 3; j++)
        {
            std::cout << "-";
        }
        std::cout << "\n";
    }

    return 0;
}
