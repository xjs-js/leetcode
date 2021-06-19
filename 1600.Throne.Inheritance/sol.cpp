struct TNode {
    string _name;
    vector<TNode*> _children;
    TNode(string& name) : _name(name) {}
};


class ThroneInheritance {
private:
    TNode* _root;
    unordered_map<string, TNode*> _index;    // 索引
    unordered_set<string> _book; // 生死簿

    void InOrder(TNode* node, vector<string>& arr) {
        if (!node) return;

        arr.push_back(node->_name);
        vector<TNode*>& children = node->_children;
        for (int i = 0; i < children.size(); ++i) {
            InOrder(children[i], arr);
        }
    }

public:
    ThroneInheritance(string kingName) {
        _root = new TNode(kingName);
        _index[kingName] = _root;
    }
    
    void birth(string parentName, string childName) {
        if (TNode* parent = _index[parentName]) {
            TNode* child = new TNode(childName);
            parent->_children.push_back(child);
            _index[childName] = child;
        }
    }
    
    void death(string name) {
        _book.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> arr;
        InOrder(_root, arr);

        vector<string> relt;
        for (int i = 0; i < arr.size(); ++i) {
            if (!_book.count(arr[i])) {
                relt.push_back(arr[i]);
            }
        }
        return relt;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
