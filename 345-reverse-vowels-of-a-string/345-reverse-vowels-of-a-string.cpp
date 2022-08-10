class Solution {
public:
    string reverseVowels(string s) {
        const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                     'A', 'E', 'I', 'O', 'U'};
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
      while (start < end && !vowels.count(s[start]))
        ++start;
      while (start< end && !vowels.count(s[end]))
        --end;
      swap(s[start++], s[end--]);
    }

    return s;
        
    }
};
/*
bool IsVowel(char ch){
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int left = 0, right = s.length()-1;
        while( left < right ){
            if( IsVowel(s[left]) && IsVowel(s[right]) ){
                swap( s[left++], s[right--]);
            }
            if( !IsVowel(s[left]) ) left++;
            if( !IsVowel(s[right]) ) right--;
        } return s;

*/


/*
    
 string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int left = 0, right = s.length()-1;
        while( left < right ){
            while( left < right && vowels.find(s[left]) == string::npos ) left++;
            while( left < right && vowels.find(s[right]) == string::npos ) right--;
            swap( s[left++], s[right--]);
        } return s;
 */
