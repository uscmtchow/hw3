#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

Node* llpivot_helper(Node* head, Node*& smaller, Node*& larger, int pivot);

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  head = llpivot_helper(head, smaller, larger, pivot);
}

Node* llpivot_helper(Node* head, Node*& smaller, Node*& larger, int pivot) {
	if (head == nullptr) {
		return nullptr;
	}
	
	head->next = llpivot_helper(head->next, smaller, larger, pivot);
  if (head->val > pivot) {
    head->next = larger;
		larger = head;
  }
  else {
    head->next = smaller;
		smaller = head;
  }

	return head;
}
