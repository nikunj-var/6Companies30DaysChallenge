#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *start = new ListNode(0);
        start->next = head;
        unordered_map<int, ListNode *> mp;
        mp[0] = start;
        ListNode *ptr = start;
        int sum = 0;
        while (ptr != NULL)
        {
            sum += ptr->val;
            mp[sum] = ptr;
            ptr = ptr->next;
        }
        ptr = start;
        sum = 0;
        while (ptr)
        {
            sum += ptr->val;
            ptr->next = mp[sum]->next;
            ptr = ptr->next;
        }
        return start->next;
    }
};