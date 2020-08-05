
map<int,bool> r;
/*bool dp(vector<int>& nums,int i)
{
if(i>=nums.size()-1)
    return true;
if(r.count(i))
    return r[i];
bool q=false;
for(int j=nums[i];j>0&&q==false;--j)
    q=q||dp(nums,i+j);
r[i]=q;
return q;
}  */
bool canJump(vector<int>& nums) {
int* arr=(int*)calloc(nums.size(),sizeof(int));
    arr[nums.size()-1]=nums.size()-1;
    arr[0]=5;
    for(int i=nums.size()-2;i>=0;--i)
    {
        if(i+nums[i]>=arr[i+1])
        {
            arr[i]=i;
           // r[i]=true;
        }
        else
        {
            arr[i]=arr[i+1];
           // r[i]=false;
        }
    }

    if(arr[0]==0||nums.size()==1)
        return true;
    else return false;
}
