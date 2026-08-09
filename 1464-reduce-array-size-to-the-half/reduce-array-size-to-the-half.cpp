class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int> pq;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        int siz = n / 2;

        for (auto it : freq) {
            pq.push(it.second);
        }
        int count = 0;
        while (pq.size() && siz > 0) {
            siz -= pq.top();
            count++;
            pq.pop();
        }
        return count;
    }
};