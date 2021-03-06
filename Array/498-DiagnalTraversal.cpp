/**************************************************************************
 * File Name : 498-DiagnalTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-04-2017
 *
 * Last Modified : Sun Apr 23 19:45:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        vector<int> res;
        if(m == 0 || n == 0) return res;
        
        vector<vector<int>> tmp(m+n-1, vector<int>{});
        for(int i=0; i<m+n-1; i++) {
            int row = max(0, i-n+1);
            int col = min(n-1, i);
            for(; row<m && col>=0; row++, col--) tmp[i].push_back(matrix[row][col]);
        }
        
        for(int i=0; i<m+n-1; i++){
            if(i%2) res.insert(res.end(), tmp[i].begin(), tmp[i].end());
            else res.insert(res.end(), tmp[i].rbegin(), tmp[i].rend());
        }
        
        return res;
    }
};
