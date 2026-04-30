class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return {nums[0]};
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>> pq;
        int new1 = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != new1) {
                pq.push({count, new1});
                new1 = nums[i];
                count = 1;
            } else {
                count++;
            }
        }
        pq.push({count, new1});

        vector<int> ans;
        while (k-- && !pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};