class Solution {
public:
    int longestPalindrome(string s) {
    vector<int> freq(256);
    int ans = 0;
    bool odd = false;
    for(int i =0;i<s.size();i++){
        freq[s[i]]++;
    }

    for(int i =0;i<256;i++){
        if(freq[i]%2==0){
            ans += freq[i];
        }
        else{
            ans += freq[i]-1;
            odd = true;
        }
    }
    if(odd) ans = ans + 1;
    return ans;
}
};