class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                freq[nums[i]]++;
            }
        }
        int num = 0;
        int count = 0;
        bool yes = false;
        for (auto& i : freq) {
            if (i.second >= count) {
                if (i.second == count) {
                    num = min(i.first, num);
                    yes = true;
                } else {
                    count = i.second;
                    num = i.first;
                    yes = true;
                }
            }
        }
        if (!yes) {
            return -1;
        }
        return num;
    }
};