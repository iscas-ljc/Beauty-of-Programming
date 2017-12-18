Grid preClick = NULL,curClick = NULL;
while{
	if(用户点击格子(x,y),且格子(x,y)为非空格子)
	{
		preClick = curClick;
		curClick.Pos=(x,y);
	}
	if(preClick!=NULL && curClick != NuLL && preClick.Pic == curClick.Pic && FindPath(preClick,curClick)!=NULL)
	{
		显示两个格子的消除路径
		消除格子preClick,curClick
		preClick=curClick=NULL;
	}
}