#include<map>
#include<vector>
#include<iostream>

using namespace std;


    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        //cout<<1;
       vector<vector<int>> ret;
       map<int,vector<int>> m;
        int i=0; int val=0;
       
      //  cout<<1;
        for(int i=0;i<groupSizes.size();++i)
        {
            if(m.find(groupSizes.at(i))==m.end())
            {
                cout<<1;
                vector<int> temp;
                temp.push_back(i);
                m[groupSizes.at(i)]=temp;
            }
            else
            {
                m[groupSizes.at(i)].push_back(i);
            }
        }
        map<int,vector<int>>::iterator itr=m.begin();
        i=0;vector<int> temp;
        while(itr!=m.end())

        {
            for(int j=0;j<itr->second.size();++j)
            {
                temp.push_back(itr->second[j]);
                ++val;
                if(val>=itr->first)
                {
                    ret.push_back(temp);
                    temp.clear();
                    ++i;
                    val=0;
                }
            }
            ++itr;
            if(!temp.empty())
             ret.push_back(temp);
            ++i;
            val=0;
        }
        return ret;
    }

int main()
{
	vector<vector<int>> v;
	int arr[]={1};
	vector<int> temp;
	for(int i=0;i<1;++i)
		temp.push_back(arr[i]);
	cout<<1;
	v=groupThePeople(temp);
	return 0;
}