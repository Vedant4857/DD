class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        if (nums.size() == 1) {
            return {0};
        }
        int n = nums.size();
        vector<int> arr(n);

        arr[n - 1] = 0;
        int even = 0, odd = 0;
        if ((nums[n - 1]) % 2 == 0) {
            even++;
        } else {
            odd++;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                arr[i] = odd;
                even++;
            } else {
                arr[i] = even;
                odd++;
            }
        }
        return arr;
    }
};