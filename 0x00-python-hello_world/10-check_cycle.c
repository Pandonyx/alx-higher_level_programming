#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list */
struct ListNode {
int val;
struct ListNode *next;
};

int check_cycle(struct ListNode *head) {
struct ListNode *slow = head;
struct ListNode *fast = head;

while (fast != NULL && fast->next != NULL) {
slow = slow->next;
fast = fast->next->next;

/* If there is a cycle, the slow and fast pointers will meet */
if (slow == fast) {
  return 1;  /* Cycle detected */
}
}

return 0;  /* No cycle found */
}

/* Test case */
int main() {
/* Call the function to check for a cycle */
int hasCycle = check_cycle(head);

/* Create a linked list with a cycle */
struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));

head->val = 1;
node1->val = 2;
node2->val = 3;
node3->val = 4;

head->next = node1;
node1->next = node2;
node2->next = node3;
node3->next = node1;  /* Create a cycle */


/* Print the result */
printf("Has cycle: %d\n", hasCycle);

/* Clean up memory */
free(node3);
free(node2);
free(node1);
free(head);

return 0;
}
