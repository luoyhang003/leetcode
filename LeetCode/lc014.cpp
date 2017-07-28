//
//  lc014.cpp
//  LeetCode
//
//  Created by 罗远航 on 04/07/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        int sl=0;
        if(strs.size()<=0) return result;
        while(1){
            if(strs[0].size()<=sl) return result;
            for(int i=1;i<strs.size();i++){
                if(strs[i].size()<=sl) return result;
                if(strs[i][sl]!=strs[0][sl]) return result;
            }
            result.push_back(strs[0][sl]);
            sl++;
        }
        return result;
    }
};
