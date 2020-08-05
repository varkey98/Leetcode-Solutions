struct order
{
	int table;
	int beef;
	//int burrito;
	int ceviche;
	int fc;
	int w;
};
order* createTable()
{
	order* temp=(order*)calloc(1,sizeof(order));
	temp->table=temp->beef=temp->ceviche=temp->fc=temp->w=0;
	return temp;
}

 vector<vector<string>> displayTable(vector<vector<string>>& orders)
{
	map<char,order*> m;
	for(int i=0;i<orders.size();++i)
	{
		if(m.find(orders[i][1])!=m.end())
		{
			if(!orders[i][2].compare("Beef Burrito"))
				m[orders[i][1]]->beef++;
			else if(!orders[i][2].compare("Ceviche"))
				m[orders[i][1]]->ceviche++;
			else if(!orders[i][2].compare("Fried Chicken"))
				m[orders[i][1]]->fc++;
			else if(!orders[i][2].compare("Water"))
				m[orders[i][1]]->w++
		}
		else
		{
			order* temp=createTable();
			if(!orders[i][2].compare("Beef Burrito"))
				temp->beef++;
			else if(!orders[i][2].compare("Ceviche"))
				temp->ceviche++;
			else if(!orders[i][2].compare("Fried Chicken"))
				temp->fc++;
			else if(!orders[i][2].compare("Water"))
				temp->w++;
			m[orders[i][1]]=temp;
		}

	}
	vector<vector<string>> ret;
	vector<string> r={"Table","Beef Burrito","Ceviche","Fried Chicken","Water"};
	ret.push_back(r);
	for(map<int,order*>::iterator itr=m.begin();itr!=m.end();++itr)
	{
		vector<string> re;
		re.push_back(to_string(itr->second->table));
		re.push_back(to_string(itr->second->beef));
		re.push_back(to_string(itr->second->ceviche));
		re.push_back(to_string(itr->second->fc));
		re.push_back(to_string(iitr->second->w));
		ret.push_back(re);
	}
	return ret;        
}