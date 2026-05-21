class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefix;
        int maxi = INT_MIN;

        for (int i = 0; i < arr1.size(); i++) {
            string str = to_string(arr1[i]);
            string s = "";
            for (char x : str) {
                s += x;
                prefix.insert(s);
            }
        }

        for (int i = 0; i < arr2.size(); i++) {
            string st = "";
            string str = to_string(arr2[i]);
            for (char x : str) {
                st += x;
                if (prefix.contains(st)) {
                    maxi = max(maxi, (int)st.size());
                }
            }
        }
        if (maxi == INT_MIN) {
            return 0;
        }
        return maxi;
    }
};