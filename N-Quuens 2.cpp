//Leetcode June Streak Day 5/30

/* 
Problem :- 52.N-Queens 2
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.


Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.


Example 2:
Input: n = 1
Output: 1



*/


class Solution {
public:
    int totalNQueens(int n) {
      
      vector<bool>col(n , true);
      vector<bool>maindg(2*n-1 , true);
      vector<bool>antidg(2*n-1 , true);
      vector<int>row(n , 0);
      int count = 0;
      dfs(0 , row, col, maindg, antidg, count);
        return count;
    }
  
  void dfs(int i , vector<int>&row, vector<bool>&col,vector<bool>&maindg,vector<bool>&antidg,int &count)
  {
    if(i  == row.size())
    {
      count++;
      return;
    }
    
    for(int j=0; j<col.size();j++)
    {
      if(col[j] && maindg[i+j] && antidg[i+col.size()-1-j])
      {
        row[i] = j;
        col[j] = maindg[i+j] = antidg[i+col.size()-1-j] = false;
        dfs(i+1, row,col,maindg,antidg,count);
        //backtracking
        col[j] = maindg[i+j] = antidg[i+col.size()-1-j] = true;
      }
      
    }
    
    
    
  }
      
        
    
};