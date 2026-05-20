class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // 1.   3.    2.   4
        // 3.   1.    2.   4
        unordered_map<int, int> mp;
        vector<int> ans;
        int count = 0;

        for (int i = 0; i < A.size(); i++) {
            mp[A[i]]++;
            mp[B[i]]++;
            if (A[i] == B[i]) {
                count++;
            } else {
                if (mp[A[i]] == 2) {
                    count++;
                }
                if (mp[B[i]] == 2) {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};