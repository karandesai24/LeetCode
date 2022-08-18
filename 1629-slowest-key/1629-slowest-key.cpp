class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
       char ans = keysPressed[0];
        int mx_time = releaseTimes[0];
        
        for(int i=1; i<releaseTimes.size(); i++) {
            int t = releaseTimes[i] - releaseTimes[i-1];
            if(t > mx_time) {
                ans = keysPressed[i];
                mx_time = t;
            } else if(t == mx_time && keysPressed[i] > ans)
                ans = keysPressed[i];
        }
        return ans; 
    }
};