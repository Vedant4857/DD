class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN, mini = INT_MAX;
        int max_index, min_index;
        if (n == 1) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                max_index = i;
            }
            if (nums[i] < mini) {
                mini = nums[i];
                min_index = i;
            }
        }
        int x, y;
        if (max_index > min_index) {
            x = max_index;
            y = min_index;
        } else {
            x = min_index;
            y = max_index;
        }

        int one = x + 1;
        int two = (y + 1) + (n - x);
        int three = n-y;

        int cc = min(one,two);
        return min(cc,three);
    }
};

// [-14,61,29,-18,59,13,-67,-16,55,-57,7,74]
//                      y.               x