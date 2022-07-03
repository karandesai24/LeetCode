class Solution {
public:
    
      set <int> inter1, inter2;
    vector <int> solution;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++)
            inter1.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); i++)
            if(inter1.find(nums2[i]) != inter1.end())
                inter2.insert(nums2[i]);//populate the intersection set
        for(set<int>::iterator it = inter2.begin(); it != inter2.end(); ++it)
        
            solution.push_back(*it);//copy the set into a vector
        return solution;
    }
};