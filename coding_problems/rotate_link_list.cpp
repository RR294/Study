#include <iostream>
#include "link_list.h"

// Rotate link list clock wise by rotate_cnt.
// Method 1 :
// three pointer approach to adjust the next link of the nodes.
// Time Complexity: O(n) where n is the number of nodes in Linked List.
// The code traverses the linked list only once.
//
// Source : https://www.geeksforgeeks.org/rotate-a-linked-list/

link_list* rotate(link_list* p_head, int rotate_cnt)
{
    if(p_head == nullptr || p_head->next == nullptr)
    {
        return p_head;
    }

    link_list* p_sec = p_head;

    // move second pointer to offset value.
    for(int cnt(0); cnt < rotate_cnt-1; ++cnt)
    {
        if(p_sec->next == nullptr)
        {
            return p_head; // ERROR, so head will remain same.
        }
        p_sec = p_sec->next;
    }

    // store new last element pointer.
    link_list* p_last_node = p_sec;

    // store new head.
    link_list* p_new_head = p_sec->next;
    if(p_sec->next == nullptr)
    {
        p_new_head = p_head;
    }

    // advance second pointer till end.
    while(p_sec->next != nullptr)
    {
        p_sec = p_sec->next;
    }

    // join the second pointer next to old_head pointer.
    p_sec->next = p_head;

    // set last element next to nullptr.
    p_last_node->next = nullptr;

    return p_new_head;
}

// Method 2 :
// To rotate a linked list by k,
// we can first make the linked list circular and then moving k-1 steps forward from head node,
// making it null and make kth node as head.

// For implementation , please refer source link.
// Source : https://www.geeksforgeeks.org/rotate-a-linked-list/


int main()
{
    link_list* p_head = new link_list(10);
    p_head->insert(20);
    p_head->insert(30);
    p_head->insert(40);
    p_head->insert(50);
    p_head->insert(60);

    p_head->print();
    std::cout << "\n\n";

    p_head = rotate(p_head, 4);
    p_head->print();

    return 0;
}