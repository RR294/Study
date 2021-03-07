#include <iostream>
#include <cstring>

#define INT_MAX 65535


// THIS IS SIMPLE SOLUTION WITH TIME COMPLEXITY EXPONENTIAL.
// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
   // base case
   if (V == 0) return 0;
 
   // Initialize result, say it is INT_MAX.
   int res = 9999;
 
   // Try every coin that has smaller value than V
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         int sub_res = minCoins(coins, m, V-coins[i]);
 
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         if (sub_res != 9999 && sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
}


// m is size of coins array (number of different coins)
int minCoins_dp(int coins[], int m, int V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    int table[V+1];
 
    // Base case (If given value V is 0)
    table[0] = 0;
 
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
 
    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
   
      if(table[V]==INT_MAX)
        return -1;
   
    return table[V];
}

int main()
{
	int coins[4] = {1,5,10,25};
	int amt;
	std::cout << "Enter the amount : ";
	std::cin >> amt;
	

	//std::cout << "Min coins : " << min_count(amt, coins, 4, cache)  << std::endl;

	std::cout << "Min coins : " << minCoins_dp(coins, 4, amt) << std::endl;
	return 0;
}

// youtube source : https://www.youtube.com/watch?v=NJuKJ8sasGk
// source : https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
