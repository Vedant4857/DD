class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        int n = nums.size();
        vector<int> ans;

        for(int i = 0;i<k-1;i++){
            while(!dq.empty()&&nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i = k-1;i<n;i++){
            while(!dq.empty()&&nums[i]>nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            if((i-k)>=dq.front()){
                dq.pop_front();
            }
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};