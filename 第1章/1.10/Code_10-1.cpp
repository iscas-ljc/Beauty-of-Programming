while(true)
{
	bool isDownloadCompleted;
	isDownloadCompleted=GetBlockFromNet(g_buffer);
	WriteBlockToDisk(g_buffer);
	if(isDownloadCompleted)
		break;
}