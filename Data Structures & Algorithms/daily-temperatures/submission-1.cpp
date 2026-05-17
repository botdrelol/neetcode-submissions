class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> indexes;
        vector<int> result (temperatures.size());
        indexes.push(0);
        for (int i =1; i < temperatures.size(); i ++)
        {
            //go through stack
            //if top is less than curr, find distance
            while (!(indexes.empty()) &&temperatures[indexes.top()] < temperatures[i])
            {
                int index = indexes.top();
                int distance = i - index;
                result[index] = distance;
                indexes.pop();
            }
            indexes.push(i);
        }
        return result;
    }
};
