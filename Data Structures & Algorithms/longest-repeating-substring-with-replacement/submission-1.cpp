class Solution {
public:
    int characterReplacement(string s, int k) {
        int result =0;
        unordered_set <char> charSet (s.begin(), s.end());
        //get each unique char in string, and iterate through each char
        //test each char and see what replacements can be made
        for (char c : charSet){
            int l =0, count =0;
            for (int r = 0; r < s.size();r++){
                //go right along string, count the freq of target char
                if (s[r] == c){
                    count++;
                }
                //r-l+1 is the current window
                //window - count = the amount of replacements that could be made
                //if it exceeds k (the amount of desired replacements), then shrink window by moving left bound
                while ((r-l +1) - count > k){
                    if (s[l]==c){
                        //remove OOB chars
                        count--;
                    }
                    l++;
                }
                //result is the longest valid window
                result = std::max(result, r- l+1);
            }
        }
        return result;
    }
};
