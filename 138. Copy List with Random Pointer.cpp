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

// Optimized
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }

        Node* iter = head;
        Node* nxt;

        // Creating new nodes and handling next pointer
        // Also merging 2 LL, side by side: oldNode1->newNode1->oldNode2->newNode2->oldNode3->newNode3
        while (iter != nullptr) {
            nxt = iter->next;

            Node* newNode = new Node (iter->val);
            newNode->next = nxt;
            iter ->next = newNode;

            iter = nxt;
        }
        iter = head;

        // Handling random pointer
        while (iter != nullptr) {
            if (iter->random != nullptr) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        // Restore the original list, and extract the copy list
        iter = head;
        Node* copy;
        Node* newHead = new Node(0);
        newHead->next = iter->next;

        while (iter != nullptr) {
            nxt = iter->next->next;
            copy = iter->next;

            iter->next = nxt;
            if (nxt != nullptr) {
                copy->next = nxt->next;
            } else {
                copy->next = nullptr;
            }
            // restore the original list
            iter->next = nxt;
            
            iter = nxt;
        }
        return newHead->next;
    }
};
