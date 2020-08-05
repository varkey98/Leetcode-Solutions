#include<vector>
using namespace std;
int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        vector<int> tb;
        vector<int> lr;
        int mint;
        for(int i=0;i<grid.size();++i)
        {
        	mint=0;
        	for(int j=0;j<grid[0].size();++j)
        		if(grid[i][j]>mint)
        			mint=grid[i][j];
        	lr.push_back(mint);
        }
        for(int i=0;i<grid[0].size();++i)
        {
        	mint=0;
        	for(int j=0;j<grid.size();++j)
        		if(grid[j][i]>mint)
        			mint=grid[j][i];
        	tb.push_back(mint);
        }
        mint=0;
        for(int i=0;i<grid.size();++i)
        	for(int j=0;j<grid[0].size();++j)
        		mint+=(min(tb[j],lr[i])-grid[i][j]);
        return mint;
    }