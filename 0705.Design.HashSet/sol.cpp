class MyHashSet {
private:
    bitset<1000001> arr;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        arr.reset();
    }
    
    void add(int key) {
        arr[key] = 1;
    }
    
    void remove(int key) {
        arr.reset(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */