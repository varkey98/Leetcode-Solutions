int calculate(string s) 
{
    stack<char> st;
    for(char x:s)
        if(x==')')
        {
            string k;
            while(!st.empty()&&st.top()!='(')
            {
                k.push_back(st.top());
                st.pop();
            }
                reverse(k.begin(),k.end());
                int val=calculate(k);
                st.pop();
                if(!st.empty()&&val<0)
                {
                    if(st.top()=='+')
                        st.pop();
                    else if(st.top()=='-')
                    {
                        st.pop();
                        st.push('+');
                        val*=-1;
                    }
                }
                k=to_string(val);
                for(char y:k)
                    st.push(y);
        }
        else st.push(x);
    string k;
    while(!st.empty())
    {
        k.push_back(st.top());
        st.pop();
    }
    reverse(k.begin(),k.end());
    int ret=0,v=0;
    bool plus=true,minus=false;
    for(int i=0;i<k.length();++i)
    {
        if(k[i]<='9'&&k[i]>='0')
            v=v*10+(k[i]-'0');
        if(k[i]=='+'||k[i]=='-'||i==k.length()-1)
        {
            if(plus)
            {
                ret+=v;
                plus=false;
            }
            if(minus)
            {
                ret-=v;
                minus=false;
            }
            v=0;
            if(k[i]=='+')
                plus=true;
            if(k[i]=='-')
                minus=true;
        }
    }
    return ret;
}