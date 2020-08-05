class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] arr=sentence.split(" ");
        int i=1;
        for(String s:arr)
        {
            if(s.length()>=searchWord.length())
                //System.out.println(s.substring(0,searchWord.length()));
               if((s.substring(0,searchWord.length())).equals(searchWord))
                {
                    return i;
                }
            ++i;
            }
    return -1;
    }
}
int maxVowels(string s, int k) {
int ret=0;
    for(int i=0;i<k;++i)
    	if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u')
    		++ret;
int temp=ret;
    for(int i=k;i<s.length();++i)
    {
    	if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='o'||s[i-k]=='i'||s[i-k]=='u')
    		--temp;
    	if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u')
    		++temp;
    	ret=max(ret,temp);
    }
    return ret;

}

int ret=0;
void fun(TreeNode* root,vector<int> c)
{
	if(root)
	{
		c[root->val]++;
		int cout=0;
		if(root->left==NULL&&root->right==NULL)
		{
			for(int x:c)
				if(x%2!=0)
					cout++;
			if(cout<=1)
				++ret;
		}
		else
		{
			fun(root->left,c);
			fun(root->right,c);
		}


	}
}
int pseudoPalindromicPaths (TreeNode* root) 
{
	vector<int> count(10,0);    
	fun(root,count);
    return ret;
}

vector<vector<int>> memo;
bool flag=true;
int dp(int i,int j,vector<int>& a,vector<int>& b)
{
	if(i>=a.size()||j>=b.size())
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int taken=a[i]*b[j]+dp(i+1,j+1,a,b);
	int not_taken=max(dp(i+1,j,a,b),dp(i,j+1,a,b));
    if(taken>not_taken)
        flag=false;
	return memo[i][j]=max(taken,not_taken);
}
int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
{
       memo.resize(nums1.size(),vector<int>(nums2.size(),-1));
    int val=dp(0,0,nums1,nums2);
    if(flag){
        int ret=nums1[0]*nums2[0];
        for(int i=0;i<nums1.size();++i)
            for(int j=0;j<nums2.size();++j)
                ret=max(ret,nums1[i]*nums2[j]);
    return ret;
    }
                
       return val; 
}