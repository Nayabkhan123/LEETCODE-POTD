/*
    You are given an integer array digits, where each element is a digit. The array may contain duplicates.

    You need to find all the unique integers that follow the given requirements:

    The integer consists of the concatenation of three elements from digits in any arbitrary order.
    The integer does not have leading zeros.
    The integer is even.
    For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

    Return a sorted array of the unique integers.
*/

class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            vector<int>freq(10);
            vector<int>ans;
            for(auto it:digits){
                freq[it]++;
            }
            for(int i=100;i<1000;i+=2){
                vector<int>temp(10);
                int num=i;
                temp[num%10]++;
                num/=10;
                temp[num%10]++;
                num/=10;
                temp[num%10]++;
                bool flag = true;
                for(int k=0;k<10;k++){
                    if(freq[k]<temp[k]){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans.push_back(i);
            }
            return ans;
        }
    };

class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            int n=digits.size();
            set<int>temp;
        
            for(int i=0;i<n;i++){
                if(digits[i]==0) continue;
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    for(int k=0;k<n;k++){
                        if(j==k || i==k || digits[k]%2) continue;
                        temp.insert(digits[i]*100+digits[j]*10+digits[k]);
                    }
                }
            }
            vector<int>ans(temp.begin(),temp.end());
            return ans;
        }
    };