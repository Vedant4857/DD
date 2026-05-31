class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long z = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int x : asteroids) {
            if (x <= z) {
                z += x;
            } else {
                return 0;
            }
        }
        return 1;
    }
};