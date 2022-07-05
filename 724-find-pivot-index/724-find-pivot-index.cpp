class Solution {
public:
    int pivotIndex(vector<int>& nums) {
   int len=nums.size();
    if(len==1)
        return nums[0];
    for(int i=0;i<len;i++){
            
          int left=accumulate(nums.begin(),nums.begin()+i,0); 
          int right=accumulate(nums.begin()+i+1,nums.end(),0);
          if(left==right)
              return i;
    }
      return -1;
    }
};