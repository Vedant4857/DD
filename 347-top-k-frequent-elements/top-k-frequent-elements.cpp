class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& a : freq) {
            pq.push({a.second, a.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            auto x = pq.top();
            ans.push_back(x.second);
            pq.pop();
        }
        return ans;
    }
};