/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "common.h"

using namespace std;

class reverseList
{
  public:
    ListNode *solve(ListNode *head)
    {
        struct ListNode *start = NULL, *p = head, *np = NULL;
        while (p != NULL) {
            np = p->next;
            p->next = start;
            start = p;
            p = np;
        }
        return start;
    }
};
