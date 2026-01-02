class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0;
        int high = n;
        if(n==1) return 1;

        while(low<=high){
            long mid = low + (high - low)/2;
            long x = mid * (mid+1)/2;
            if(x<=n) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};