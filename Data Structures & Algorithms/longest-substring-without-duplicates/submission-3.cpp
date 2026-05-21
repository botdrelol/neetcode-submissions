class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0; 
        int r =0;
        int max =0;
        int tmp =0;
        unordered_map <char, int> ocur;
        while (r < s.length()){
            //iterate through string, if not occurred already, add and continue
            if (ocur.find(s[r]) == ocur.end()){
                ocur[s[r]]=r;
                r++;
                tmp ++;
                cout << r << " " << tmp;
            }
            //this means that found reoccuring char
            //will continue until no more reoccurance, continue iterate ahead once removing dupes
            else{
                if (tmp > max)
                    max = tmp;
                //delete past chars starting from left bound 
                ocur.erase(s[l]);
                l++;
                tmp--;
            }
        }
        if (tmp > max) max = tmp;
        return max;
    }
};
