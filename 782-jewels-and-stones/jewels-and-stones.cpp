class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_set<char> st;
        for (char ch : jewels) {
            st.insert(ch);
        }
        for (char ch : stones) {
            if (st.contains(ch)) {
                count++;
            }
        }
        return count;
    }
};