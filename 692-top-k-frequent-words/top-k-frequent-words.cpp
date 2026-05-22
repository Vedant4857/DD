class Solution {
public:
    class cmp {
    public:
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        // pair<string,int>
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        unordered_map<string, int> mp;
        vector<string> ans;
        for (auto w : words) {
            mp[w]++;
        }

        for (auto it : mp) {
            pq.push({it.first, it.second});

            if (pq.size() > k) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};