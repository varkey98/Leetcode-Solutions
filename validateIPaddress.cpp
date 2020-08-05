string validIPAddress(string IP) 
{
	int flag=0;
	for(int i=0;i<IP.length();++i)
		if(IP[i]=='.')
		{
			flag=1;
			break;
		}
		else if(IP[i]==':')
		{
			flag=2;
			break;
		}
	switch(flag)
	{
		case 1:
		{
			int c=0,val=0,dot=0;
			for(int i=0;i<IP.length();++i)
				if(IP[i]=='.')
				{
					if(c==0||val>255||dot>3)
						return "Neither";
					++dot;
					c=0;
					val=0;
				}
				else if(IP[i]>='0'&&IP[i]<='9')
				{
					if(c>0&&val==0)
						return "Neither";
					++c;
					val=val*10+IP[i]-'0';
				}
				else return "Neither";
			return "IPv4";
		}
		break;
		case 2:
		{
			int c=0,colon=0;
			for(int i=0;i<IP.length();++i)
			{
				if(c>4)
					return "Neither";
				if(IP[i]==':')
				{
					if(c==0||colon>7)
						return "Neither";
					else c=0;
					++colon;
				}
				else if((IP[i]>='a'&&IP[i]<='z')||(IP[i]>='A'&&IP[i]<='Z')||(IP[i]>='0'&&IP[i]<='9'))
					++c;
				else return "Neither";
			}
			if(c>4||colon>7)
				return "Neither";
			return "IPv6";
		}
	}
	return "Neither";
}