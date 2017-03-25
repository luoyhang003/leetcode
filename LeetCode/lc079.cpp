//
//  lc079.cpp
//  LeetCode
//
//  Created by 罗远航 on 25/03/2017.
//  Copyright © 2017 罗远航. All rights reserved.
//  Runtime: 46 ms

//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || word.length() == 0 ){
            return false;
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(search(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, string word, int x, int y, int pos){
        if(pos == word.length()){
            return true;
        }
        if(x < 0 || y < 0 || y >= board[x].size() || x >= board.size()){
            return false;
        }
        if(board[x][y] != word[pos]){
            return false;
        }
        char temp = board[x][y];
        board[x][y] = '*';
        
        bool result = search(board, word, x-1, y, pos+1)
        || search(board, word, x+1, y, pos+1)
        || search(board, word, x, y+1, pos+1)
        || search(board, word, x, y-1, pos+1);
        
        board[x][y] = temp;
        
        return result;
    }
};
