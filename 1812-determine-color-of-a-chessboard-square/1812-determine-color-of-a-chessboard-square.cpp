class Solution {
public:
    bool squareIsWhite(string coordinates) {
        
          return (coordinates[0]%2==0 ^ coordinates[1]%2==0);
                  
        
        
    }
};