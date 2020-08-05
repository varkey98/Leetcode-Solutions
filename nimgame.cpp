    #include<map>
#include<iostream>
using namespace std;
    map<int,bool> m;
    bool canWinNim(int n) {
        /*if(n<=3)
            return true;
        else if(n==4)
            return false;
        else if(m.count(n))
            return m[n];
        else
        {
            if(canWinNim(n-1)==false||canWinNim(n-2)==false||canWinNim(n-3)==false)
                m[n]=true;
            else
                m[n]=false;
            return m[n];
        }*/
        if(n<=3)
            return true;
        else
        {
            bool t1=true,t2=true,t3=true;
            bool ret;
            for(int i=4;i<=n;++i)
            {
                ret=!(t1&&t2&&t3);
                t3=t2;
                t2=t1;
                t1=ret;
            }
            return ret;
        }
    }
    int main(int argc, char const *argv[])
    {
        cout<<canWinNim(100001);
        return 0;
    }