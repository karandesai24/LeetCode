class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
		string emp = "0123456789abcdef";
		string res = "";
		int count = 0;
		while(num && count < 8){
			res += emp[num & 15];
			num >>= 4;
			count++;
		}
		reverse(res.begin(), res.end());
		return res;
    }
};