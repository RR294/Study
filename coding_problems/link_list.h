
class link_list
{
    public:
    int val;
    link_list* next;

    link_list(int new_val):val(new_val), next(nullptr){}

    void insert(int new_val)
    {
        link_list* p_cur = this;
        while(p_cur->next != nullptr)
        {
            p_cur = p_cur->next;
        }

        p_cur->next = new link_list(new_val);
    }

    void print()
    {
        link_list* p_cur = this;
        while(p_cur != nullptr)
        {
            std::cout << p_cur->val << "->";
            p_cur = p_cur->next;
        }

        std::cout << "NULL \n";
    }

    // Function to get node ptr at given index(0-based index).
    // if index is valid and found in the linked list then pointer to node will be returned.
    // if index is invalid or not found in the linked list then it will return nullptr.
    link_list* get_node(int ind)
    {
        if(ind < 0)
        {
            return nullptr;
        }

        if(ind == 0)
        {
            return this;
        }

        link_list* p_tmp = this;
        int cur_ind(0);
        while(p_tmp->next != nullptr && cur_ind < ind)
        {
            p_tmp = p_tmp->next;
            ++cur_ind;

            if(cur_ind == ind)
            {
                return p_tmp;
            }
        }

        return nullptr;
    }

    // Function returns the length of linked list.
    int length()
    {
        link_list* p_tmp = this;
        int len(0);
        while(p_tmp != nullptr)
        {
            p_tmp = p_tmp->next;
            ++len;
        }

        return len;
    }
};