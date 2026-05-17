class Solution {
public:
    bool isValid(string s) {
        stack<char> order;
        if (s.size() < 2)
            return false;
        for (char par : s)
        {
            //for an opening, push onto stack (most recent/top needs to be closed first)
            if (par == '(' || par == '{' || par =='[')
                order.push(par);
            else
            {
                if (order.empty())
                    return false;
                //for a closing, get the top of stack and match with the current closing
                char curr = order.top();
                order.pop();
                if (!((curr == '(' && par ==')') || (curr =='{' && par =='}') || (curr=='[' && par ==']')))
                    return false;
            }
        }
        if (order.empty())
            return true;
        return false;
    }
};
