class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),[] (int a, int b){
            string x = to_string(a);
            string y = to_string(b);

            return x+y > y+x;
        });

        if(nums[0]==0){
            return "0";
        }

        string res = "";

        for(int i = 0;i<n;i++){
            res += to_string(nums[i]);
        }
        return res;
    }
};