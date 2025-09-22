#include <iostream>
#include <fstream>

class CSP_sudoku
{

private:
    const int row = 9;
    int grid[9][9];

    bool check_constraint(int row, int col, int value) const
    {
        // Check the row
        for (int j = 0; j < 9; j++)
        {
            if (grid[row][j] == value)
                return false;
        }

        // Check the column
        for (int i = 0; i < 9; i++)
        {
            if (grid[i][col] == value)
                return false;
        }

        // Check the 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i + startRow][j + startCol] == value)
                    return false;
            }
        }

        return true;
    };

public:
    CSP_sudoku()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j] = 0;
            }
        }
    };

    void set_value(int row, int col, int value)
    {
        grid[row][col] = value;
    };
    int get_value(int row, int col) const
    {
        return grid[row][col];
    };

    void display_grid()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void read_data_from_file(const std::string &filename)
    {
        std::ifstream file(filename);
        if (!file)
        {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }
        else
        {

            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < row; ++j)
                {

                    float value;
                    file >> value;
                    set_value(i, j, value);
                }
            }
            file.close();
        }
    }

    bool solve()
    {
        // Iterate over every cell
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == 0)
                { // Find an empty cell
                    // Try numbers from 1 to 9
                    for (int val = 1; val <= 9; val++)
                    {
                        if (check_constraint(i, j, val))
                        {                         // If placing num is valid
                            set_value(i, j, val); // Place the number
                            if (solve())          // Recursively solve the next empty cell
                                return true;
                            set_value(i, j, 0); // Backtrack: reset the cell
                        }
                    }
                    return false; // Once a valid number is placed, exit (like Python’s return)
                }
            }
        }

        return true;
    }

    ~CSP_sudoku() {
        // Destructor logic (if needed)
    };
};