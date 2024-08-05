class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i]==arr[j]){
                    a[i]++;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                cnt++;
            }
            if(cnt==k){
                return arr[i];
            }
        }
        return "";
    }
};