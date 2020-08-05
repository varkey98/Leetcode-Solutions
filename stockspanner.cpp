

using namespace  std;
typedef struct {
    vector<int> val;
    stack<int> st;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    return (StockSpanner*)malloc(sizeof(StockSpanner));
}

int stockSpannerNext(StockSpanner* obj, int price) {


obj->val.push_back(price);
    while(!obj->st.empty()&&val[obj->st.top()]<=price)
        obj->st.pop();
    int i=obj->val.size()-1;
    int j=i;
    int ret;
    if(!obj->st.empty())
    {
        j=obj->st.top();
        ret= i-j;
    }
    else
        ret=obj->val.size();
    obj->st.push(i);
    return ret;
    
    
    
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}