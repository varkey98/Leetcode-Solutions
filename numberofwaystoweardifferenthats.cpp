#include<vector>
using namespace std;
int dp(int mask,int i,vector<vector<int>>& h)
{
    if(mask==allmask)
        return 1;// the error was that the allmask check was done after the i>40 check, which will obviously reduce somemasks, which was complete.
    if(i>40)
        return 0;
    if(memo[mask][i]!=-1)
        return memo[mask][i];
    long int q = dp(mask,i+1,h);
    for(int j:h[i])
        if(mask&(1<<j))
            continue;
    else
        q+=dp(mask|(1<<j),i+1,h);
    q=q%(int)(1e9+7);
    return memo[mask][i]=q;
}
   int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> persons(41); // there is 1... 40 hats
        for(int i=0; i< hats.size(); ++i){
            for(const auto& h: hats[i]){
                persons[h].push_back(i); // fill people for each hat type
            }
        }
        
        allmask = (1<<hats.size()) -1;
        memo.resize(allmask, vector<int>(41, -1));
        
        return  dp(0,1,persons); // start 0 mask and 1.hat number
    }