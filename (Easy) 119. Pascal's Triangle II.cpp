class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //Refer to the solution listed on Github repository known as 118. Pascal's Triangle to solve this problem with some slight modification to the code below

        //Dynamic Programming Approach and why it works:
       /*
       * 1. Base Case: The value at the beginning or end of a row is always 1.
       * 2. Recurrence Relation: Each number is the sum of the two numbers directly above it. 

       The following is the formula: triangle[row][col] = triangle[row-1][col-1] + triangle[row-1][col]
       * Time Complexity: O(N^2) where N is the number of rows. Here is a total number of iteration are: N * (N + 1) / 2 which creates the time complexity.

       * Space Complexity: O(1)
       */

        vector<vector<int>> resultVector(rowIndex+1);  //since rowIndex indicates the last index, it doesn't account for the total number of rows numRows = rowIndex + 1 and numRows also represents the size of the 2d vector
        for (int i = 0; i <= rowIndex; i++) {  //we will iterate until i == numRows, this is the outer loop iteration
            resultVector[i].resize(i+1, 1); //resize the vector to the length of current index i + 1 back to size 1, thus resetting the vector's size back to 1 after each inner loop iteration
            for (int j = 1; j < i; j++) {  //inner loop starts at j index, which is at 1 and will increment until j is less than i
                resultVector[i][j] = resultVector[i-1][j-1] + resultVector[i-1][j];  //set the value using the formula shown here
            }
        }
        return resultVector[rowIndex];  //return the resulting 2D vector's index parameter specified
    }
};
