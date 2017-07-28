//
//  lc013.cpp
//  LeetCode
//
//  Created by 罗远航 on 22/06/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

/*
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 * M:1000 D:500 C:100 L:50 X:10 V:5 I:1
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        return romanToInt1(s);
    }
    
    int romanToInt1(string s) {
        int result = 0;
        
        if(s.length() == 0)
            return 0;
        
        int length = s.length()-1;
        
        for(int i = length; i >=0; i--){
            char c = s[i];
            switch (c) {
                case 'M':
                    result += 1000;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'C':
                    result += 100*(result >= 500? -1:1);
                    break;
                case 'L':
                    result += 50*(result >= 100? -1:1);
                    break;
                case 'X':
                    result += 10*(result >= 50? -1:1);
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'I':
                    result += (result >= 5? -1:1);
                    break;
                default:
                    break;
            }
        }
        
        
        return result;
    }
    
    int romanToInt2(string s) {
        if(s.length() == 0)
            return 0;
        
        map<char, int> m;
        m.insert(map<char, int>::value_type('M',1000));
        m.insert(map<char, int>::value_type('D',500));
        m.insert(map<char, int>::value_type('C',100));
        m.insert(map<char, int>::value_type('L',50));
        m.insert(map<char, int>::value_type('X',10));
        m.insert(map<char, int>::value_type('V',5));
        m.insert(map<char, int>::value_type('I',1));
        
        int length = s.length();
        int result = m[s[s.length()-1]];
        
        for(int i = length-2; i >= 0; i--){
            if(m[s[i+1]] <= m[s[i]])
                result += m[s[i]];
            else
                result -= m[s[i]];
        }
        return result;
    }
};
