class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}
    int nonSpecialCount(int l, int r) {
        int s = r - l + 1;
        //must be square of a prime number
        int le = sqrt(l);
        int ri = sqrt(r);

        for(int i = le;i<=ri;i++){
            if(isPrime(i) && i*i<=r && i*i>=l){
                s--;
            }
        }
        return s;
    }
};