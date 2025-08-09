#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* newlist = NULL;
    struct ListNode* now = NULL;
    struct ListNode* start1 = list1;
    struct ListNode* start2 = list2;
    while(start1 != NULL || start2 != NULL){
        if(start1 != NULL && start2 != NULL){
            if(start1 -> val < start2 -> val){
                if(newlist == NULL){
                    newlist = start1;
                    now = start1;
                }else{
                    now -> next = start1;
                    now = start1;
                }
                start1 = start1 -> next;
            }else{
                if(newlist == NULL){
                    newlist = start2;
                    now = start2;
                }else{
                    now -> next = start2;
                    now = start2;
                }
                start2 = start2 -> next;
            }
        }else if(start1 == NULL && start2 != NULL){
            if(newlist == NULL){
                newlist = start2;
                now = start2;
            }else{
                now -> next = start2;
                now = start2;
            }
            start2 = start2 -> next;
        }else if(start1 != NULL && start2 == NULL){
            if(newlist == NULL){
                newlist = start1;
                now = start1;
            }else{
                now -> next = start1;
                now = start1;
            }
            start1 = start1 -> next;
        }
    }
    return newlist;
}