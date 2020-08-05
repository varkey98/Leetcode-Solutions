bool isHappy(int n)
{
	int sum=0,r;
	int k=10;
	do
	{
		sum=0;
		while(n)
		{
			r=n%10;
			n/=10;
			sum+=r*r;
		}
		n=sum;
	}while(sum!=1&&k--);
	if(sum==1)
		return true;
	else return false;
}