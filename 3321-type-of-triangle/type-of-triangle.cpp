class Solution {
public:
    string triangleType(vector<int>& nums) {
        // First, check Triangle Inequality Theorem:
        // Sum of any two sides must be greater than the third side.
        sort(nums.begin(), nums.end());

        if (nums[0] + nums[1] <= nums[2]) {
            return "none"; // Not a valid triangle
        }

        // All three sides equal
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }

        // Any two sides equal
        if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        }

        // All sides different
        return "scalene";
    }
};