#include <iostream>
#include <stack>

// Min stack , which will return min. element in O(1) time.

// Approach 1 : use single stack only ...
// Time complexity : O(1)
// Space complexity : O(1)
// source : https://www.youtube.com/watch?v=gGlVXfTAMH8
// Source : https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

// A user defined stack that supports getMin() in
// addition to push() and pop()
struct MyStack
{
    std::stack<int> s;
    int min_ele;
 
    // Prints minimum element of MyStack
    void getMin()
    {
        if (s.empty())
            std::cout << "Stack is empty\n";
 
        // variable minEle stores the minimum element
        // in the stack.
        else
            std::cout <<"Minimum Element in the stack is: "
                 << min_ele << "\n";
    }
 
    // Function prints top element of the stack.
    // if top_ele < min_ele then return min_ele.
    void peek()
    {
        if (s.empty())
        {
            std::cout << "Stack is empty \n";
            return;
        }
 
        int top_ele = s.top();

        // if top_ele < min_ele then return min_ele.
        if(top_ele < min_ele)
        {
            top_ele = min_ele;
        }

        std::cout << "Top Most Element is: ";
        std::cout << top_ele << "\n";
    }
 
    // Remove the top element from the stack.
    int pop()
    {
        if (s.empty())
        {
            std::cout << "Stack is empty\n";
            return INT32_MAX;
        }
 
        int top_ele = s.top();
        int removed_ele = top_ele;
        s.pop();
 
        // if top_ele < min_ele then calculate new min_ele again.
        if (top_ele < min_ele)
        {
            removed_ele = min_ele;
            min_ele = ((2 * min_ele) - top_ele);
        }
        
        
        std::cout << "Removed element val : " << removed_ele << " min_ele : " << min_ele << "\n";
    }
 
    // Insert new number in the stack and update the min_ele.
    void push(int new_ele)
    {
        // Insert new number into the stack
        if (s.empty())
        {
            min_ele = new_ele;
            s.push(new_ele);
            std::cout <<  "Number Inserted: " << new_ele << "\n";
            return;
        }
 
        // If new number is less than min_ele then
        // insert calculated element in the stack.
        if (new_ele < min_ele)
        {
            int calc_ele = ((2 * new_ele) - min_ele);
            s.push(calc_ele);
            min_ele = new_ele;
            std::cout << "Number Inserted: " << new_ele << " Actual inserted : " << calc_ele << "\n";

        }
        else
        {
            s.push(new_ele);
            std::cout << "Number Inserted: " << new_ele << "\n";
        }
    }
};

// Using two stack approach.
// Time complexity : O(1)
// Space complexity : O(n)
// NOTE : THIS IS NOT THE BEST SOLUTION.
class min_stack
{
    std::stack<int> st;
    std::stack<int> min_st;

    public:

    void push(int new_ele)
    {
        if(min_st.empty() || new_ele < min_st.top())
        {
            min_st.push(new_ele);
        }

        st.push(new_ele);
        std::cout << "Pushed : " << new_ele << "\n";
    }

    void pop()
    {
        if(min_st.top() == st.top())
        {
            min_st.pop();
        }
        st.pop();
    }

    int get_min()
    {
        if(min_st.empty())
        {
            return INT32_MAX;
        }

        return min_st.top();
    }

    int top()
    {
        if(st.empty())
        {
            return INT32_MAX;
        }

        return st.top();
    }
};

int main()
{
    MyStack my_stk;
    my_stk.push(10);
    my_stk.push(1);
   // my_stk.push(6);
   // my_stk.push(12);
   // my_stk.push(4);

    //std::cout << "Top ele is : " 
    my_stk.getMin();
    my_stk.peek();// << "\n";
    my_stk.pop();
    my_stk.pop();

    my_stk.pop();
    //my_stk.pop();
    //my_stk.pop();
    //my_stk.pop();


    // Test for method 2 ....................
   /* min_stack m_st;

    m_st.push(11);
    m_st.push(4);
    m_st.push(13);
    m_st.push(2);
    m_st.push(3);
    m_st.push(7);*/

   // std::cout << "Min ele is : " << m_st.get_min() << "\n";

    return 0;
}