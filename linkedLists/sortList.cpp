//Sort a linked list in O(n log n) time using constant space complexity.
//Can't use recursion as function call stack does not take constant space

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::sortList(ListNode* A) {

	ListNode *head = A, *temp1, *temp2, *prev, *curr, *bound;
	temp1 = A;
	int sz = 0, count;
	while (temp1 != NULL) {
		temp1 = temp1->next;
		sz++;
	}

	for (int i = 1; i < sz; i = i * 2) {

		count = 0;
		temp1 = head;
		temp2 = head;
		prev = NULL;
		for (int j = 0; j < i; j++) {
			temp2 = temp2->next;
		}

		while (1) {

			bound = temp2;
			for (int j = 0; j < i; j++) {
				if (bound != NULL)
					bound = bound->next;
			}

			int tcount1 = 0, tcount2 = 0;
			int loopC = min(2 * i, sz - count);

			for (int k = 0; k < loopC; k++) {
				count++;
				if (tcount2 == i || temp2 == NULL || (temp1->val <= temp2->val && tcount1 < i)) {
					curr = temp1;
					temp1 = temp1->next;
					tcount1++;
				} else {
					curr = temp2;
					temp2 = temp2->next;
					tcount2++;
				}

				if (prev == NULL) {
					prev = curr;
					head = curr;
				} else {
					prev->next = curr;
					prev = curr;
				}

			}

			temp1 = bound;
			temp2 = bound;
			prev->next = bound;

			for (int l = 0; l < i; l++) {
				if (temp2 == NULL)
					break;
				temp2 = temp2->next;
			}

			if (temp2 == NULL)
				break;
		}
	}
	return head;
}
