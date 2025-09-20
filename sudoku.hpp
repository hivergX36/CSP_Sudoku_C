#include <iostream>


class CSP_sudoku {


    private:
        int grid[9][9];
        bool is_valid(int row, int col, int value) const;

        void all_different_constaint();


public:
    
    CSP_sudoku();
    
    
    ~CSP_sudoku();

    void print();
    bool solve();
    void set_value(int row, int col, int value){
        grid[row][col] = value;
    };
    int get_value(int row, int col) const {
        return grid[row][col];
    };
    
    void display_grid(){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }



};