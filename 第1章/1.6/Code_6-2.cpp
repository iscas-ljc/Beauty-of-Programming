int[V+1][T+1] opt;
//子问题的记录项表
int Cal(int V,int type)
{
	if(type==T)
	{
		if(V==0)
			return 0;
		else
			return -INF;
	}
	if(V<0)
		return -INF;
	else if(V==0)
		return 0;
	else if(opt[V][type]!=-a)
		return opt[V][type];
	//子问题有解则返回
	//没有则求解
	int ret=-INF;
	for(int i=0;i<C[type];i++)
	{
		int temp=Cal(V-i*C[type],type+1);
		if(temp!=-INF)
		{
			temp+=H[type]*i;
			if(temp>ret)
				ret=temp;
		}
	}
	return opt[V][type]=ret;
}