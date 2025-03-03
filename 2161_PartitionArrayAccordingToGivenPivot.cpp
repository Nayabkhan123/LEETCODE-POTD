/*
    You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums 
    such that the following conditions are satisfied:

    Every element less than pivot appears before every element greater than pivot.
    Every element equal to pivot appears in between the elements less than and greater 
    than pivot.
    The relative order of the elements less than pivot and the elements greater than 
    pivot is maintained.
    More formally, consider every pi, pj where pi is the new position of the ith element 
    and pj is the new position of the jth element. If i < j and both elements are 
    smaller (or larger) than pivot, then pi < pj.
    Return nums after the rearrangement.
*/

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int lcnt=0,eqcnt=0,gcnt=0;
            for(auto it:nums){
                if(it<pivot){
                    lcnt++;
                }
                else if (it==pivot){
                    eqcnt++;
                }
                else{
                    gcnt++;
                }
            }
            int i=0,j=lcnt,k=lcnt+eqcnt;
            vector<int>ans(nums.size(),0);
            for(auto it:nums){
                if(it<pivot){
                    ans[i]=it;
                    i++;
                }
                else if (it==pivot){
                    ans[j]=it;
                    j++;
                }
                else{
                    ans[k]=it;
                    k++;
                }
            }
            return ans;
        }
    };

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int>l,g;
            int n=nums.size(),cnt=0;
            for(int i=0;i<n;i++){
                if(pivot>nums[i]) l.push_back(nums[i]);
                else if (pivot<nums[i]) g.push_back(nums[i]);
                else cnt++;
            }
            while(cnt--){
                l.push_back(pivot);
            }
            l.insert(l.end(), g.begin(), g.end());
            for(int i=0;i<l.size();i++){
                nums[i]=l[i];
            }
            return nums;
        }
    };