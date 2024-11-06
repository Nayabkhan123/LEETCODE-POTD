class Solution {
public:
    int countSetBits(int n){
        int cnt=0;
        while(n){
            cnt+=n&1;
            n=n>>1;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int max=nums[0];
        int setbits=countSetBits(nums[0]);
        int lastMax=0;
        for(int i=0;i<nums.size();i++){
            if(setbits!=countSetBits(nums[i])){
                lastMax=max;
            }
            if(nums[i]>max){
                setbits = countSetBits(nums[i]);
                max=nums[i];
            }
            if(nums[i]<lastMax) return false;
        }
        return true;
    }
};