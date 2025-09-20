
#include <iostream>
#include "sudoku.hpp"

int main() {
  CSP_sudoku sudoku = CSP_sudoku();
  sudoku.read_data_from_file("data.txt");
  sudoku.solve();
  sudoku.display_grid();

}
