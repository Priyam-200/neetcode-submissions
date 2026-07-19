class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int e=(m*n)-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int rowIndex=mid/n;
            int colIndex=mid%n;
            if(matrix[rowIndex][colIndex]==target){
                return true;
            }
            else if(matrix[rowIndex][colIndex]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
};
