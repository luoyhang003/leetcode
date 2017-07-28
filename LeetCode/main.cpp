//
//  main.cpp
//  LeetCode
//
//  Created by 罗远航 on 22/03/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <iostream>
#include <vector>
#include "lc026.cpp"

using namespace std;
int main() {
    Solution s;
    
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    
    cout << s.removeDuplicates(v) <<endl;
    
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<endl;


}
