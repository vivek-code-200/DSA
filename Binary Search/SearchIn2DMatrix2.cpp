// LeetCode - Medium : 240. Search a 2D Matrix II

#include<iostream>
using namespace std;
#include<vector>

bool SearchInMatrix(vector<vector<int>> &matrix, int target){
    int n=matrix.size();
    int m=matrix[0].size();

    int row=n-1;
    int col=0;

    while (row>=0 and col<m)
    {
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]<target){
            col++;
        }
        else{
            row--;
        }
    }

    return false;
}

int main(){
    vector<vector<int>> matrix={{5,8,10,12},{6,9,12,15},{11,13,16,20}};

    bool result = SearchInMatrix(matrix,20);

    if(result){
        cout<<"Element Found!";
    }
    else{
        cout<<"Element not Found!";
    }
}

// Exact LeetCode Question :

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
 
// Example 1:

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

// Example 2:

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= n, m <= 300
// -109 <= matrix[i][j] <= 109
// All the integers in each row are sorted in ascending order.
// All the integers in each column are sorted in ascending order.
// -109 <= target <= 109