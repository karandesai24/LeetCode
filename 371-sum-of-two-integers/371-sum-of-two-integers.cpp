class Solution {
public:
    int getSum(int a, int b) {
        int sum=a;
        unsigned int carry; 
        while(b)
        {
            sum=a^b;
            carry=a&b;
            a=sum;
            b=carry<<1;
        }
        return sum;
    }
};