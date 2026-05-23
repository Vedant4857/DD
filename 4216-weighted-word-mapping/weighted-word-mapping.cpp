class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        // char ch = 122 - 8
        // weights[ch - 'a']
        int j = 0;
        string str = "";
        for (auto word : words) {
            int sum = 0;
            for (auto c : word) {
                sum += weights[c - 'a'];
            }
            sum = sum % 26;
            str += 'z' - sum;
        }
        return str;
    }
};