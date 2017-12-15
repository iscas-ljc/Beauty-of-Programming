bool nim(int x,int y)
{
	double a,b;
	a=(1+sqrt(5.0))/2;
	b=(3+sqrt(5.0))/2;
	if(x==y)
		return true;
	if(x>y)
		swap(x,y);
	return (n!=(long)floor((y-x)*a));
}