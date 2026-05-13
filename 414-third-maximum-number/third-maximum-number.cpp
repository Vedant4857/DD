class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int>us(nums.begin(),nums.end());
        if (us.size() < 3) {
            return *max_element(nums.begin(), nums.end());
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : us) {
            pq.push(x);
            if (pq.size() > 3) {
                pq.pop();
            }
        }
        return pq.top();
    }
};