class Solution {
public:
    int withmaxK(vector<int>& arr, int k){
        int left = 0, distinct = 0;
        vector<int> freq(20001,0);
        int ans = 0;

        for(int right = 0;right < arr.size();right++){
            if(freq[arr[right]] == 0) distinct++;
            freq[arr[right]]++;

            while(distinct > k){
                freq[arr[left]]--;
                if(freq[arr[left]] == 0) distinct--;
                left++;
            }
            ans += (right - left + 1); 
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return withmaxK(nums,k) - withmaxK(nums,k-1);
    }
};