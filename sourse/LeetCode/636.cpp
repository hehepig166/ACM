//https://leetcode-cn.com/problems/partition-list/comments/
#include <cstdio>



struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* partition(ListNode* head, int x) {
        ListNode *small=new ListNode;
        ListNode *smallHead=small;
        ListNode *large=new ListNode;
        ListNode *largeHead=large;
        
        while (head!=nullptr) {
        	if (head->val < x) {
        		small->next=head;
        		small=small->next;
			}
			else {
				large->next=head;
				large=large->next;
			}
			head=head->next;
		}

        large->next=nullptr;
        small->next=largeHead->next;
        
        return smallHead->next;

    }
};

int main()
{
	
	return 0;
}
