class Thread
{
public:		
	Thread(void (*work_func));	//创建一个进程
	~Thread()；	//释放内存空间
	void Start();	//开始进程
	void Abort();	//终止进程
};
class Semaphore
{
public:
	Semaphore(int count,int max_count);		//初始化信号量
	~Semaphore();
	void Unsignal();	//消耗一个信号量，如果为0则锁住当前进程
	void Signal();	//释放一个信号量
};
class Mutex
{
public:
	WaitMutex();	//锁住进程直到其他进程释放锁
	ReleaseMutex();		//给其他锁住的进程释放锁
};