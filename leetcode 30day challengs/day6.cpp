class Solution {
public:
 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();++i)
        {
            string j=strs[i];
            sort(j.begin(),j.end());
            if(m.count(j))
                m[j].push_back(strs[i]);
            else
            {
                vector<string> temp;
                temp.push_back(strs[i]);
                m[j]=temp;
            }
       
        }
             map<string,vector<string>>::iterator itr=m.begin();
            vector<vector<string>> ret;
            while(itr!=m.end())
            {
                ret.push_back(itr->second);
                ++itr;
            }
            
            return ret;
        
    }
};