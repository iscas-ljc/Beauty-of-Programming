int nPerson[];
//第i层的乘客数量
int nFloor,nMinFloor,nTargetFloor;
nTargetFloor=-1;
for(i=1;i<=N;i++)
	//逐层计算人员走的楼层，通过比较确定
	//O(N^2)
{
	nFloor=0;
	for(j=1;j<i;j++)
		nFloor+=nPerson[j]*(i-j);
	for(j=i+1;j<=N;j++)
		nFloor+=nPerson[j]*(j-i);
	if(nTargetFloor==-1||nMinFloor>nFloor)
	{
		nMinFloor=nFloor;
		nTargetFloor=i;
	}
}
return (nTargetFloor,nMinFloor)