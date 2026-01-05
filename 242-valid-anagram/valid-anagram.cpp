class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return 0;

        unordered_map <char,int> anagram;

        for(char x:s){
            anagram[x]++;
        }

        for(char y:t){
            if(anagram[y]==0){
                return 0;
            }
            anagram[y]--;
        }
        return 1;

        
    }
};