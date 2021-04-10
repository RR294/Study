
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
};