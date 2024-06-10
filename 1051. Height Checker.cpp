class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        int cnt=0;
        int expected[n];
        for(int i=0;i<n;i++) expected[i]=heights[i];
        sort(expected,expected+n);
        for(int i=0;i<n;i++){
            if(expected[i]!=heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};