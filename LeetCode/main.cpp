//
//  main.cpp
//  LeetCode
//
//  Created by 罗远航 on 22/03/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//

#include <iostream>
#include "lc079.cpp"
int main(int argc, const char * argv[]) {
    Solution s;
    
    vector<char> v1;
    v1.push_back('a');
    v1.push_back('a');
//    v1.push_back('C');
//    vector<char> v2;
//    v2.push_back('F');
//    v2.push_back('E');
//    v2.push_back('D');
//    vector<char> v3;
//    v3.push_back('C');
//    v3.push_back('Q');
//    v3.push_back('B');
    
    vector<vector<char>> matrix;
    matrix.push_back(v1);
//    matrix.push_back(v2);
//    matrix.push_back(v3);
    
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    if(s.exist(matrix, "aa")){
        cout << "TRUE" << endl;
    }

    

}
