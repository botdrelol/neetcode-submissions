class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> count;
        vector<vector<int>> freq (nums.size()+1);

        //count frequency of ints 
        for (int n : nums)
        {
            count [n] = 1 + count[n];
        }
        //put the number into the vector that matches with frequency
        for (auto pair : count)
        {
            freq[pair.second].push_back(pair.first);
        }
        vector<int> results;
        //go through the buckets 
        for (int i = freq.size()-1 ; i > 0; i--)
        {
            //go through each bucket
            for (int n : freq[i])
            {
                //get the next number until k is reached
                results.push_back(n);
                if (results.size() ==k)
                    return results;
            }
        }
        return results;
    }
};
