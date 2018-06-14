/**
 * Definition for singly-linked list.
 */
#include "common.h"

class addTwoNumbers {
public:
    ListNode* solve(ListNode* l1, ListNode* l2) {
        ListNode *lp = NULL, *res = NULL;
        int addon = 0, num = 0;
        while (l1 != NULL || l2 != NULL) {
            
            if (l1 != NULL) {
                num += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                num += l2->val;
                l2 = l2->next;
            }
            if (lp == NULL) {
                lp = new ListNode((num + addon) % 10);
                res = lp;
            } else {
                lp->next = new ListNode((num + addon) % 10);
                lp = lp->next;
            }
            addon = (num + addon) / 10;
            num = 0;
        }
        if (addon > 0) {
            lp->next = new ListNode(addon);
        }
        return res;
    };
};