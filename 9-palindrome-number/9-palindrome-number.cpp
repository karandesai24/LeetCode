class Solution {
public:
    bool isPalindrome(int x) {
        
        string s = to_string(x);
        int j = s.size()-1;
        int i = 0;
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
};
/*
class Solution {
public:

long int reverse_no(int x){
long int res=0;
while(x!=0){
res=(res*10)+(x%10);
x/=10;
}
return res;
}


bool isPalindrome(int x) {

if(x<0)return false;


long int rev_x=reverse_no(x);


if(x==rev_x)return true;
else return false;
}
};
*/