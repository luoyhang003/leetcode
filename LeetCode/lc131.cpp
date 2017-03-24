//
//  lc131.cpp
//  LeetCode
//
//  Created by 罗远航 on 22/03/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution{
public:
    vector<vector<string>> partition(string s){
        //return partition_backtrace(s);
        return partition_recursion(s);
    }
    
    vector<vector<string>> partition_recursion(string s){
        vector<vector<string>> vec;
        
        if(s.length() == 0){
            return vec;
        }
        
        if(isPalindrome_recursion(s, 0, s.length()-1)){
            vector<string> temp;
            temp.push_back(s);
            vec.push_back(temp);
        }
        for(int i = 1; i <= s.length(); i++){
            string left = s.substr(0, i);
            if(isPalindrome_recursion(left, 0, left.length()-1)){
                string right = s.substr(i, s.length()-i);
//                cout << "left:" << left << " | right:"<<right<<"length"<<right.length()<<endl;
                vector<vector<string>> rightVec = partition_recursion(right);
                if(rightVec.size() > 0){
                    for(int j = 0; j < rightVec.size(); j++){
                        vector<string> temp;
                        temp.push_back(left);
                        for(int x = 0; x < rightVec[j].size(); x++){
                            temp.push_back(rightVec[j][x]);
                        }
                        vec.push_back(temp);
                    }
                }
            }
        }
        
        return vec;
    }

    
    vector<vector<string>> partition_backtrace(string s){
        vector<vector<string>> vec;
        vector<string> temp;
        backtrace(vec, temp, s, 0);
        return vec;
    }
    
    void backtrace(vector<vector<string>> &vec, vector<string> &temp, string s, int start){
        if(start == s.length()){
            vec.push_back(temp);


        }
        else{
            for(int i = start; i < s.length(); i++){
                if(isPalindrome_recursion(s, start, i)){
                    temp.push_back(s.substr(start, i-start+1));
                    backtrace(vec, temp, s, i+1);
                    temp.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome_recursion(string s, int i,int j){
        if(i == j){
            return true;
        }
        else{
            if(s[i] == s[j]){
                i++;
                j--;
                if(i < j){
                    return isPalindrome_recursion(s, i, j);
                }
                else{
                    return true;
                }
            }
            else{
                return false;
            }
        }
    }
    
    bool isPalindrome_doublepoints(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isPalindrome_reverse(string s, int i, int j){
        string r = s;
        reverse(s.begin(),s.end());
        if(s.compare(r)!=0){
            return false;
        }
        return true;
    }
    
    void printVec(vector<vector<string>> vec){
        cout << "---------"<<endl;
        for(int i = 0; i < vec.size(); i++){
            vector<string> temp = vec[i];
            for(int j = 0; j < temp.size(); j++){
                cout << "[" << temp[j] << "]";
            }
            cout << endl;
        }
        cout << "---------"<<endl;
    }
    
};
