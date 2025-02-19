/*
    A happy string is a string that:

    consists only of letters of the set ['a', 'b', 'c'].
    s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
    For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings 
    "aa", "baa" and "ababbc" are not happy strings.

    Given two integers n and k, consider a list of all happy strings of length n sorted in 
    lexicographical order.

    Return the kth string of this list or return an empty string if there are less than k 
    happy strings of length n.
*/


class Solution {
    public:
        string getHappyString(int n, int k) {
            vector<string> size_n;
            queue<string> q;
    
            q.push("a");
            q.push("b");
            q.push("c");
            while(!q.empty()){
                string curr = q.front();
                q.pop();
                if(curr.size()==n){
                    size_n.push_back(curr);
                    continue;
                }
                string first=curr;
                string second=curr;
    
                if(curr.back()=='a'){
                    first.push_back('b');
                    second.push_back('c');
                }else if(curr.back()=='b'){
                    first.push_back('a');
                    second.push_back('c');
                }else{
                    first.push_back('a');
                    second.push_back('b');
                }
                if(size_n.size()>=k)    break;
                q.push(first);
                q.push(second);
            }
            if(size_n.size()<k)
                return "";
            return size_n[k-1];
        }
    };