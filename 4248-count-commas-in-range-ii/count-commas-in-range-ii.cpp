class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        //100,000,000,000,00
        if(n>=1000){
            count += (min(n,999999LL)-1000+1)*1LL;
        }
        if(n>=1000000LL){
            count += (min(n,999999999LL)-1000000LL+1)*2LL;
        }
        if(n>=1000000000LL){
            count += (min(n,999999999999LL)-1000000000LL+1)*3LL;
        }
        if(n>=1000000000000LL){
            count += (min(n,999999999999999LL)-1000000000000LL+1)*4LL;
        }
        if(n==1000000000000000LL){
            count += 5;
        }
        return count;
    }
};