//
//  lc020.cpp
//  LeetCode
//
//  Created by 罗远航 on 05/07/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        return isValid1(s);
    }
    
    bool isValid1(string s) {
        stack<char> stack;
        
        if (s.size() == 0) {
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(stack.empty()){
                stack.push(c);
            }
            else if(stack.top() == '(' && c == ')') {
                stack.pop();
            }
            else if(stack.top() == '[' && c == ']') {
                stack.pop();
            }
            else if(stack.top() == '{' && c == '}') {
                stack.pop();
            }
            else{
                stack.push(c);
            }
        }
        
        return stack.empty();
        
        
    }
};
