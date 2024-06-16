class Solution {
    int col_f(string& x, int score){
        int ret=0; vector<char> b;
        for (char c : x){
            if (!b.empty()&&b.back()=='a'&&c=='b') {
                    b.pop_back();
                    ret+=score;
                }
                else b.push_back(c);
        }
        x=string(b.begin(),b.end());
       return ret;
    }
    
    int col_g(string& x, int score){
        reverse(x.begin(),x.end());
        int ret=0; vector<char> b;
        for (char c : x){
            if (!b.empty()&&b.back()=='a'&&c=='b') {
                    b.pop_back();
                    ret+=score;
                }
                else b.push_back(c);
        }
        x=string(b.begin(),b.end());
        reverse(x.begin(),x.end());
       return ret;
    }
    
public:
    int maximumGain(string s, int x, int y) {
        int ret=0; string t;
        if (x>y){
            ret+=col_f(s,x);
            ret+=col_g(s,y);
        }
        else {
            ret+=col_g(s,y);
            ret+=col_f(s,x);
        }
        return ret;
    }
};
