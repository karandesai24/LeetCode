class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         if (n == 0)
      return tasks.size();
        map<char, int> taskFreq;
        int maxFrequent = 0; // task that appeared most frequent 
        for(auto task : tasks){
            taskFreq[task]++;
            maxFrequent = max(maxFrequent, taskFreq[task]);
        }
        // we can get exhausted all our mostfrequent task in (mostFrequent -1)slots 
        int ans = (maxFrequent -1)*(n + 1);
        // if we have multiple most frequent task then we can get them done in one go.
        for(auto it : taskFreq){
            if(it.second == maxFrequent)ans++;
        }
        return max(ans, (int)tasks.size());
    }
};