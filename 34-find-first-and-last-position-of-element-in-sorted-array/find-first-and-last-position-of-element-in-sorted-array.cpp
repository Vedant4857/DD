// Vedant
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid;
        int first = -1;
        bool  flag = true;

        while(low<=high){
            mid = low + (high - low)/2;
            if(nums[mid]==target){
                first = mid;
                high = mid-1;
                flag = false;
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            else{
                high = mid  - 1;
            }
        }

        low = 0;
        high = n-1;
        int second = -1;
        while(low<=high){
            mid = low + (high - low)/2;
            if(nums[mid]==target){
                second = mid;
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid + 1;
            }
            else{
                high = mid  - 1;
            }
        }
        return {first,second};
    }
};