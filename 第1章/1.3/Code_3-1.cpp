class CprefixSorting
{
public:
	CprefixSorting()
	{
		m_nCakeCnt = 0;		
		m_nMaxSwap = 0;
	}
	~CprefixSorting()
	{
		if( m_CakeArray != NULL)	
		{
			delete m_CakeArray;
		}
		if( m_SwapArray != NULL)
		{
			delete m_SwapArray;
		}
		if( m_ReverseCakeArray != NULL)
		{
			delete m_ReverseCakeArray;
		}
		if( m_ReverseCakeArraySwap !=NULL)
		{
			delete m_ReverseCakeArraySwap;
		}
	}
	void Run(int* pCakeArray,int nCakeCnt)
	//烙饼个数
	//存储烙饼的索引数组
	//记录翻转信息
	{
		Init(pCakeArray, nCakeCnt);
		m_nSearch = 0;
		Search(0);
	}
	void Output()
	//输出翻转次数
	{
		for(int i=0;i<m_nMaxSwap;i++){
			printf("%d",m_SwapArray[i]);
		}
		printf("\n |Search Times| : %d\n",m_nSearch);
		printf("Total Swap times =%d\n",m_nMaxSwap);
	}

private:
	void Init(int* pCakeArray ,int nCakeCnt)
	{
		assert(pCakeArray !=NULL);
		assert(nCakeCnt >0);
		m_nCakeCnt=nCakeCnt;
		m_CakeArray=new int[m_nCakeCnt];
		assert(m_CakeArray != NULL);
		//初始化数组
		for(int i=0;i<m_nCakeCnt;i++)
		{
			m_CakeArray[i]=pCakeArray[i];
		}
		m_nMaxSwap = UpperBound(m_nCakeCnt);
		//设置最多交换
		m_SwapArray = new int[m_nMaxSwap + 1];
		assert(m_SwapArray != NULL);
		//初始化交换结果数组
		m_ReverseCakeArray =new int[m_nCakeCnt];
		//初始化中间数组
		for(i=0;i<m_nCakeCnt;i++)
		{
			m_ReverseCakeArray[i]=m_CakeArray[i];
		}
		m_ReverseCakeArraySwap = new int[m_nMaxSwap];
	}
	int UpperBound(int nCakeCnt)
	{
		return nCakeCnt*2；
		//翻转上界
	}
	int Lowerbound(int* pCakeArray,int nCakeCnt)
	{
		int t,ret =0;
		//根据当前信息判断最少换多少次
		for(int i=1;i<nCakeCnt;i++)
		{
			t=pCakeArray[i] - pCakeArray[i-1];
			//判断相邻的两个尺寸是否相邻
			if((t==1)||(t==-1))
			{
			}
			else
			{
				ret++;
			}
		}
		return ret;
	}
	void Search(int step)
	//主函数
	{
		int i,nEstimate;
		m_nSearch++;
		nEstimate =Lowerbound(m_ReverseCakeArray,m_nCakeCnt);
		if(step + nEstimate > m_nMaxSwap)
			return;
		//估算最小交换次数
		if(IsSorted(m_ReverseCakeArray,m_nCakeCnt)
		{
			if(step<m_nMaxSwap)
			{
				m_nMaxSwap=step;
				for(i=0;i<m_nMaxSwap;i++)
					m_SwapArray[i]=m_ReverseCakeArray[i];
			}
		return;
		}
		for(i=1;i<m_nCakeCnt;i++)
		{
			Reverse(0,i);
			m_ReverseCakeArray[step]=i;
			Search(step+1);
			Reverse(0,i);
		}
	bool IsSorted(int* pCakeArray,int nCakeCnt)
	{
		for(int i=1;i<nCakeCnt;i++)
		{
			if(pCakeArray[i-1]>pCakeArray[i])
			{
				return false;
			}
		}
		return true;
	}
	void Reverse(int nBegin,int nEnd)
	{
		assert(nEnd > nBegin);
		int i,j,t;
		for(i=nBegin,j=nEnd;i<j;i++;j--)
		{
			t=m_ReverseCakeArray[i];
			m_ReverseCakeArray[i]=m_ReverseCakeArray[j];
			m_ReverseCakeArray[j]=t;
		}
	}
	)}
private:
	int* m_CakeArray;	//烙饼信息
	int m_nCakeCnt;		//烙饼个数		
	int m_nMaxSwap;		//最多交换次数(2*m_nCakeCnt)
	int* m_SwapArray;	//交换结果数组
	int* m_ReverseCakeArray;	//当前烙饼信息
	int* m_ReverseCakeArraySwap;	//当前交换结果
	int m_nSearch;	//当前搜索次数
};