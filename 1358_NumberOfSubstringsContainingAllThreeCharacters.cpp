/*
    Given a string s consisting only of characters a, b and c.

    Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int currcnt=0;
            vector<int>abc(3);
            int left=0,n=s.size(),ans=0;
            for(int right=0;right<n;right++){
                if(abc[s[right]-'a']==0){
                    currcnt++;
                }
                abc[s[right]-'a']++;
                while(currcnt==3){
                    ans+=n-right;
                    if(abc[s[left]-'a']==1){
                        currcnt--;
                    }
                    abc[s[left]-'a']--;
                    left++;
                }
            }
            return ans;
        }
    };