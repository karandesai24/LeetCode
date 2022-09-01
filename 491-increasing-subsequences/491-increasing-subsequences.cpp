class Solution {
public:
    void solveRec(vector<int>& nums, int i, set<vector<int>>&ans, vector<int>& temp)
{
    if(i==nums.size()){
        if(temp.size()>=2) ans.insert(temp); 
        return;
    }
    //including the current elem only if the temp vector is empty so push first elem and if the next added elem is greater than equal to previous
    if(temp.empty()||nums[i]>=temp.back()) 
    {
        temp.push_back(nums[i]);
        solveRec(nums,i+1,ans,temp);
        temp.pop_back();
    }
    //excluding the current elem
    solveRec(nums,i+1,ans,temp);
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    int n=nums.size();
    set<vector<int>>st;  //set to avoid duplicated vals 
    vector<vector<int>>ans; vector<int> temp;
    solveRec(nums,0,st,temp);
    
    //copying set value to ans
    for(auto &x:st)  ans.push_back(x);
    
    return ans;
}

};