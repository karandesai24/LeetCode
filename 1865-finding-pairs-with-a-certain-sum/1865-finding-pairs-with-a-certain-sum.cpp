class FindSumPairs{
public:
    vector<int> v1,v2;
    map<int,set<int>> mp1;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;
        v2=nums2;
        for(int i=0;i<nums2.size();i++){
            mp1[nums2[i]].insert(i);
        }
    }
    void add(int index, int val){
        mp1[v2[index]].erase(index);
        mp1[v2[index]+val].insert(index);
        v2[index]+=val;
    }
    int count(int tot){
        int count=0;
        for(auto el:v1){
            count+=(mp1[tot-el].size());
        }
        return count;
    }
};


/*
   FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
  : nums1(nums1), nums2(nums2) {
    for (const int num : nums2)
      ++count2[num];
  }

  void add(int index, int val) {
    --count2[nums2[index]];
    nums2[index] += val;
    ++count2[nums2[index]];
  }

  int count(int tot) {
    int ans = 0;
    for (const int num : nums1) {
      const int target = tot - num;
      if (count2.count(target))
        ans += count2[target];
    }
    return ans;
  }

 private:
  vector<int> nums1;
  vector<int> nums2;
  unordered_map<int, int> count2;
  */
/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */