/*
    You are given an integer array nums. You need to ensure that the elements in the array 
    are distinct. To achieve this, you can perform the following operation any number of times:

    Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, 
    remove all remaining elements.
    Note that an empty array is considered to have distinct elements. Return the minimum number 
    of operations needed to make the elements in the array distinct.
*/

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n=nums.size();
            unordered_map<int,int>mp;
            for(int i=n-1;i>=0;i--){
                mp[nums[i]]++;
                if(mp[nums[i]]>1){
                    return (i+1)%3==0?(i+1)/3:(i+1)/3+1;
                }   
            }
            return 0;
        }
    };