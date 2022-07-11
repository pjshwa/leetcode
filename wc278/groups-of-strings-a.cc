map<int,int> mp;
map<int,int> used;

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int i,j,k,t,ng,mg,l,tmp,x;
        vector<int> q;
        vector<int> ans;
        mp.clear();
        for (i=0;i<words.size();i++)
        {
            tmp=0;
            for (j=0;j<words[i].length();j++)
                tmp|=(1<<(words[i][j]-'a'));
            mp[tmp]++;
        }
        used.clear();
        ng=0;mg=0;
        for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            if (used.find(it->first)==used.end())
            {
                used[it->first]=1;
                t=it->second;
                ng++;
                q.clear();
                q.push_back(it->first);
                for (l=0;l<q.size();l++)
                {
                    x=q[l];
                    for (i=0;i<26;i++)
                    {
                        tmp=(x^(1<<i));
                        if ((mp.find(tmp)!=mp.end())&&(used.find(tmp)==used.end()))
                        {
                            used[tmp]=1;
                            q.push_back(tmp);
                            t+=mp[tmp];
                        }
                    }
                    for (i=0;i<26;i++)
                        if (((1<<i)&x)==0)
                            for (j=0;j<26;j++)
                                if (((1<<j)&x)!=0)
                                {
                                    tmp=(x^(1<<i)^(1<<j));
                                    if ((mp.find(tmp)!=mp.end())&&(used.find(tmp)==used.end()))
                                    {
                                        used[tmp]=1;
                                        q.push_back(tmp);
                                        t+=mp[tmp];
                                    }
                                }
                }
                if (t>mg) mg=t;
            }
        }
        ans.clear();
        ans.push_back(ng);
        ans.push_back(mg);
        return ans;
    }
};
