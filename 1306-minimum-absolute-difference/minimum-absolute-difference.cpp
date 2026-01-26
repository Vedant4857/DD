class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> nums;
        sort(arr.begin(),arr.end());
        int min = INT_MAX;

        for(int i = 1 ;i<n;i++){
            if(arr[i]-arr[i-1] < min){
                min = arr[i]-arr[i-1];
                nums.clear();
                nums.push_back({arr[i-1],arr[i]});
            }
            else if(arr[i]-arr[i-1] == min){
                nums.push_back({arr[i-1],arr[i]});
            }
            else continue;
        }
        return nums;
    }
};