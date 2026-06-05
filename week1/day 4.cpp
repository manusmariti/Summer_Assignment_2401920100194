QUES MATRIX DIAGONAL SUM
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            sum+=mat[i][i];
            sum+=mat[i][n-i-1];
        }
        if(n%2!= 0){
            sum-=mat[n/2][n/2];
        }
        return sum;
    }
};
QUES RESHAPE THE MATRIX
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> result(r, vector<int>(c));
        if(m*n!= c*r){
            return mat;
        }
        else{
            for(int i=0;i<m*n;i++){
                result[i/c][i%c]=mat[i/n][i%n];
            }
        }
        return result;
    }
};
QUES SPIRAL MATRIX
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> ans;
         int rowbeg=0;
         int rowend=matrix.size()-1;
         int colbeg=0;
         int colend=matrix[0].size()-1;
         int i;
         while(rowbeg<=rowend && colbeg<=colend){
            for(i= colbeg;i<=colend;i++){
                ans.push_back(matrix[rowbeg][i]);
            }
            rowbeg++;
            for(i=rowbeg;i<=rowend;i++){
                ans.push_back(matrix[i][colend]);
            }
            colend--;
            if(rowbeg<=rowend){
                for(i=colend;i>=colbeg;i--){
                    ans.push_back(matrix[rowend][i]);
                }
                rowend--;
            }
             
             if(colbeg<=colend){
                for(i=rowend;i>=rowbeg;i--){
                    ans.push_back(matrix[i][colbeg]);
                }
                colbeg++;
             } 
            
         }
        return ans;
    }
};
QUES OOPS
class KidUsers implements LibraryUser {
    int age;
    String bookType;

    public void registerAccount() {
        if (age < 12) {
            System.out.println("You have successfully registered under a Kids Account");
        } else {
            System.out.println("Sorry, Age must be less than 12 to register as a kid");
        }
    }

    public void requestBook() {
        if (bookType.equals("Kids")) {
            System.out.println("Book Issued successfully, please return the book within 10 days");
        } else {
            System.out.println("Oops, you are allowed to take only kids books");
        }
    }
}
