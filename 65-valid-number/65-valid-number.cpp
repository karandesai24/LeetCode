class Solution {
public:
  
    bool isInt(string s)
    {
        int n = s.length();
        int si = 0;
        
        if(n == 0) return false;
        
        if(s[0] == '+' || s[0] == '-') si = 1;
        
        if(n==1 && si==1) return false;
     
        
        for(int i = si;  i<n ; i++)
        {
            if(s[i] >= '0' && s[i] <= '9') continue;
            
            return false;
        }
        
        return true;
    }
    
    bool isDec(string s)
    {
        int n = s.length();
        int si =  0; 
        if(n==0) return false;
        if(s[0] == '+' || s[0] == '-') si = 1;
        if(n==1 && si==1) return false;
      
        bool dot = false;
        if(si == n-1 && s[si] == '.') return false;
        
        for(int i = si ; i<n ; i++)
        {
            if(s[i] >= '0' && s[i] <= '9') continue;
            if(s[i] == '.')
            {
                if(dot) return false; 
                dot = true;
                continue;
            
            }
            return false;
        }
        
        return true;
    }
    
    
    bool valid(string s )
    {
       
        for(char c : s)
        {
            if(c=='E' || c=='e' || c=='.')continue;
            if(c=='+' || c=='-')continue;
            if('0' <= c && c <= '9') continue;
            
            return false;
        }
        return true;
    }
    
public:
    bool isNumber(string str) {
        
        if(!valid(str)) return false;
        
        
        string f , s;
       
        bool flag = false;
       
        for(char c : str)
        {
            if(c=='e' || c=='E') {
                if(flag == false) flag = true;
                else return false; 
            }
            else {
                if(flag) s += c;
                else f += c;
            }
        }
        
      
        if(!isDec(f) && !isInt(f)) return false;
        
        if(flag==false) return true;
       
        
      
        if(!isInt(s)) return false;
        
        return true ;
    }
};