#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;

        for (int j = 2; j <= n; j++) {
            for (int i = 1; i < j; i++) {
                if (__gcd(i, j) == 1) {
                    ans.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }

        return ans;
    }
};