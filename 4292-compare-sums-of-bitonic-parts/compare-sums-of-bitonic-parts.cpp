class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long asc = nums[0];
        long dsc = 0;

        for(int i = 1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                asc = asc + nums[i];
            }
            else if(nums[i]<nums[i-1]){
                if(dsc == 0){
                    dsc += nums[i-1] + nums[i];
                }
                else{
                    dsc += nums[i];
                }
            }
        }
        if(asc == dsc){
            return -1;
        }
        else if(asc>dsc){
            return 0;
        }
        else{
            return 1;
        }
    }
};