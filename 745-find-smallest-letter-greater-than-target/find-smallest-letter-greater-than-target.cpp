class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0;
        int high = n-1;

        while(low<high){
            int mid = low + (high - low)/2;
            if(letters[mid]>target) high = mid;
            else low = mid + 1;
        }
        if(letters[low] > target)
            return letters[low];

        return letters[0]; 
    }
};