class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = 0;
        for(int i = 0; i<n;i++){
            if(piles[i]>max){
                max = piles[i];
            }
        }

        int low = 1;
        int high = max;


        while(low<high){
            long long hours = 0;

            int mid = low + (high - low)/2;

            for(int i =0;i<n;i++){
                hours += (piles[i] + mid - 1)/mid;
            }

            if(hours<=h){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};