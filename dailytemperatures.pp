    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> ret(T.size(),0);
        for(int i=T.size()-1;i>=0;--i)
        {
            int j=i;
            while(!st.empty()&&T[i]>=T[st.top()])
                st.pop();
            if(!st.empty())
                j=st.top();
            ret[i]=j-i;
            st.push(i);
        }
        return ret;
    }