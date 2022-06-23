class Solution {
public:
    int findComplement(int num) {
        unsigned int zero_complement = ~0;
        while( num & zero_complement ){
            zero_complement = zero_complement << 1;
        } return num == 0 ? 1 : ~num ^ zero_complement;
        
    }
};