class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stack;
        int sum = 0;
        for(int i=0; i<ops.size(); ++i){
            if( ops[i] == "C" ){ 
           
                sum -= stack.back();
                stack.pop_back();
            } else if( ops[i] == "D" ){ 
           
                sum += stack[ stack.size()-1 ]*2;
                stack.push_back( stack.back()*2 );
            } else if( ops[i] == "+" ){ 
           
                sum += stack[ stack.size()-2 ] + stack[ stack.size()-1 ];
                stack.push_back(stack[stack.size()-2]+stack[stack.size()-1]);
            } else { 
                
                stack.push_back( stoi(ops[i]) );
                sum += stack.back();
            }
        } return sum;
    }
};