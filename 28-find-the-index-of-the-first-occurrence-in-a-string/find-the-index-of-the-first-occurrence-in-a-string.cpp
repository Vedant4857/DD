class Solution {
public:
    int strStr(string h, string n) {
        int H = h.size();
        int N = n.size();
        if(N==0) return 0;

        for(int i=0;i<H;i++){
            int j = 0;
            while(j<N && h[i+j] == n[j]){
                j++;
            }
            if(j==N) return i;
        }
        return -1;
    }
};