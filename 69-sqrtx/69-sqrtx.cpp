class Solution {
public:
    int mySqrt(int x) {
        int left = 1 , right = x / 2 , mid , ans;
    long temp;
    while(left <= right)
    {
        mid = (left + (right - left) / 2);
        temp = (long)mid * (long)mid;
        //mid * mid can be large, so use long
        if(temp == x)
            return mid;
        if(temp < x)
            ans = mid , left = mid + 1;
        else
            right = mid - 1;
    }
    return ans;
        
    }
};