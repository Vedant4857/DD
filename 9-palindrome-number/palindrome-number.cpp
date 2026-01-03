class Solution {
public:
    bool isPalindrome(int x) {
        long sum = 0;
        int z = x;
        while(x>0){
            int n = x%10;
            sum = sum * 10 + n;
            x = x/10;
        }
        if(z==sum){
            return 1;
        }
        return 0;
    }
};