class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> ord; int z=order.size();
        for (int i=0;i<z;++i)ord[order[i]]=i;
        sort(s.begin(),s.end(),[&](char a,char b){return ord[a]<ord[b];});
        return s;
    }
};
