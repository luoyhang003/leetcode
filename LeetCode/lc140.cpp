//
//  lc140.cpp
//  LeetCode
//
//  Created by 罗远航 on 27/03/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        string temp = "";
        bool *flags;
        

        flags = new bool[s.length()];
        backtracking(s, wordDict, 0, flags, temp, result);
        
        return result;
    }
    
    bool backtracking(string s, vector<string>& wordDict, int pos, bool *flags, string &temp, vector<string> &result){
        if(pos == s.length()){
            temp = temp.substr(0, temp.length()-1);
            result.push_back(temp);
            return true;
        }
        if(flags[pos]){
            return false;
        }
        
        bool flag = false;
        
        for(int i = 0; i < wordDict.size(); i++){
            if(compare(wordDict[i], s, pos)){
                string str = temp;
                temp += wordDict[i] + " ";
                bool tempflag = backtracking(s, wordDict, pos+wordDict[i].length(), flags, temp, result);
                temp = str;
                flag = flag || tempflag;
            }
        }
        flags[pos] = !flag;
        
        return flag;
    }
    
    bool compare(string dic, string s, int pos){
        if(s.length()-dic.length() < pos){
            return false;
        }
        for(int i = 0; i < dic.length(); i++){
            if(s[pos+i] != dic[pos]){
                return false;
            }
        }
        return true;
    }
};
