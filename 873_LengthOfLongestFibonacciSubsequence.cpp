/*
    A sequence x1, x2, ..., xn is Fibonacci-like if:

    n >= 3
    xi + xi+1 == xi+2 for all i + 2 <= n
    Given a strictly increasing array arr of positive integers forming a sequence, 
    return the length of the longest Fibonacci-like subsequence of arr. If one does 
    not exist, return 0.

    A subsequence is derived from another sequence arr by deleting any number of 
    elements (including none) from arr, without changing the order of the remaining 
    elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].
*/

class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n=arr.size(),ans=0;
            unordered_set<int>s;
            for(auto it:arr){
                s.insert(it);
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int prev=arr[j];
                    long long curr = arr[i]+arr[j];
                    int len=2;
                    while(s.contains(curr)){
                        int temp = curr;
                        curr+=prev;
                        prev=temp;
                        ans=max(ans,++len);
                    }
                }
            }
            return ans;
        }
    };