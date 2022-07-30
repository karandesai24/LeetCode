class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        
        std::sort(products.begin(), products.end());
       
        // lower_bound() -> find the position of the value >= key 
        // upper_bound() -> find the position of the value > key
        for(int i=0; i<searchWord.length(); i++){
            vector<string> tmp;
            string str = searchWord.substr(0, i+1);
            // cout << str << endl;
            auto iter = std::lower_bound(products.begin(), products.end(), str);
            for(int cnt = 1; cnt <= 3 && iter != products.end(); cnt++, iter++){
                if( (*iter).substr(0, i+1) == str ) tmp.push_back(*iter);
                else break;
            } res.push_back(tmp);
        } return res;
    }
};