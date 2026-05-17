class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (string s : strs)
        {
            string length = to_string(s.size());
            result= result+length+'!'+s;
        }
        return result;
    }

    vector<string> decode(string s) {
        int index = 0;
        vector<string>result;
        string stringCount;
        int numCount;
        if (s.size() ==1)
            result.push_back("");
        while (index < s.size())
        {
            if (s[index] != '!')
            {
                stringCount += s[index];
                index ++;
            }
            else
            {
                index ++;
                numCount = stoi(stringCount);
                string temp = s.substr(index, numCount);
                result.push_back(temp);
                stringCount = "";
                index += numCount;
            } 
        }
        return result;
    }
};
