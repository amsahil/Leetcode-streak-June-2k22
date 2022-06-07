//Leetcode June Streak Day 3/30

/* 
Problem :- 304.Range Sum Query 2D-Immutable[M]

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Implement the NumMatrix class:
.NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
.int sumRegion(int row1, int col1, int row2, int col2)
 Returns the sum of the elements of matrix inside the rectangle defined by 
 its upper left corner (row1, col1) and lower right corner (row2, col2).

Example 1:
Input:
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output:
[null, 8, 11, 12]
*/

class NumMatrix {
public:
    vector<vector<int>>sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();       
        int col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
         for(int i=1;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        sum=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total=sum[row2][col2];
        int extrasum =(col1!=0?sum[row2][col1-1]:0)+(row1!=0?sum[row1-1][col2]:0)-((row1!=0 && col1!=0)?sum[row1-1][col1-1]:0);
        return total-extrasum;
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */