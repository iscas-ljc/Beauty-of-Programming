_PROCESSOR_POWER_INFORMATION info;

CallNTPowerInformation(11,
	NULL,
	0,
	&info,
	sizeof(info));
unsigned__int64 t_begin = GetCPUTickCount();

//do something

unsigned__int64 t_end =GetCPUTickCount();
double millisec = (double)(t_end-t_begin) / (double)info.CurrentMhz;