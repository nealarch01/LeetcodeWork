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
    void continuousMerge(ListNode *l, ListNode *res) {
        ListNode *ptrNode = l;
        while(ptrNode != nullptr) {
            ListNode *nNode = new ListNode(ptrNode->val);
            res->next = nNode;
            res = nNode;
            ptrNode = ptrNode->next;
        }
        return;
    }
    void merge(ListNode *l1, ListNode *l2, ListNode *l3) {
        if(l1 == nullptr && l2 == nullptr) return;
        if(l1 == nullptr) {
            continuousMerge(l2, l3);
            return;
        }
        if(l2 == nullptr) {
            continuousMerge(l1, l3);
            return;
        }
        ListNode *nextNode = new ListNode();
        l3->next = nextNode;
        if(l1->val > l2->val) {
            nextNode->val = l2->val;
            l2 = l2->next;
        } else if (l2->val > l1->val) {
            nextNode->val = l1->val;
            l1 = l1->next;
        } else {
            nextNode->val = l1->val;
            ListNode *snNode = new ListNode(l2->val);
            nextNode->next = snNode;
            nextNode = snNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        merge(l1, l2, nextNode);
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode *nNode = new ListNode();
        if(list1->val > list2->val) {
            nNode->val = list2->val;
            merge(list1, list2->next, nNode);
        } else if (list2->val > list1->val) {
            nNode->val = list1->val;
            merge(list1->next, list2, nNode);
        } else {
            nNode->val = list1->val;
            ListNode *snNode = new ListNode(list2->val);
            nNode->next = snNode;
            merge(list1->next, list2->next, snNode);
        }
        return nNode;
    }
};
