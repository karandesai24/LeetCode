class Solution {
public:
    int bitwiseComplement(int n) {
       unsigned int zero_complement = ~0;
        while( n & zero_complement ){
            zero_complement = zero_complement << 1;
        } return n == 0 ? 1 : ~n ^ zero_complement;
        
    }
};