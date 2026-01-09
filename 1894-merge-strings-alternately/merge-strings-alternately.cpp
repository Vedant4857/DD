class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string sum = "";

        while(word1[i] || word2[j]){
            if(word1[i]){
                sum += word1[i];
                i++;
            } 
            if(word2[j]){
                sum += word2[j];
                j++;
            }
        }
        return sum;
    }
};