// Program to check if given tree is Binary tree or not ???
// Assuming all the data value is interger and duplicate is not allowed in the tree.

// Time Complexity : O(N) : As each node will be traversed once.

#include <iostream>

class node
{
    public:
    int val;
    node* left;
    node* right;

    node(int new_val):val(new_val),left(NULL),right(NULL){}
    bool insert_node(node* n);
};

bool node::insert_node(node* new_node)
{
    if(new_node == NULL)
        return false;

    if(new_node->val < val)
    {
        if(left == NULL)
        {
            left = new_node;
            return true;
        }

        return left->insert_node(new_node);
    }

    if(new_node->val > val)
    {
        if(right == NULL)
        {
            right = new_node;
            return true;
        }

        return right->insert_node(new_node);
    }

    std::cout << "duplicate found : " << new_node->val << std::endl;
    return false;
} 

bool is_valid_sbtree(node* ch_node, int min, int max)
{
    if(ch_node == NULL)
    {
        return true;
    }

    if(ch_node->val <= min || ch_node->val >= max)
        return false;

    return is_valid_sbtree(ch_node->left, min, ch_node->val) &&
        is_valid_sbtree(ch_node->right, ch_node->val, max);
}

bool is_valid_btree(node* ch_node)
{
    return is_valid_sbtree(ch_node, INT32_MIN, INT32_MAX);
}



int main()
{ 
    node root(5);
    node n1(2);
    node n2(7);
    node n3(1);
    node n4(3);
    node n5(6);
    node n6(8);

    // TEST 1: should return false.
    //root.left = &n5;
    //root.right = &n2;

    // TEST 2 : Should return true.
    root.insert_node(&n1);
    root.insert_node(&n2);
    root.insert_node(&n3);
    root.insert_node(&n4);
    root.insert_node(&n5);
    root.insert_node(&n6);

    std::cout << "BTREE is Valid : " << is_valid_btree(&root) << std::endl;

    return 0;
}