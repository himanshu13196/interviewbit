/**
 * Merge k sorted linked lists and return it as one sorted list.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {

    ListNode *head = NULL, *prev= NULL;
    int idx = 0, k;
    int sz;
    vector<ListNode*> heads = A;
    map<int, vector<int>> min;

    for(; idx < heads.size(); idx++) {
        if(heads[idx] != NULL) {
            min[heads[idx]->val].push_back(idx);
        }
    }

    while(min.size() > 0) {

         k = (min.begin())->first;
         idx = min[k].back();
         min[k].pop_back();

         if(min[k].size() == 0) {
            min.erase(k);
         }

        if(head == NULL) {
            head = heads[idx];
            prev = head;
        } else {
            prev->next = heads[idx];
            prev = heads[idx];
        }

        heads[idx] = heads[idx]->next;

        if(heads[idx] != NULL) {
            k = heads[idx]->val;
            min[k].push_back(idx);
        }

    }

    if(prev != NULL) {
        prev->next = NULL;
    }

    return head;

}
