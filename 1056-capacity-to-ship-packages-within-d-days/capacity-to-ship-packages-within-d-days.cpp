class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int max = 0;
        int s = 0;
        for(int i = 0;i<n;i++){
            if(w[i]>max) max = w[i];
            s+= w[i];
        }
        int low = max;
        int high = s;
        int ans = s;

        

        while(low<=high){
            int mid = low + (high - low)/2;
            int sum = 0;
            int k = 1;

            for(int i = 0;i<n;i++){
                if(w[i] + sum <= mid){
                    sum += w[i];
                }
                else{
                    k++;
                    sum = w[i];
                }
            }

            if(k<=days){
                high = mid -1;
                ans = mid;
            }
            else low = mid + 1;

        }
        return ans;
    }
};