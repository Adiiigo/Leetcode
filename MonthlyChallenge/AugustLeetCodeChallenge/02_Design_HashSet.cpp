Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

    add(value): Insert a value into the HashSet. 
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)


Note:

    All values will be in the range of [0, 1000000].
    The number of operations will be in the range of [1, 10000].
    Please do not use the built-in HashSet library.

Solutions:

//Approach 1-
-> Get the vector whose size is used as the key and the at every key the value is puchbacked
-> getKey - used to get hashkey
-> getValue - used to get value

#define SIZE 1000000
class MyHashSet {
    
    vector<int> lookup[SIZE] ;
    
    int getKey(int key){
        return key%SIZE ;
    }
    
    int getPos(int hashKey , int key){
        
        for(int i = 0 ; i < lookup[hashKey].size() ; i++){
            if(lookup[hashKey][i] == key){
                return i ;
            }
        }
        return -1 ;
    }
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        int hashKey = getKey(key) ;
        int pos = getPos(hashKey,key) ;
        if(pos == -1){
            lookup[hashKey].push_back(key) ;
        }
    }
    
    void remove(int key) {
        int hashKey = getKey(key) ;
        int pos = getPos(hashKey,key) ;
        if(pos >= 0){
            //the key exists
            lookup[hashKey].erase(lookup[hashKey].begin()+pos) ;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashKey = getKey(key) ;
        int pos = getPos(hashKey,key) ;
        
        if(pos >= 0){
            return true ;
        }
        
        return false ;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
