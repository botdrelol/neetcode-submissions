class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> anagram;
        for (string s : strs)
        {
            vector<int> letterCount (26,0);
            for (char c : s)
            {
                letterCount [c - 'a'] ++;
            }

            string key = to_string(letterCount[0]);
            for (int i = 1; i < 26; i ++)
            {
                key = key + ',' + to_string(letterCount[i]);
            }
            anagram[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto pair : anagram)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
