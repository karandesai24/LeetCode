class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       vector<int>sumarray;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
          sum=sum+nums[i];
            sumarray.push_back(sum);
        }
        
        int rem;
        int count=0;
        map<int,int>mymap;
        for(int i=0;i<sumarray.size();i++)
        {
            rem=sumarray[i]%k;
            if(rem<0) rem+=k;
            if(mymap[rem]!=0)
            {
                count=count+mymap[rem];
            }
            ++mymap[rem];
            if(rem==0)
            {
                count++;
            }
        }
        return count;
    }
};