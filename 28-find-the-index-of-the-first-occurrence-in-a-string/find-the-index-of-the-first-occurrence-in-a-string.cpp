class Solution {
public:
    int strStr(string h, string n) {
        int H = h.size();
        int N = n.size();
        if(N==0) return 0;

        for(int i =0;i<=H-N;i++){
            int j = 0;
            while(j<N){
                if(h[i+j] == n[j]) j++;
                else break;
            }
            if(j==N) return i;
        }
        return -1;
    }
};