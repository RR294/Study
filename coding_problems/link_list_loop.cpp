#include <iostream>
#include "link_list.h"


// Mathod 1 : Best solution.
// When fast and slow pointer matches with each other,(loop detected case)
// point slow pointer to head and move both the pointer 1 step at a time.
// if both pointer->next is same then set fast pointer next to NULL.

// p_head : pointer to head or slow pointer which is pointing to head.
// p_fast : pointer to node where loop was detected(or say fast pointer)
void remove_loop(link_list* p_head, link_list* p_fast)
{
    if(p_head == nullptr || p_fast == nullptr)
    {
        return;
    }

    link_list* p_ptr1 = p_head;
    link_list* p_ptr2 = p_fast;

    // Corner case ...
    // this check is needed when slow
    // and fast both meet at the head of the LL
    // eg: 1->2->3->4->5 and then
    // 5->next = 1 i.e the head of the LL
    if (p_ptr1 == p_ptr2)   // CORNER CASE
    {
        while (p_ptr2->next != p_ptr1)
        {
            p_ptr2 = p_ptr2->next;
        }
    }
    else
    {
        while (p_ptr1->next != p_ptr2->next)
        {
            p_ptr1 = p_ptr1->next;
            p_ptr2 = p_ptr2->next;
        }
    }

    std::cout << "PTR2 node val : " << p_ptr2->val << "\n";
    p_ptr2->next = nullptr;
}


// Method 2 : Better solution.
// Count no. of elements in the loop, say k.
// Take first pointer pointing to head node.
// Take second pointer pointing to head + kth node.
// iterate both pointer by one step and keep checking if they matches.
// also keep track of previous of second pointer, so it can be used to set next to null.

void remove_loop_using_loop_cnt(link_list* p_head, link_list* p_loop_node)
{
    if(p_head == nullptr || p_loop_node == nullptr)
    {
        return;
    }

    // count elements in the loop.
    int loop_cnt{1};
    link_list* p_ptr2 = p_loop_node;
    while(p_ptr2->next != nullptr && p_ptr2->next != p_loop_node)
    {
        p_ptr2 = p_ptr2->next;
        ++loop_cnt;
    }

    // set ptr2 to head+loop_cnt node.
    p_ptr2 = p_head;
    while(loop_cnt > 0)
    {
        p_ptr2 = p_ptr2->next;
        --loop_cnt;
    }

    // pointer 1 is pointing to head.
    // increase both pointer 1 at a time,
    // if they are pointing to same node then found the loop node.
    link_list* p_ptr1 = p_head;
    link_list* p_prev = p_ptr2;
    while(p_ptr1 != p_ptr2)
    {
        p_prev = p_ptr2;
        p_ptr1 = p_ptr1->next;
        p_ptr2 = p_ptr2->next;
    }

    std::cout << "LAST linked list node val : " << p_prev->val << "\n";
    p_prev->next = nullptr;

}

// Method 3 : for each node from head, iterate each node in the loop
// and compare them, if they matches then end found.
//
// PROBLEM : loop node will be iterated many times.

// Function to remove loop in the given linked linst.
// p_head : pointer to head node of linked list.
// p_loop_node : pinter to any loop node in the linked list.
void remove_loop_bruteforce(link_list* p_head, link_list* p_loop_node)
{
    if(p_head == nullptr || p_loop_node == nullptr)
    {
        return;
    }

    link_list* p_first = p_head;
    

    while(p_first != nullptr)
    {
        link_list* p_sec = p_loop_node;

        // iterate loop node until it completes on circle or
        // matches with head traverse node.
        while(p_sec->next != p_loop_node && p_sec->next != p_first)
        {
            p_sec = p_sec->next;
        }

        // if loop node next points to head traverse node then
        // set it's next to NULL.
        if(p_sec->next == p_first)
        {
            std::cout << "Last node val : " << p_sec->val << "\n";
            p_sec->next = nullptr;
            return;
        }

        // Move head traverse pointer.
        p_first = p_first->next;
    }

}

// [IN] p_head : pointer to head node of the linked list.
// true - loop detected in the given linked list.
// false - there is no loop in the given linked list.
bool loop_detected(link_list* p_head)
{
    if(p_head == nullptr)
    {
        return false;
    }

    if(p_head->next == p_head)
    {
        return true;
    }

    link_list* p_slow = p_head;
    link_list* p_fast = p_head;

    while(p_slow != nullptr && p_fast != nullptr && p_fast->next != nullptr)
    {
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;

        if(p_slow == p_fast)
        {
            remove_loop(p_head, p_slow);

            //remove_loop_using_loop_cnt(p_head, p_slow);
            //remove_loop_bruteforce(p_head, p_slow);

            //std::cout << "both are pointing to : " << p_slow->val << "\n";
            return true;
        }
    }

    return false;
}



int main()
{
    link_list* p_head = new link_list(1);
    p_head->insert(2);
    p_head->insert(3);
    p_head->insert(4);
    p_head->insert(5);

    // create link explicitly.
    //std::cout << "Third node value : " << p_head->get_node(2)->val << "\n";
    //std::cout << "Fifth node value : " << p_head->get_node(4)->val << "\n";

    link_list* p_third = p_head->get_node(2);
    link_list* p_fifth = p_head->get_node(4);
    if(p_third != nullptr && p_fifth != nullptr)
    {
        p_fifth->next = p_head;
    }


    bool is_loop = loop_detected(p_head);
    std::cout << "Linked list has loop : " << is_loop << "\n";

    return 0;
}

// source : https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
// source : https://www.youtube.com/watch?v=_BG9rjkAXj8