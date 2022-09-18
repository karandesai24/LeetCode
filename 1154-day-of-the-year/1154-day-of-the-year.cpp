class Solution {
public:
    int dayOfYear(string date) {
        int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int n=stoi(date.substr(0,4));
    if(n%4==0) month[1]=29;
    if(n%100==0) month[1]=28;
    if(n%400==0) month[1]=29;
    for(int i=1;i<12;i++)  month[i]=month[i]+month[i-1];
    int day=stoi(date.substr(8,10));
    int m=stoi(date.substr(5,7));
    if(m==1) return day;
    return day + month[m-2];
    }
};