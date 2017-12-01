int nPerson[];
int nMinFloor,nTargetFloor;
int N1,N2,N3;
nTargetFloor=-1;
nMinFloor=0;
for(N1=0,N2=nPerson[1],N3=0,i=2;i<=N;i++){
	N3+=nPerson[i];
	nMinFloor+=nPerson[i]*(i-1);
	//N3表示当层之上的人数
	//N2表示当层的人数
	//N1表示当层之下的人数
}
for(i=2;i<=N;i++)
{
	if(N1+N2<N3)
	{
		nTargetFloor=i;
		nMinFloor+=(N1+N2-N3);
		N1+=N2;
		N2=nPerson[i];
		N3-=nPerson[i];
	}
	else
		break;
	//当N1+N2>=N3
	//就会跳出，表示再往上升，nMinFloor也会随之上升
}
return (nTargetFloor,nMinFloor)