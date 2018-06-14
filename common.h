#ifndef COMMON_H
#define COMMON_H

#include <cstdlib>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif