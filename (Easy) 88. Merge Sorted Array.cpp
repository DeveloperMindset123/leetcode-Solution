class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //basic approach:
        /*Copy elements of second array into first and sort the merged array */
        //approach 2: two pointers approach, where the time complexity will be O(k) and space complexity will be O(1)

        //The prompt told us that length of nums1 is (m + n) and length of nums2 is (n), meaning nums1[m - n] = last nonzero element of array nums1

        //let us declare our pointers:
        int p1 = m - 1;  //represents the last index of nonnegative element of nums1, beyong p1, the values stored at the remaining indexes are all 0s
        int p2 = n - 1;  //represents the last index of array nums2
        int i = nums1.size() - 1;

        //since our array is already sorted for nums1, to maintain that, we will start at the end of the last index of nums1 and fill in our values from there
        while (i > p1) {
            //copy in the values of nums2 in reverse order
            nums1[i] = nums2[p2];  //replace 0s with elements in nums2 starting from the end
            //decrement pointer 2 and index i
            i--;
            p2--;
        }
    
    }
};
