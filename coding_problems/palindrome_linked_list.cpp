#include <iostream>
#include "link_list.h"

// First thought was ....
// Reverse linked list and compare it with original but it will require extra space of O(n).


// Second thought wa ....

// As from middle of LL, left part should be comparedin the reverse direction,
// initial thought was, while traversing LL with slow & fast pointer,
// keep inserting left part element in the stack.
// once fast pointer reaches to an end, start comparing second part from middle with stack element ...
// BUT that solution requires extra space to insert element in the stack.




// Third optimized approach...

// Time complexity = O(n)
// Space complexity = O(1)

bool is_palindrome_linf_list(link_list* p_head)
{
    if(p_head == nullptr || p_head->next == nullptr)
    {
        return true;
    }

    link_list* p_cur = p_head;
    link_list* p_slow = p_head;
    link_list* p_fast = p_head;
    link_list* p_prev = nullptr;

    // iterate till fast pointer reaches to an end.
    // while iterating, keep reversing first part.
    // adjust slow pointer to first element of second part.
    

    while(p_fast != nullptr && p_fast->next != nullptr)
    {
        p_cur = p_slow;
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;

        // reverse first part 
        p_cur->next = p_prev;

        // update previous to current.
        p_prev = p_cur;
    }

    // for odd element count, increment slow pointer before comparison.
    if(p_fast != nullptr)
    {
        p_slow = p_slow->next;
    }

    std::cout << "Left part : ";
    p_prev->print();

    std::cout << "Right part : ";
    p_slow->print();
    

    while(p_prev != nullptr && p_slow != nullptr)
    {
        if(p_prev->val != p_slow->val)
        {
            return false;
        }

        p_slow = p_slow->next;
        p_prev = p_prev->next;
    }

    return true;
}

int main()
{
    link_list* p_head = new link_list(1);
    p_head->insert(2);
    //p_head->insert(3);
    p_head->insert(2);
    p_head->insert(1);

    p_head->print();

    if(is_palindrome_linf_list(p_head))
    {
        std::cout << "Given linked list is palindrome \n";
    }
    else
    {
        std::cout << "Not Palindrome \n";
    }

    return 0;
}

// source : https://www.youtube.com/watch?v=H3J-HoGCVXs&list=WL&index=83