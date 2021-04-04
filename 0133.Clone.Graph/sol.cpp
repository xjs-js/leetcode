/**
 * @date: 2021-04-04 20:48
 * @note: 这是我第一次在leetcode中遇见图的题目
 */


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node*, Node*> _oldNew;
public:
    /**
     *  这题还是挺简单的，维护几个数据结构：
     *  1. set<Node*>, 存放访问过的顶点
     *  2. map<Node*, Node*>, 存放旧新节点地址的对应关系
     *  3. queue<Node*>, 存放未访问的顶点
     */
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        queue<Node*> que;   // 待访问队列
        set<Node*> visited; // 已经访问的节点

        que.push(node);
        while (!que.empty()) {
            Node* front = que.front();
            que.pop();

            if (!visited.count(front)) {
                Node* newFront = getNew(front);
                vector<Node*>& neighbors = front->neighbors;
                for (int i = 0; i < neighbors.size(); ++i) {
                    Node* n = neighbors[i];
                    Node* n_new = getNew(n);
                    newFront->neighbors.push_back(n_new);
                    if (!visited.count(n)) {
                        que.push(n);
                    }
                }
                visited.insert(front);
            }
        }

        return getNew(node);
    }

    Node* getNew(Node* old) {
        if (_oldNew.find(old) != _oldNew.end()) {
            return _oldNew[old];
        } else {
            Node* newNode = new Node(old->val);
            _oldNew[old] = newNode;
            return newNode;
        }
        return nullptr;
    }
};
