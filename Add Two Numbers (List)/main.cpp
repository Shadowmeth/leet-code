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
private:
    void newNode(ListNode** walk, int val) {
        (*walk)->next = new ListNode;
        *walk = (*walk)->next;
        (*walk)->val = val;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* walk = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            if (sum >= 10) {
                sum = sum % 10;
                carry = 1;
            } else {
                carry = 0;
            }

            if (!head) {
                // only first time
                head = new ListNode;
                head->val = sum;
                walk = head;
            } else {
                newNode(&walk, sum);
            }
            
        }

        // if carry is left over when both lists end then we need to
        // add it manually
        if (carry) {
            newNode(&walk, carry);
        }

        return head;
    }
};
