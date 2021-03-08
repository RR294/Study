// C++ Program to implement 
// concatenate string with all unique characters from given sub string list.

// Time Complexity: O(2^N) ??
// Auxiliary Space: O(N * 2^N) == O(N)


#include <bits/stdc++.h> 
using namespace std;

// Function to check if all the
// string characters are unique
bool check(string in_str)
{

    set<char> uni_char_set;

    // Check for repetation in
    // characters
    for (auto ch : in_str)
    {
        if (uni_char_set.count(ch))
            return false;

        uni_char_set.insert(ch);
    }

    return true;
}

// Funcyion to generate all possible strings with unique characters
// from the given array
vector<string> build_unique_string_list(vector<string> &in_str_vec,
                      int ind)
{

    // Base case
    if (ind == in_str_vec.size())
        return {""};

    // Consider every string as
    // a starting substring and
    // store the generated string
    vector<string> unique_str_vec = build_unique_string_list(in_str_vec, ind + 1);

    vector<string> final_unique_str_vec(unique_str_vec.begin(),
                                        unique_str_vec.end());

    // Add current string to result of
    // other strings and check if
    // characters are unique or not
    for (auto str : unique_str_vec)
    {
        string new_str = str + in_str_vec[ind];
        if (check(new_str))
            final_unique_str_vec.push_back(new_str);
    }

    return final_unique_str_vec;
}

// Function to find the maximum 
// possible length of a string 
int maxLength(vector<string>& arr) 
{ 
    vector<string> unique_str_vec = build_unique_string_list(arr, 0); 
 
    int len = 0; 
 
    // Return max length possible 
    for (auto str : unique_str_vec) { 
        //std::cout << "String : " << i << std::endl;
        len = len > str.size() 
                ? len 
                : str.size(); 
    } 
 
    // Return the answer 
    return len; 
} 
 
// Driver Code 
int main() 
{ 
    vector<string> s; 
    s.push_back("abcdefghijklmnopqrstuvwxyz");
    s.push_back("cd");
    s.push_back("ab"); 

    int max_len = maxLength(s);
    cout << "\nString with max length : " << max_len << std::endl;
 
    return 0; 
} 

//source : https://www.geeksforgeeks.org/maximize-length-of-the-string-by-concatenating-characters-from-an-array-of-strings/

// explanation : go till last sub-string ...
// add empty string '' in the string list first (VERY IMPORTANT)
// now each function will return and will append it's current substring with all the string in the list only
// if concatenation have n duplicate character then returns updated string list to previous caller.