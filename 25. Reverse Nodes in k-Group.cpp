/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* node) {
        int count = 1;
        while (node != nullptr) {
            count++;
            node = node->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        ListNode* nxt = head;
        ListNode* oldHead = new ListNode(0, head);
        for (int i = 0; i < k && nxt != nullptr; i++) {
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            curr->next = prev;
        }
        if (getLength(nxt) - k > 0) oldHead->next->next = reverseKGroup(nxt, k);
        else oldHead->next->next = nxt;
        return curr;
    }
};
