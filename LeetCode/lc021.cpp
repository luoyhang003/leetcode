//
//  lc021.cpp
//  LeetCode
//
//  Created by 罗远航 on 06/07/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <iostream>


using namespace std;


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
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return mergeTwoLists1(l1, l2);
    }
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists1(l1->next, l2);
            return l1;
        }
        else{
            l2.next = mergeTwoLists1(l1, l2->next);
            return l2;
        }
        
    }
};
