class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(),deck.end());
        deque<int>q;
        q.push_front(deck[n-1]);
        for(int i = n-2;i>=0;i--){
            int x = q.back();
            q.pop_back();
            q.push_front(x);
            q.push_front(deck[i]);
        }
        for(int i = 0;i<n;i++){
            deck[i] = q.front();
            q.pop_front();
        }
        return deck;
    }
};