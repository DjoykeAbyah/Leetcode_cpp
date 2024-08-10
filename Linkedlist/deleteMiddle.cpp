#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//delete middle note return head of modified list
//middle is n/2 using 0 
//size /2 +1 for correct index?

//not sure how that translates into getting to that node yet
//want to use pointer to currect and temp
//and previous 
//so I say listlast next = previous?

//I need to loop to figure out the size of the list

//think about edge cases
//think carefully about input
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

		if (head == nullptr || head->next == nullptr) {
			return nullptr;
		}

		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *prev = head;

		while (fast != nullptr && fast->next != nullptr) {
			
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = slow->next;
		delete(slow);
		return head;
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

	Solution solution;

	ListNode *display = solution.deleteMiddle(node1);

	while (display != nullptr) {
		std::cout << display->val << std::endl;
		display = display->next;
	}	

	return 0;
}