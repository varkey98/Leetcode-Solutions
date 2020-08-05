int racecar(int target)//this dfs doesn't work :(
{
	string ret;
	int speed=1;
	int pos=0;
	while(pos!=target)
	{
		while(pos<target)
		{
			if(speed<0)
			{
				ret.push_back('R');
				speed=1;
				continue;
			}
			ret.push_back('A');
			pos+=speed;
			speed*=2;
		}
		while(pos>target)
		{
			if(speed>0)
			{
				ret.push_back('R');
				speed=-1;
				continue;
			}
			ret.push_back('A');
			pos+=speed;
			speed*=2;
		}
	}
	return ret.size();
}