class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(count == 0){
                maj = nums[i];
                count++;
            }
            else if(nums[i] == maj){
                count++;
            }
            else{
                count--;
            }
        }
        return maj;
    }
};