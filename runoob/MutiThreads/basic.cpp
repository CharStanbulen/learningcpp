#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <thread>

std::thread::id main_thread_id = std::this_thread::get_id();

using namespace std;

//#define BASIC
//#define PARAM
//#define DETACH
#define STDTHR

#define NUM_THREADS 5

//函数加上*可以被函数传递
#ifdef BASIC
void* say_hello(void* args)
{
	cout << "Hello world!" << endl;
	return 0;
}
#endif

#ifdef PARAM
struct thread_data{
	int thread_id;
	char *message;
};
void *PrintHello(void *threadarg)
{
	struct thread_data *my_data;

	my_data = (struct thread_data *) threadarg;

	cout << "Thread ID : " << my_data->thread_id;
	cout << "Message : " << my_data->message << endl;

	pthread_exit(NULL);
}
#endif

#ifdef DETACH
void  *wait(void *t)
{
	int i;
	long tid;

	tid = (long)t;

	sleep(1);
	cout << "Sleeping in thread " << endl;
	cout << "Thread with id : " << tid << " ...exiting " << endl;
	pthread_exit(NULL);
}
#endif

#ifdef STDTHR
void hello()
{
	std::cout << "Hello Concurrent World\n";
	if (main_thread_id == std::this_thread::get_id())
		std::cout << "This is the main thread.\n";
	else
		std::cout << "This is not main thread.\n";
}

void pause_thread(int n) {
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
}
#endif

int main()
{
#ifdef STDTHR
	std::thread t(hello);
	std::cout << t.hardware_concurrency() << std::endl;
	std::cout << "native_handle " << t.native_handle() << std::endl;
	t.join();
	std::thread a(hello);
	a.detach();
	std::thread threads[5];
	
	std::cout << "Spawning 5 threads...\n";
	for (int i = 0; i < 5; ++i)
		threads[i] = std::thread(pause_thread, i + 1);
	std::cout << "Done spawing threads. Now waiting for them to join:\n";
	for (auto &thread : threads)
		thread.join();
	std::cout << "All threads joined!\n";
#endif
#ifdef DETACH
	int rc;
	int i;

	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void *status;

	//初始化并设置线程是可链接的
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < NUM_THREADS; i++) {
		cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, wait, (void *)&i);
		if (rc) {
			cout << "Error: unable to create thread," << rc << endl;
			exit(-1);
		}
	}

	pthread_attr_destroy(&attr);
	for(i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(threads[i], &status);
		if (rc){
			cout << "Error: unable to join," << rc << endl;
			exit(-1);
		}
		cout << "Main: completed thread id :" << i;
		cout << "	exiting with status :" << status << endl;
	}
	cout << "Main: program exiting." << endl;
	pthread_exit(NULL);
#endif
#ifdef PARAM
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	int rc;
	int i;

	for (i = 0; i < NUM_THREADS; i++) {
		cout << "main() : creating thread, " << i << endl;
		td[i].thread_id = i;
		td[i].message = (char*)"This is message";
		//强制把参数转换为void *进行传递
		rc =  pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);

		if (rc) {
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
#endif
#ifdef BASIC
	pthread_t tids[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++)
	{
		int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
		if (ret != 0)
		{
			cout << "pthread_create error: error_code=" << ret << endl;
		}
	}
	pthread_exit(NULL);
#endif

	return 0;
}
