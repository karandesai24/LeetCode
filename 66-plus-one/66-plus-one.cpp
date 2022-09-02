class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
int flag = 0; // to check if all digits are 9
for(int i=size-1; i>=0; i--)
{
if(digits[i]==9)
{
digits[i] = 0;
}
else
{
flag = 1;
digits[i]++;
break;
}
}
if(flag==0)
{
digits[0] = 1;
digits.push_back(0);
}
return digits;
    }
};