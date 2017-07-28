//
//  lc026.cpp
//  LeetCode
//
//  Created by 罗远航 on 26/07/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicatesA(nums);
    }

    
    int removeDuplicatesA(vector<int>& nums) {
        int size = nums.size();
        for(int i = 1; i < size; i++){
            if(nums[i] == nums[i-1]){
                nums.erase(nums.begin()+i-1);
                i--;
                size--;
            }
        }
        
        return nums.size();
    }
    

};
