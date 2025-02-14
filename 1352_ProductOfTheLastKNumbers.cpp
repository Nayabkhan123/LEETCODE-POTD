/*
    Design an algorithm that accepts a stream of integers and retrieves the product of the last k 
    integers of the stream.

    Implement the ProductOfNumbers class:

    ProductOfNumbers() Initializes the object with an empty stream.
    void add(int num) Appends the integer num to the stream.
    int getProduct(int k) Returns the product of the last k numbers in the current list. You can 
    assume that always the current list has at least k numbers.
    The test cases are generated so that, at any time, the product of any contiguous sequence of 
    numbers will fit into a single 32-bit integer without overflowing.
*/

class ProductOfNumbers {
    vector<int>store;
public:
    ProductOfNumbers() {
        
    }
    void add(int num) {
        if(num==0){
            store={};
            return;
        }
        int last=store.size();
        int prev = last==0 ? 1 : store[last-1];
        store.push_back(num*prev);
    }
    
    int getProduct(int k) {
        int n=store.size();
        if(n<k) return 0;
        else if (n==k) return store[n-1];
        else return store[n-1]/store[n-1-k];
    }
};

// Brute Force Approch
class ProductOfNumbers {
    vector<int>store;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        store.push_back(num);
    }
    
    int getProduct(int k) {
        int ans=1,n=store.size();
        for(int i=n-k;i<n;i++){
            ans*=store[i];
        }
        return ans;
    }
};