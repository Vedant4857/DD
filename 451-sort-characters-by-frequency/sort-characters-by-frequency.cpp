class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        priority_queue<pair<int,char>>pq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        for(auto&i:freq){
            pq.push({i.second,i.first});
        }
        string str = "";
        while(pq.size()){
            int siz = pq.top().first;
            char st = pq.top().second;
            str += string(siz,st);
            pq.pop();
        }
        return str;
    }
};