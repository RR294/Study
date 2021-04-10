// Place N Queen on chess board.
#include <iostream>
#include <vector>

// Time Complexity : (Worst time)Exponential.

bool are_cells_under_attack(int occupied_row, int occupied_col, int new_row, int new_col)
{
    // For left->right & going top->bottom digonal ...
    // if both cells row-col result are same then they are under attack.
    if((occupied_row - occupied_col) == (new_row - new_col))
    {
        return true;
    }

    // For left->right & going bottom->top diagonal ...
    // if both cells row+col result are same then they are under attack.
    if((occupied_row + occupied_col) == (new_row + new_col))
    {
        return true;
    }

    // if both cells are in the same row/column then they are under attack.
    if(occupied_row == new_row || occupied_col == new_col)
    {
        return true;
    }

    return false;
}

// class defined to store chess cell value.
class chess_board_cell
{
    public:
    int r;
    int c;

    chess_board_cell(int new_r, int new_c):r(new_r), c(new_c){}
};

// vector to store chess cell positions.
typedef std::vector<chess_board_cell> board_pos;


// Function to check if new cell position is safe with already placed queens.
// true - new queen can be placed safe with already placed queen.
bool is_pos_safe(board_pos& pos, int row, int col)
{
    for(auto& pos_it : pos)
    {
        if(are_cells_under_attack(pos_it.r, pos_it.c, row,col))
        {
            return false;
        }
    }

    return true;
}

// Function to place n queen on chess board safely ...
// pos : to store safe queen positions.
// row_ind : next row in which next queen needs to be placed.
// sqr_max_cnt :size of the chess board, if it is 4 then chess board will be considered as 4*4.
bool place_n_queen(board_pos& pos, int row_ind, int sqr_max_cnt)
{
    // std::cout << "called for row = " << row_ind << "\n";
    if(row_ind == sqr_max_cnt)
    {
        return true;
    }

    for (auto c_ind(0); c_ind < sqr_max_cnt; ++c_ind)
    {
        chess_board_cell cell{row_ind, c_ind};
        if (is_pos_safe(pos, row_ind, c_ind))
        {
            pos.emplace_back(cell);

            // if next queen can't find safe position then
            // remove last queen added and check for the next position.
            if (place_n_queen(pos, row_ind + 1, sqr_max_cnt))
            {
                return true;
            }

            // on failure remove lastly inserted position and check next cell in the row.
            pos.pop_back();
        }
    }

    return false;
}

int main()
{
    board_pos chess_pos;
    place_n_queen(chess_pos,0,6);
    for(auto& it : chess_pos)
    {
        std::cout << it.r << "," << it.c << "\n";
    }
    return 0;
}

//source : https://www.youtube.com/watch?v=xouin83ebxE&list=WL&index=65
