class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> count;
        vector<vector<int>> freq (nums.size()+1);

        //count how many times a number appears
        for (int n : nums)
            count [n] ++;
        
        //insert the number in its freq index
        for (auto pair : count)
            freq[pair.second].push_back(pair.first);

        vector<int> result;
        //start at the highest freq found
        for (int i =freq.size()-1; i>0; i--){
            //go through individual freq vector and push nums
            for (int j =0; j < freq[i].size(); j++){
                result.push_back(freq[i][j]);
                if (result.size()==k)
                    return result;
                    //stop when k nums have been pushed into result
            }
        }
    }
};
