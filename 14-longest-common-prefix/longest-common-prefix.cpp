class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        string str1 = strs[0];
        string str3 = "";

        for(int i  = 1;i < n; i++){
            string str2 = strs[i];
            for(int j = 0;j < str1.length();j++){
                if(str1[j]==str2[j]){
                    str3 += str1[j];
                }
                else{
                    break;
                }
            }
            str1 = str3;
            str3 = "";
        }
        return str1;
    }
};