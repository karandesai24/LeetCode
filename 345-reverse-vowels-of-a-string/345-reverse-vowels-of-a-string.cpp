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