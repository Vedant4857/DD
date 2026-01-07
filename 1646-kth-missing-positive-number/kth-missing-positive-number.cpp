class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int n = arr.size();
        int high = n - 1;

        while(low<=high){
            int mid = low + (high - low)/2;

            int k2= arr[mid] - mid - 1;
            if(k2<k) low = mid+1;
            else high = mid - 1;
        }
        return low + k;
    }
};