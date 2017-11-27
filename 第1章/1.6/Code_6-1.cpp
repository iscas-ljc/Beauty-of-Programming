int Cal(int v,int T)
{
	opt[0][T] = 0;
	//T表示所有饮料的种类
	for(int i = 1 ;i <= v; i++)
	//定义边界条件
	{
		opt[i][T]=-INF;
	}
	for(int j = T-1;j >= 0; j--)
	{
		for(int i = 0 ;i <= v; i++)
		{
			opt[i][j]= -INF;
			for(int k = 0; k <= C[j]; k++)
			//遍历第j种饮料选取数量k
			//C[]存放的是饮料的可能最大数量
			{
				if(i < k * V[j])
				{
					break;
				}
				int x = opt[i - k*V[j]][j+1];
				if(x != -INF)
				{
					x += H[j] *k;
					//H[]存放的是饮料的满意度
					if(x > opt[i][j])
					//选取最大的满意度
					{
						opt[i][j] = x;
					}
				}
			}
		}
	}
	return opt[V][0]
}