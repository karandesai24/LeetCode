class Solution {
public:
   bool is_palin(string s)
{
    int left = 0, right = s.size()-1;
    
    while(left < right)
    {
        if(s[left] != s[right])
        {
            return false;
        }
        
        left++;
        
        right--;
    }
    
    return true;
}
vector<vector<int>> palindromePairs(vector<string>& words) {
    
    unordered_map<string,int> mp;
    
    vector<vector<int>> ans;
    
    int n = words.size();
    
    for(int i=0; i<n; i++)
    {
        string temp = words[i];
        
        reverse(temp.begin(), temp.end());
        
        mp[temp] = i;
    }
    
    if(mp.find("") != mp.end())
    {
        for(int i=0;i<n;i++ )
        {
            if(mp[""] == i)
            {
                continue;
            }
            
            if(is_palin(words[i]))
            {
                ans.push_back({i,mp[""]});
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        string str = words[i];
        
        string left = "";
        
        string right = str;
        
        for(int j=0; j<str.size(); j++)
        {
            left.push_back(str[j]);
            
            right.erase(0,1);
            
        if(mp.find(left)!= mp.end() && mp[left] != i && is_palin(right))
        {
            ans.push_back({i,mp[left]});
        }
            
        if(mp.find(right) != mp.end() && mp[right] != i && is_palin(left))
        {
            ans.push_back({mp[right], i});
        }
    }
 }
    
    return ans;
    
}
};