class Solution {
public:
       bool search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return 1;

			if(nums[low] == nums[mid] && nums[mid] == nums[high]){
				low++;
				high--;
	
			}	
            else if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && nums[mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            } else {
                if (nums[high] >= target && nums[mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return 0;
    }

};
