class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) 
        {
            //move l pointer to left until it hits alphanumeric 
            while (l < r && !isalnum(s[l])) 
                l++;
            //move r pointer to right until it hits alphanumeric
            while (l < r && !isalnum(s[r])) 
                r--;
            //compare two characters, if dont match return false
            if (tolower(s[l]) != tolower(s[r])) 
                return false;
            //move past the compared characters and repeat
            l++;
            r--;
        }
        return true;
    }
};

