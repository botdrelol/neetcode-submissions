class Solution {
public:

    string encode(vector<string>& strs) {
        string result="";
        for (string s : strs)
            result += to_string(s.size()) +'#' + s;
        //for every string, add it to a long string
        //where each string is seperated by its size and a #
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int index =0; 
        string buffer; //holds the char between each #
        int count; //how long the building string should be
        if (s.size() ==1)
            result.push_back("");
        while (index < s.size()){ 
            //while not found #, keep adding to buffer to get the length
            if (s[index]!='#'){
                buffer += s[index];
                index++;
            }
            //once found #
            else{
                index++;
                count = stoi (buffer); //convert buffer to a length
                string temp = s.substr(index,count); //start at index until legnth of string
                result.push_back(temp);
                buffer="";
                index += count;
            }
        }
        return result;
    }
};
