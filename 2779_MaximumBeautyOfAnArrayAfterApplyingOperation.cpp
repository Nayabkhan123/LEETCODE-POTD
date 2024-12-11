class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        if(nums.size()==1) return 1;
        int maxi = -1;
        for(auto it : nums){
            maxi=max(maxi,it);
        }
        vector<int>count(maxi+1,0);
        for(auto it : nums){
            count[max(0,it-k)]++;
            count[min(maxi,it+k+1)]--;
        }
        int currsum=0;
        int maxsum=0;
        for(auto it:count){
            currsum+=it;
            maxsum = max(maxsum,currsum);
        }
        return maxsum;
    }
};