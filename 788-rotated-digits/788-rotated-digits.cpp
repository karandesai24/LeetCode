class Solution {
public:
    int rotatedDigits(int N) {
        
    int count = 0;
        for(int i=1; i<=N; i++){
            int changed = 0, num = i;
            while( num ){
                int tmp = num % 10;
                num /= 10;
                if( tmp==3 || tmp==4 || tmp==7 ){
                    changed = 0;
                    break;
                } else if ( tmp==2 || tmp==5 || tmp==6 || tmp==9 ) changed = 1;
            } if( changed ) count++;
        } return count;
    }
};