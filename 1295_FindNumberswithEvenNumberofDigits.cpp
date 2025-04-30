/*
    Given an array nums of integers, return how many of them contain an even number of digits.
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto it : nums){
            int digits = floor(log10(it))+1;
            if(digits%2) continue;
            ans++;            
        }
        return ans;
    }
};

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto it : nums){
            int digits=0;
            while(it){
                it/=10;
                digits++;
            }
            if(digits%2) continue;
            ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto it : nums){
            string s=to_string(it);
            if(s.size()%2) continue;
            ans++;
        }
        return ans;
    }
};