#include "windows.h"
#include "stdlib.h"
#include "math.h"
const int SAMPLING_COUNT=200;  //把一条sin曲线分为200份
const double PI=3.1415926535;
const int TOTAL_AMPLITUDE=300; //每300ms抽一个时间点
int _tmain(int argc,_TCHAR* argv[])
{
	DWORD busySpan[SAMPLING_COUNT];
	int amplitude=TOTAL_AMPLITUDE/2;
	double radian=0.0;
	double radianIncrement=2.0/(double)SAMPLING_COUNT; //弧度抽取的增量
	for(int i=0;i< SAMPLING_COUNT;i++)
	{
		busySpan[i]=(DWORD)(amplitude+(sin(PI*radian)*amplitude));
		radian+=radianIncrement;
	}
	for(int j=0;;j=(j+1)%SAMPLING_COUNT)
	{
		startTime=GetTickCount();
		while((GetTickCount()-startTime)<=busySpan[j])
			;
		Sleep(TOTAL_AMPLITUDE-busySpan[j]);
	}
	return 0
}
//使任务管理器中的CPU占用率呈现一条sin函数