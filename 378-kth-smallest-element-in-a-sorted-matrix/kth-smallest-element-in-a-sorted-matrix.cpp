class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        for (int i = 0; i < matrix.size(); i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        pair<int, pair<int, int>> element;
        int result, row, col;

        while (k--) {
            element = pq.top();
            pq.pop();
            result = element.first;
            row = element.second.first;
            col = element.second.second;

            if (col < matrix[0].size()-1) {
                pq.push({matrix[row][col + 1], {row, col+1}});
            }
        }
        return result;
    }
};