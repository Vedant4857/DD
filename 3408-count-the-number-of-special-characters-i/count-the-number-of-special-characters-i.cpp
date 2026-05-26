class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        unordered_set<char> v;
        for (auto w : word) {
            if (w >= 'a' && w <= 'z') {
                v.insert(w - 32);
            }
        }
        for (auto w : word) {
            if (v.count(w)) {
                count++;
                v.erase(w);
            }
        }
        return count;
    }
};