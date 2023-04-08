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
    Node* duplicateNode(int val) {
        Node* newNode = new Node;
        newNode->val = val;
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> um; // {OldNode, NewNode}
        std::queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (um.find(temp) == um.end()) {
                um[temp] = duplicateNode(temp->val);
                for(auto& e: temp->neighbors) {
                    q.push(e);
                }
            }
        }
        for (auto& each: um) {
            for (auto e: each.first->neighbors) {
                each.second->neighbors.push_back(um[e]);
            }
        }
        return um[node];
    }
};
