class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        // land -> water
        for (int i = 0; i < landStartTime.size(); i++) {
            int landEnd = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); j++) {
                int waterStart = max(landEnd, waterStartTime[j]);
                ans = min(ans, waterStart + waterDuration[j]);
            }
        }

        // water -> land
        for (int i = 0; i < waterStartTime.size(); i++) {
            int waterEnd = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < landStartTime.size(); j++) {
                int landStart = max(waterEnd, landStartTime[j]);
                ans = min(ans, landStart + landDuration[j]);
            }
        }

        return ans;
    }
};