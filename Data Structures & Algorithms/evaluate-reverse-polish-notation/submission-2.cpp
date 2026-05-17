class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> order;
        int a, b;
        for (string& c : tokens)
        {
            if (c == "+")
            {
                a = order.top();
                order.pop();
                b = order.top();
                order.pop();
                order.push(b+a);
            }
            else if (c == "-")
            {
                a = order.top();
                order.pop();
                b = order.top();
                order.pop();
                order.push(b-a);
            }   
            else if (c == "*")
            {
                a = order.top();
                order.pop();
                b = order.top();
                order.pop(); 
                order.push(b*a);
            }       
            else if (c == "/")
            {
                a = order.top();
                order.pop();
                b = order.top();
                order.pop(); 
                order.push(b/a);
            }
            else
                order.push(stoi(c));
        }
        return order.top();
    }
};
