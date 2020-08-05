int lengthOfLongestSubstring(string s) 
{
    map<char,bool> arr;
    int ret=0;
    deque<int> q;
    for(int i=0;i<s.length();++i)
    {
        if(arr.find(s[i])==arr.end()||arr[s[i]]==false)
            arr[s[i]]=true;
        else
        {
            ret=max(ret,i-q.front());
            while(!q.empty()&&arr[s[i]])
            {
                arr[s[q.front()]]=false;
                q.pop_front();
            }
        }
        arr[s[i]]=true;
        q.push_back(i);
    }
    if(!s.length())
        return 0;
    int n=s.length()-q.front();
    return max(ret,n);
}