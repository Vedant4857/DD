class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int count = 0;
        int i = 0, j = n-1;
        sort(people.begin(),people.end());

        while(i<=j){
            if(people[j] + people[i] <= limit){
                count++;
                i++;
                j--;
            }
            else{
                if(people[j] <= limit){
                    count++;
                    j--;
                }
            }
        }
        return count;
    }
};