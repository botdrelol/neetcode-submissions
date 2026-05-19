class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> anagram;
        //go through every string given
        for (string s : strs){
            //find the frequency of each letter
            vector<int> letterFreq (26,0);
            for (char c : s)
                letterFreq [c-'a' ] ++;
            string key ="";
            for (int i = 0; i < letterFreq.size(); i++)
                key = key + ',' + to_string(letterFreq[i]);
            //convert freq into a string to use a key lookup
            anagram[key].push_back(s);
            //use key to lookup words with same letter freqs and add it to the vector
        }
        vector<vector<string>> result;
        for (auto pair : anagram)
        //get the vector of anagrams from each unique key
            result.push_back(pair.second);
        return result;
        
    }
};
