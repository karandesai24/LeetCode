class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> data(nums.size()+1,0);
        for(int i=0; i<nums.size(); i++) 
            data[ nums[i] ] = 1; 
        for(int i=0; i<nums.size()+1; i++) 
            if( !data[i] )
                return i;  
        return 0;
    }
};
/*
 int mask = 0;
        for(int i=0; i<=nums.size(); i++) mask = mask ^ i;
        for(int i=0; i<nums.size(); i++) mask = mask ^ nums[i];
        return mask;
        */