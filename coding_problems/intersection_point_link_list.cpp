#include <iostream>
#include"link_list.h"

// two linked list joins at some random point, find the intersected node.


// Method 1 : 
// count the length of both the linked list.
// calculate the difference of length.
// take pointer pointing to head of longer linked list and traverse by difference val.
// now take second pointer pointing to smalled linked list head.
// advance both the pointer until their next node address is same.
// Time complexity O(m+n).

link_list *find_intersected_node(link_list *p_first, link_list *p_sec)
{
    if (p_first == nullptr || p_sec == nullptr)
    {
        return nullptr;
    }

    auto first_len(p_first->length());
    auto sec_len(p_sec->length());

    // Find length of both linked list.
    // move larger linked list head pointer by offset value.
    if (first_len > sec_len)
    {
        auto diff = first_len - sec_len;
        while (diff-- > 0)
        {
            p_first = p_first->next;
        }
    }
    else
    {
        auto diff = sec_len - first_len;
        while (diff-- > 0)
        {
            p_sec = p_sec->next;
        }
    }

    // now both linked list has same distance from intersection point.
    // so traverse till they find intersection point.
    while (p_first->next != p_sec->next)
    {
        p_first = p_first->next;
        p_sec = p_sec->next;
    }

    if (p_first->next == p_sec->next)
    {
        return p_first->next;
    }

    return nullptr;
}

// Method 2(Simply use two loops) 
// Use 2 nested for loops.
// Time complexity : O(M * N).

// Method 3(Mark Visited Nodes) 
// This solution requires modifications to basic linked list data structure. 
// Time Complexity : O(m+n)

int main()
{
    link_list* p_head = new link_list(10);
    p_head->insert(20);
    p_head->insert(30);
    p_head->insert(40);
    p_head->insert(50);
    p_head->insert(60);

    p_head->print();

    link_list* p_sec = new link_list(100);
    p_sec->insert(200);

    p_sec->get_node(1)->next = p_head->get_node(4);

    p_sec->print();

    link_list* p_common = find_intersected_node(p_head, p_sec);

    if (p_common != nullptr)
    {
        std::cout << "Common node val is : " << p_common->val << "\n";
    }

    return 0;
}