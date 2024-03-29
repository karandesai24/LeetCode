class Solution {
public:
    int magicalString(int n) {
         if(n<=3) return 1;
        string s = "122";
        int ans = 1;
        int i = 2;
        char pre = '2';
        while(s.size()<n){
            int cnt = s[i++]-'0';
            if(pre=='1'){
                while(cnt--){
                    s.push_back('2');
                }
            }
            else{
                ans+=cnt;
                while(cnt--){
                    s.push_back('1');
                }
            }
            pre = pre=='1'?'2':'1';
        }
        return s.size()==n ? ans:(s[s.size()-1]=='1'?ans-1:ans);
    }
};
/*
STL
int magicalString(int n) {
   
    string s = " 122";
    for(int i=3;i<=n;i++){
        s.append(s[i]-'0', i&1 ? '1': '2');
        if(i>n) break;
    }
    return count(s.begin(),s.begin()+n+1,'1');
}
*/