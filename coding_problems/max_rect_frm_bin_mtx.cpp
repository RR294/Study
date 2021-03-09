// Program to find max rectangle from binary matrix formed by 1.

#include <iostream>
// 1 0 1 1 0
// 0 1 1 0 1
// 1 1 1 0 1
// 1 1 1 0 0
// 0 1 1 1 1

// In above matrix , rectangle with mix 1 will be eight 1's.

// Time complexity : O(rows * cols)
// Space complexity : number of columns => O(cols) 
// to optimise space , takemin between rows & cols and sweep accordingly.

// function to find matrix with max value from given row
int get_max_frm_row(int bars[], int bar_cnt)
{
    int max(0);
    int cnt(0);
    int min(9999);

    for(int bar_ind(0); bar_ind < bar_cnt; ++bar_ind)
    {
        if(bars[bar_ind] == 0)
        {
            // on 0 bar height, reset count & min height.
            cnt = 0;
            min = 9999;
        }
        else
        {
            // with each new bar height ...
            // increment bar count and maintain the min height.
            ++cnt;
            if(bars[bar_ind] < min)
            {
                min = bars[bar_ind];
            }
        }

        // after each iteration, calculate max rect &
        // swap if it greater than previous max.
        int tmp = cnt * min;
        if (tmp > max)
        {
            max = tmp;
        }
    }

    

    return max;
}

// Function to max rectangle in binary matrix formed by 1.
int find_max_rect(int mtx[][6], int rows, int cols)
{
    int bar_sum_row[rows];

    // copy first row ...
    for(int col_ind(0); col_ind < cols; ++col_ind)
    {
        bar_sum_row[col_ind] = mtx[0][col_ind];
    }

    int max_rect = get_max_frm_row(bar_sum_row, cols);

    std::cout << "row index 0 max = " << max_rect << std::endl;

    for(int row_ind(1); row_ind < rows; ++row_ind)
    {
        for(int col_ind(0); col_ind < cols; ++col_ind)
        {
            if(mtx[row_ind][col_ind] == 0)
            {
                bar_sum_row[col_ind] = 0;
            }
            else
            {
                bar_sum_row[col_ind] += mtx[row_ind][col_ind];
            }
        }

        int cur_max = get_max_frm_row(bar_sum_row, cols);
        if(cur_max > max_rect)
        {
            max_rect = cur_max;
        }

        std::cout << "row index " << row_ind << " max = " << max_rect << std::endl;
    }

    return max_rect;
}

int main()
{
    int mtx[4][6] = {
        { 1, 0, 0, 1, 1, 1},
        { 1, 0, 1, 1, 0, 1},
        { 0, 1, 1, 1, 1, 1},
        { 0, 0, 1, 1, 1, 1}
    };

    int max_rect = find_max_rect(mtx, 4/*row_cnt*/, 6/*col_cnt*/);
    std::cout << "\nMax rect with 1 is " << max_rect << std::endl;

    return 0;
}

// source : https://www.youtube.com/watch?v=g8bSdXCG-lA