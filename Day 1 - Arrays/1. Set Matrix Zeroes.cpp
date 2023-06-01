// INPLACE OPTIMAL    TC-O(m*n + m*n)    SC-O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool>dummyRow(cols);     // stores whether particular column contains 0 or not
        vector<bool>dummyCol(rows);     // stores whether particular row contains 0 or not

        // iterate over each cell and update dummyRow and dummyCol if cell contains 0
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j]==0){
                    dummyCol[i] = 1;
                    dummyRow[j] = 1;
                }
            }
        }

        // if dummyRow[idx] is 1, make whole col 0 and
        // if dummyCol[idx] is 1, make whole row 0
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(dummyCol[i] || dummyRow[j])
                    matrix[i][j] = 0;
            }
        }
    }
};


// INPLACE IF ELEMENTS ARE POSITIVE ONLY    TC-O(m*n*(m+n) + m*n)    SC-O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // iterate over each cell
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                // if the cell is 0
                if(matrix[i][j] == 0){
                    // ṃake its entire row -1
                    for(int k=0; k<n; k++){
                        if(matrix[i][k] != 0)
                            matrix[i][k] = -1;
                    }

                    // make its entire col -1
                    for(int k=0; k<m; k++){
                        if(matrix[k][j] != 0)
                            matrix[k][j] = -1;
                    }
                }

            }
        }

        // iterate over each cell
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // if the cell is -1, that row / col contains 0
                if(matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
};


// OUTPLACE    TC-O(m*n*(m+n))    SC-O(m*n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>temp = matrix;

        // iterate over each cell in temp
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                // if cell is 0, make its entire row and col 0 in matrix
                if(temp[i][j]==0){
                    // entire row
                    for(int k=0; k<n; k++)
                        matrix[i][k]=0;

                    // entire col
                    for(int k=0; k<m; k++)
                        matrix[k][j]=0;
                }
            }
        }
    }
};