// Merge Sort on Doubly Linked List
// Problem Link: https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1
struct Node *merge(struct Node *first, struct Node *second) {
    // base cases when either of two halves is null.
    if (!first)
        return second;
    if (!second)
        return first;

    // comparing data in both halves and storing the smaller in result and
    // recursively calling the merge function for next node in result.
    if (first->data < second->data) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        // returning the resultant list.
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        // returning the resultant list.
        return second;
    }
}

// Function to split the list into two halves.
struct Node *splitList(struct Node *head) {
    // using two pointers to find the midpoint of list
    struct Node *fast = head, *slow = head;

    // first pointer, slow moves 1 node and second pointer, fast moves
    // 2 nodes in one iteration.
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // slow is before the midpoint in the list, so we split the
    // list in two halves from that point.
    struct Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Function to sort the given doubly linked list using Merge Sort.
struct Node *sortDoubly(struct Node *head) {
    if (!head || !head->next)
        return head;

    // splitting the list into two halves.
    struct Node *second = splitList(head);

    // calling the sortDoubly function recursively for both parts separately.
    head = sortDoubly(head);
    second = sortDoubly(second);

    // calling the function to merge both halves.
    return merge(head, second);
    }