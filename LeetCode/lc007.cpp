//
//  lc007.cpp
//  LeetCode
//
//  Created by 罗远航 on 21/06/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <iostream>
#include <climits>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isOverflow(__int64_t x){
        if(x >= INT_MIN && x <= INT_MAX)
            return false;
        return true;
    }
    
    int reverse(int x) {
        if(x >= 0){
            int result = 0;
            stringstream stream;
            stream << x;
            string s = stream.str();

            ::reverse(s.begin(),s.end());

            __int64_t temp;
            stream = stringstream(s);
            stream>>temp;

            if(isOverflow(temp)){
                return 0;
            }
            return temp;

        }
        else if(x < 0){
            stringstream stream;
            stream << x;
            string s = stream.str();
            ::reverse(s.begin(),s.end());
            __int64_t temp;
            stream = stringstream(s);
            stream>>temp;
            if(!isOverflow(temp))
                return 0-temp;
            return 0;
        }
        else{
            return 0;
        }
    }
};
