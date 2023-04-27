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
    	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
			return list2;
		}
        else if (!list2) {
			return list1;
		}
		
        ListNode* newHead;
		if (list1->val > list2->val) {
			newHead = list2;
			// Always make list1 smaller and list2 larger
			std::swap (list1, list2);
		} else {
			newHead = list1;
		}
		
        while (list1 != nullptr && list2 != nullptr) {
            ListNode* temp;
			while (list1 != nullptr && list1->val <= list2->val) {
				temp = list1;
				list1 = list1->next;
			}
			temp->next = list2;
			std::swap (list1, list2);   // Again make list1 smaller and list2 larger
        }
        return newHead;
    }
};
