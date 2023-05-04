/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }

        std::unordered_map<Node*, Node*> um;    // { }OldNode, NewNode }
        Node* temp = head;

        while (temp != nullptr) {
            um[temp] = new Node (temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr) {
            um[temp]->next = um[temp->next];
            um[temp]->random = um[temp->random];
            temp = temp->next;
        }
        return um[head];
    }
};
