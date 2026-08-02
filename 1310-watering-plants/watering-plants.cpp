class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cap = capacity;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (plants[i] <= cap) {
                cap -= plants[i];
                sum += 1;
                continue;
            } else {
                sum += i;
                sum += i + 1;
                cap = capacity;
                cap -= plants[i];
            }
        }
        return sum;
    }
};