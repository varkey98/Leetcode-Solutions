 string complexNumberMultiply(string a, string b) {
        
        string ret;
        string::iterator itr1,itr2;
        itr1=a.begin();
        itr2=b.begin();
        int f=0;
        int av=0,bv=0,ai=0,bi=0;
        for(;*itr1!='+';++itr1)
        	if(*itr1=='-')
        		f=1;
        	else
        		av=av*10+(int)*itr1-48;
        if(f)
        	av*=-1;f=0;
        for(;*itr2!='+';++itr2)
        	if(*itr2=='-')
        		f=1;
        	else
        		bv=bv*10+(int)*itr2-48;
        if(f)
        	bv*=-1;f=0;
        ++itr1;++itr2;
        for(;*itr1!='i';++itr1)
        	if(*itr1=='-')
        		f=1;
        	else
        		ai=ai*10+(int)*itr1-48;
        if(f)
        	ai*=-1;f=0;
        for(;*itr2!='i';++itr2)
        	if(*itr2=='-')
        		f=1;
        	else
        		bi=bi*10+(int)*itr2-48;
        if(f)
        	bi*=-1;f=0;
        int ansr=av*bv-ai*bi;int ansi =av*bi+ai*bv;
        if(ansr<0)
        {
        	ret.push_back('-');
        	ansr*=-1;
        }
        string t;
        if(ansr)
        {
        	while(ansr)
        	{
        		t.push_back(ansr%10+48);
        		ansr/=10;
        	}
        	for(int i=t.length()-1;i>=0;--i)
        		ret.push_back(t.at(i));
        }
        else
        	ret.push_back(48);
        ret.push_back('+');t.clear();
        if(ansi<0)
        {
        	ret.push_back('-');
        	ansi*=-1;
        }
        if(ansi)
        {
        	while(ansi)
        	{
        		t.push_back(ansi%10+48);
        		ansi/=10;
        	}
        	for(int i=t.length()-1;i>=0;--i)
        		ret.push_back(t.at(i));
        }
        else ret.push_back(48);
        ret.push_back('i');
        return ret;
    }