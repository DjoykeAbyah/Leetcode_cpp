#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode *previous = nullptr;
		ListNode *current = head;
        while (current != nullptr) {
			ListNode *temp = nullptr;
			temp = current->next;
			current->next = previous;
			previous = current;
			current = temp;
		}
		return previous;
    }
    ListNode* reverseList2(ListNode* head) {
        // Base case: if the list is empty or has only one node, return head
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Recursive step: reverse the rest of the list
        ListNode* newHead = reverseList2(head->next);
        
        // Reverse the current node's link
        head->next->next = head;
        head->next = nullptr;
        
        // Return the new head of the reversed list
        return newHead;
    }
};



int main() {
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	ListNode *head = node1;
	Solution solution;

	ListNode* reversedHead = solution.reverseList(head);

	while(reversedHead != nullptr) {
		std::cout << reversedHead->val << std::endl;
		reversedHead = reversedHead->next;
	}
	return 0;
}