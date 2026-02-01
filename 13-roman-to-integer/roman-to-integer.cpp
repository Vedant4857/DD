class Solution {
public:

    bool nextisBigger(char current, char next){
        char roman[7] = {'I','V','X','L','C','D','M'};
        if(current==next) return 0;
        for(int i =0;i<7;i++){
            if(current == roman[i]) return true;
            else if(next == roman[i]) return false;
        }
        return 0;
    }
    int tovalue(char c){
        char roman[7] = {'I','V','X','L','C','D','M'};
        int value[7] = {1,5,10,50,100,500,1000};

        for(int i =0;i<7;i++){
            if(roman[i] == c) return value[i];
        }
        return 0;
    }
    int romanToInt(string S) {
        int n = S.size(), sum = 0, i = 0;
        while(i<n){
            if(i!= n-1 && nextisBigger(S[i],S[i+1])){
                int x = tovalue(S[i]);
                sum -= x;
            }
            else{
                int x = tovalue(S[i]);
                sum += x;
            }
            i++;
        }
        return sum;
    }
};