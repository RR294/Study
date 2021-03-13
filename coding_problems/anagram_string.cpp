#include <iostream>
// An anagram of a string is another string that contains
// the same characters, only the order of characters can be different.

// characters can be anything, so to make the problem simpler,
// this program considers input characters are between 'a' to 'z' only. (including both)

// Time Complexity : O(m+n) , where m and n are length of strings and checking arrays for count is constant.

bool is_str_anagram(std::string f_str, std::string s_str)
{
    int f_len(f_str.length());
    int s_len(s_str.length());

    if(f_len != s_len)
        return false;

    // take a array to count the occurance of characters.
    int ch_cnt_arr[26] = {0};

    // For the first string increment the character count.
    for(char& ch : f_str)
    {
        ++ch_cnt_arr[ch - 'a'];
    }
    // For the second string decrement the character count.
    for(char& ch : s_str)
    {
        --ch_cnt_arr[ch - 'a'];
    }

    for(int ind(0); ind < 26; ++ind)
    {
        if(ch_cnt_arr[ind] > 0)
        {
            std::cout << "ch = " << 'a' + ch_cnt_arr[ind] << " count = " << ch_cnt_arr[ind] << std::endl;
            return false;
        }
    }
    return true;
}

int main()
{
    bool is_anagram = is_str_anagram("aabcdefghijklmnopqrstuvwxyzz", "zzyxwvutsrqpomnlkjihgfeabcda");
    std::string res = is_anagram ? "TRUE" : "FALSE";

    std::cout << "Given strings are anagram : " << res << "\n\n";
    return 0;
}