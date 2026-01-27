class Solution {
public:
    string removeOuterParentheses(string s) {
        int it = 0;
        string xyz;

        for(int i =0;i<s.size();i++){
            if(s[i] == '('){
                if(it>=1){
                    xyz.push_back(s[i]);
                }
                it++;
            }
            else{
                if(it>=2){
                    xyz.push_back(s[i]);
                }
                it--;
            }
        }
        return xyz;
    }
};