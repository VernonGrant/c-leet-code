#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order, and each of their nodes
contains a single digit. Add the two numbers and return the sum as a linked
list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
    - The number of nodes in each linked list is in the range [1, 100].
    - 0 <= Node.val <= 9
    - It is guaranteed that the list represents a number that does not have leading zeros.
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
   The following solution passes and was created by someone else.
   TODO: Check why this works.

    struct ListNode* addTwoNumbersAlt(struct ListNode* l1, struct ListNode* l2){
        struct ListNode head, *cur=&head, *tp;
        register char acc=0;
        while(l1 && l2)
        {
            cur->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            cur = cur->next;
            acc = l1->val + l2->val + acc/10;
            cur->val = acc % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        tp = ((l1 == NULL) ? l2:l1);
        while (tp)
        {
            cur->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            cur = cur->next;
            acc = tp->val + acc / 10;
            cur->val = acc % 10;
            tp = tp->next;
        }
        if(acc / 10)
        {
            cur->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            cur = cur->next;
            cur->val = 1;
        }
        cur->next = NULL;
        return head.next;
    }
*/


// TODO: Find a solution that will work independent of the number length.

/**
 * This is logically the correct approach, but this solution will not work as
 * numbers will overflow.
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int num_a = 0;
    int num_b = 0;

    // Get number A.
    struct ListNode *a_current_node = l1;
    for(int offset = 0;;offset++) {
        num_a += a_current_node->val * pow(10, offset);
        if (a_current_node->next == NULL) {
            break;
        } else {
            a_current_node = a_current_node->next;
        }
    }

    // Get number B.
    struct ListNode *b_current_node = l2;
    for(int offset = 0;;offset++) {
        num_b += b_current_node->val * pow(10, offset);
        if (b_current_node->next == NULL) {
            break;
        } else {
            b_current_node = b_current_node->next;
        }
    }

    // Calculate our final number.
    int final_value = num_a + num_b;

    // We now need to do the opposite.
    // Setup our root node.
    struct ListNode *r_node = NULL;
    struct ListNode *f_current_node = NULL;

    // Account for zero
    if (final_value == 0) {
        r_node = malloc(sizeof(struct ListNode));
        r_node->val = 0;
        r_node->next = NULL;
        return r_node;
    }

    int fraction = final_value;
    while (fraction > 0) {
        int current_digit = fraction % 10;
        fraction = fraction / 10;

        // Create our node.
        if (f_current_node == NULL) {
            f_current_node = malloc(sizeof(struct ListNode));
            f_current_node->val = current_digit;
            f_current_node->next = NULL;

            // Set our root node;
            r_node = f_current_node;
        } else {
            // Set the current's next node.
            f_current_node->next = malloc(sizeof(struct ListNode));
            f_current_node->next->val = current_digit;
            f_current_node->next->next = NULL;

            // Set the new current.
            f_current_node = f_current_node->next;
        }
    }

    return r_node;
}

int main(int argc, char *argv[])
{
    // Testing Number: 243
    struct ListNode a_three;
    a_three.val = 3;
    a_three.next = NULL;

    struct ListNode a_four;
    a_four.val = 4;
    a_four.next = &a_three;

    struct ListNode a_root;
    a_root.val = 2;
    a_root.next = &a_four;

    // Testing Number: 564
    struct ListNode b_four;
    b_four.val = 4;
    b_four.next = NULL;

    struct ListNode b_six;
    b_six.val = 6;
    b_six.next = &b_four;

    struct ListNode b_root;
    b_root.val = 5;
    b_root.next = &b_six;

    struct ListNode *result = addTwoNumbers(&a_root, &b_root);
    if (result == NULL) {
        printf("The result pointer was NULL\n");
        return EXIT_FAILURE;
    }

    struct ListNode *res_current = result;
    for(int offset = 0;;offset++) {
        printf("%u", res_current->val);
        if (res_current->next == NULL) {
            break;
        } else {
            res_current = res_current->next;
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}
