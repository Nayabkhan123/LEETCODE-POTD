/*
    Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal 
    to its value.
    Return the largest lucky integer in the array. If there is no lucky integer return -1.

    Example 1:
    Input: arr = [2,2,3,4]
    Output: 2
    Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
*/

// using map
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        int ans=INT_MIN;
        for(auto it : arr){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.first == it.second){
                ans = max(ans,it.first);
            }
        }
        return ans==INT_MIN ? -1 : ans;
    }
};

// using vector
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>freq(501);
        int ans=INT_MIN;
        for(auto it : arr){
            freq[it]++;
        }
        for(auto it : arr){
            if(freq[it] == it){
                ans = max(ans,it);
            }
        }
        return ans==INT_MIN ? -1 : ans;
    }
};