/*
    You are given two 2D integer arrays nums1 and nums2.

    nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
    nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
    Each array contains unique ids and is sorted in ascending order by id.

    Merge the two arrays into one array that is sorted in ascending order by id, respecting the 
    following conditions:

    Only ids that appear in at least one of the two arrays should be included in the resulting array.
    Each id should be included only once and its value should be the sum of the values of this id 
    in the two arrays. If the id does not exist in one of the two arrays, then assume its value 
    in that array to be 0.
    Return the resulting array. The returned array must be sorted in ascending order by id.
*/

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int i=0,j=0,n=nums1.size(),m=nums2.size();
            vector<vector<int>>ans;
            while(i<n && j<m){
                int a=nums1[i][0],b=nums2[j][0];
                if(a==b){
                    ans.push_back({a,nums1[i][1]+nums2[j][1]});
                    i++,j++;
                }
                else if (a>b){
                    ans.push_back(nums2[j]);
                    j++;
                }
                else {
                    ans.push_back(nums1[i]);
                    i++;
                }
            }
            while(i<n){
                ans.push_back(nums1[i]);
                i++;
            }
            while(j<m){
                ans.push_back(nums2[j]);
                j++;
            }
            return ans;
        }
    };