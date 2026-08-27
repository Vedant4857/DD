class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, string> rank;
        vector<string> ans;
        priority_queue<int> q;
        int num = 4;
        for (int x : score) {
            q.push(x);
        }
        int n = score.size();
        int i = 0;
        while (i < n && q.size()) {
            int r = q.top();
            q.pop();
            if (i == 0) {
                rank[r] = "Gold Medal";
            }
            if (i == 1) {
                rank[r] = "Silver Medal";
            }
            if (i == 2) {
                rank[r] = "Bronze Medal";
            }
            if (i > 2) {
                string j = to_string(num);
                rank[r] = j;
                num++;
            }
            i++;
        }

        for (int k = 0; k < n; k++) {
            ans.push_back(rank[score[k]]);
        }
        return ans;
    }
};