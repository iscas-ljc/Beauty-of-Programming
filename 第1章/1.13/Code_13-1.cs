static bool nim(int x,int y)
{
	if(x==y)
	{
		return True;
	}
	if(x>y)
	{
		int t=x;
		x=y;
		y=t;
	}
	if(x==1 && y==2)
	//第一个危险情况
	{
		return false;
	}
	ArrayList al=new ArrayList();
	al.Add(2);
	int n=1;
	int delta=0;
	int addition=0;
	while(x>n)
	{
		while(al.IndexOf(++n)!=-1);
		//发现下一个不安全情况
		delta++
		al.Add(n+delta);
		addition++;
		if(al.Count>2 && addition>100)
		//保证不安全数组处在一个小规模
		{
			ShrinkArray(al,n)；
			addition=0;
		}
	}
	if((x!=n)||(al.IndexOf(y)==-1))
	{
		return true;
	}
	else
	{
		return false;
	}
	static void ShrinkArray(ArrayList al,int n)
	{
		for(int i=0;i<al.Count;i++)
		{
			if((int)al[i]>n)
			{
				al.RemoveRange(0,i);
				return;
			}
		}
	}
}