#include <iostream>
#include <csignal>
#include <unistd.h>
#include <cstdlib>
#include <windows.h>

//#define BASIC
//#define RAISE
//#define PAUSE
using namespace std;

#ifdef BASIC
void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received.\n";

	exit(signum);
}
#endif

#ifdef RAISE
void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") received.\n";
	exit(signum);
}
#endif

int main()
{
#ifdef RAISE
	int i = 0;
	signal(SIGINT, signalHandler);
	
	while(++i){
		cout << "Going to sleep..." << endl;
		if (i == 3) {
			//raise用来生成信号
			raise(SIGINT);
		}
		sleep(1);
	}
#endif
#ifdef BASIC
	signal(SIGINT, signalHandler);

	while (1) {
		cout << "Going to sleep..." << endl;
		sleep(1);
	}
#endif
#ifdef PAUSE
	int a = 1;
	while (a)
	{
		cout << "welcome to wenliang world." << endl;
		sleep(100);
	}
	system("pause");
#endif

	return 0;
}
