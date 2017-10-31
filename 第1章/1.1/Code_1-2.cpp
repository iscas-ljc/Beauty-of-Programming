const DWORD busyTime=10;
const DWORD int idleTime=busyTime
Int64 startTime=0;
while(true)
{
	DWORD startTime=GetTickCount();
	// busy loop
	while((GetTickCount()-startTime)<=busyTime)
		;
	//idle loop
	Sleep(idleTime);
}