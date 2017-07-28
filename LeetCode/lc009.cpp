//
//  lc009.cpp
//  LeetCode
//
//  Created by 罗远航 on 21/06/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome1(x);
    }
    
    bool isPalindrome1(int x){
        if(x < 0)
            return false;
        int div = 1;
        while(x/div >= 10) div*=10;
        
        while(x != 0){
            int left = x / div;
            int right = x % 10;
            if(left != right)
                return false;
            x = x % div / 10;
            div /= 100;
        }
        return true;
    }
            
};
