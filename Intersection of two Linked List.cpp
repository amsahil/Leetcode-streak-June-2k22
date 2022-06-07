//Leetcode June Streak Day 6/30

/* 
PROBLEM:- 160. Intersection of Two Linked Lists[E]

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Example 1.
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3

Output: Intersected at '8'

Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
*/
Solution:-

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      
      if(headA ==NULL || headB==NULL)
        return NULL;
      
      ListNode *a = headA;
      ListNode *b = headB;
      
      // if a&b have different len,then we will stop the loop after second iteration

      while(a!=b)
      {

      // for the end of first iteration,we just reset the pointer to the head of another linkedlist

        a = a == NULL? headB: a->next;
        b = b == NULL? headA: b->next;
      }
      return a;
        
    }
};

/*
TIME COMPLEXITY:  O(2m)
SPACE COMPLEXITY: O(1)
*/