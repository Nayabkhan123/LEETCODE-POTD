/*
    You are given an integer array values where values[i] represents the value of the ith sightseeing spot. 
    Two sightseeing spots i and j have a distance j - i between them.

    The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the 
    sightseeing spots, minus the distance between them.

    Return the maximum score of a pair of sightseeing spots.
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int result=0;
        int leftMax=values[0]+0;
        for(int j=1;j<n;j++){
            int rightvalue=values[j]-j;
            result=max(result,leftMax+rightvalue);
            leftMax=max(leftMax,values[j]+j);
        }
        return result;
    }
};

//Brute Force Approch (gives Time Limit Exceeded 49/55 testcases passed)
int maxScoreSightseeingPair(vector<int>& values) {
    int n=values.size();
    int maxi=INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(values[i]+values[j]+i-j>maxi){
                maxi=values[i]+values[j]+i-j;
            }
        }
    }
    return maxi;
}