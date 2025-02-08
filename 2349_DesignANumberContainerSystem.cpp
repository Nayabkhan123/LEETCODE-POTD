/*
    Design a number container system that can do the following:

    Insert or Replace a number at the given index in the system.
    Return the smallest index for the given number in the system.
    Implement the NumberContainers class:

    NumberContainers() Initializes the number container system.
    void change(int index, int number) Fills the container at index with the number. 
    If there is already a number at that index, replace it.
    int find(int number) Returns the smallest index for the given number, or -1 if there is 
    no index that is filled by number in the system.
*/

class NumberContainers {
    unordered_map<int,int> index_number;
    unordered_map<int,set<int>> number_indices;
public:
    NumberContainers() {
        
    }
    void change(int index, int number) {
        if(index_number.count(index)){
            number_indices[index_number[index]].erase(index);
            if(number_indices[index_number[index]].size()==0)
                number_indices.erase(index_number[index]);
        }
        
        index_number[index]=number;
        number_indices[number].insert(index);
    }
    
    int find(int number) {
        if(!number_indices.count(number))
            return -1;
        return *(number_indices[number].begin());
    }
};
