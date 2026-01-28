class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U',
                                      'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        vector<int> freq(123,0);

        for (int i = 0; i < n; i++) {
            if (vowels.count(s[i])) {
                freq[s[i]]++;
            }
        }

         int idx = 0;

        for(int j = 0; j < 123; j++){
            while(freq[j] > 0){
                while(idx < n && !vowels.count(s[idx])){
                    idx++;
                }
                s[idx] = char(j);
                freq[j]--;
                idx++;
            }
        }
        return s;
    }
};