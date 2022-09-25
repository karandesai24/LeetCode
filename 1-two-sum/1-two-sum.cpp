class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(m[nums[i]] > 0 && m[nums[i]] - 1 != i) 
                return{m[nums[i]] - 1, i};
            
            m[target-nums[i]] = i+1;
        }
        
        return {-1,-1};
    }
        
  
};
//other 

//method: 1, using hashmap  O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            int value = target - nums[i];
            if(mpp.find(value)!=mpp.end())
            {
                ans.push_back(mpp[value]);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};
    
    //METHOD - 2
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n= nums.size();
//         vector<int> a;
//         for(int i=0; i<n-1; i++)
//         {
//             for(int j=i+1; j<n; j++)
//             {
//                 if(nums[i]+nums[j]==target)
//                 {
//                     a.push_back(i);
//                     a.push_back(j);
//                 }
//             }
//         }
//         return a;
//     }
// };
    
    
    
        //METHOD - 3
    //method using two pointer, works good if you've to return the elements itself not the indices.
    
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         int i=0;
//         int j=nums.size()-1;
//         sort(nums.begin(), nums.end());
//         while(i<j)
//         {
//             if(nums[i]+nums[j]==target)
//             {
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 i++; 
//                 j--;
//             }
//             else if(nums[i]+nums[j]>target)
//                 j--;
//             else i++;
//         }
//         return ans;
//     }
