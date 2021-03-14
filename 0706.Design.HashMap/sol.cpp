#include <iostream>

using namespace std;

struct Node
{
    int key;
    int val;
    Node* next;
    
    Node(int key, int val) : key(key), val(val), next(nullptr) {}
    Node(int key, int val, Node* next) : key(key), val(val), next(next) {}
};

class MyHashMap {
private:
    Node** _nodeArr;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        _nodeArr = new Node*[761];
        for (int i = 0; i < 761; ++i)
            _nodeArr[i] = nullptr;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % 761;
        if (Node* pointer = _nodeArr[index]) {
            while (pointer && pointer->key != key) {
                pointer = pointer->next;
            }
            if (pointer == nullptr) {
                _nodeArr[index] = new Node(key, value, _nodeArr[index]);
            }
            else {
                pointer->val = value;
            }
        } else {
            _nodeArr[index] = new Node(key, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % 761;
        if (Node* pointer = _nodeArr[index]) {
            while (pointer) {
                if (pointer->key == key) {
                    return pointer->val;
                }
                
                pointer = pointer->next;
            }
        }

        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % 761;
        if (Node* pointer = _nodeArr[index]) {
            if (pointer->key == key) {
                _nodeArr[index] = pointer->next;
                delete pointer;
            } else {
                Node* p = pointer;
                Node* q = pointer->next;
                while (q) {
                    if (q->key == key) {
                        p->next = q->next;
                        delete q;
                        return ;
                    }
                    p = q;
                    q = q->next;
                }
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(int argc, char* argv[])
{
    MyHashMap* obj = new MyHashMap();
    obj->put(1, 2);
    int param2 = obj->get(1);
    std::cout << param2 << std::endl;
    obj->remove(1);
    param2 = obj->get(1);
    std::cout << param2 << std::endl;

    return 0;
}