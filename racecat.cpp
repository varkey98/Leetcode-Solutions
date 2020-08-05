struct node
{
	int pos;
	int speed;
	int obj;
};
int racecar(int target)
{
	node* n=(node*)malloc(sizeof(node));
	node* t;
	n->pos=0;
	n->speed=1;
	n->obj=0;
	queue<node*> Q;
    set<pair<int,int>> s;
	Q.push(n);
    pair<int,int> p;
    p.first=n->pos;p.second=n->speed;
    s.insert(p);
	int pos,speed,obj;
	while(Q.size())
	{
		n=Q.front();
		Q.pop();
		if(n->pos==target)
			break;
		pos=n->pos;
		speed=n->speed;
		obj=n->obj;
        if(pos<-100||pos>10000)
            continue;
		n=(node*)malloc(sizeof(node));
		t=(node*)malloc(sizeof(node));
		n->pos=pos;
		n->speed=speed>0?-1:1;
		t->pos=pos+speed;
		t->speed=speed*2;
		n->obj=t->obj=obj+1;
        p.first=n->pos;
        p.second=n->speed;
        if(s.find(p)==s.end())
        {
            Q.push(n);
            s.insert(p);
        }
        p.first=t->pos;
        p.second=t->speed;
        if(s.find(p)==s.end())
        {
		    Q.push(t);
            s.insert(p);
        }
	}
	return obj;
}