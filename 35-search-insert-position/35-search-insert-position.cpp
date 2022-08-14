class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int  middle = ( left + right ) / 2;
        while( left <= right ){
             middle = ( left + right ) / 2;
            if( nums[middle] == target ) return middle;
            else{
                if( target < nums[middle] ){
                    right = middle - 1;
                } else if ( target > nums[middle] ){
                    left = middle + 1;
                }
            }
        } return left;
        //return middle>target? middle-1:middle+1 ; unless 0 is target
    }
};