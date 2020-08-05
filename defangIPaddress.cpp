 #include<string>
using namespace std;
  string defangIPaddr(string address) {
  	string::iterator itr=address.begin();
  	string ret;
  	while(itr!=address.end())
  	{
  	if(*(itr)=='.')
  	{
  		ret.push_back('[');
  		ret.push_back('.');
  		ret.push_back(']');
        
    }  
    else 
    	ret.push_back(*(itr));
    ++itr;	
}
return ret;
}
