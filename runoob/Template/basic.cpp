#include <iostream>
using namespace std;

//#define BASIC
//#define USING
#define NEST

#ifdef BASIC
namespace first_space{
	 void func() {
	 	cout << "Inside first_space" << endl;
	 }
}

namespace second_space{
	void func() {
		cout << "Inside second_space" << endl;
	}
}
#endif

#ifdef USING
namespace first_space{
	void func() {
		 cout << "Inside first_space" << endl;
	}
}
namespace second_space{
	void func() {
		 cout << "Inside second_space" << endl;
	}
}
using namespace first_space;
using std::cout;
#endif

#ifdef NEST
namespace first_space{
	 void func() {
	 	cout << "Inside first_space" << endl;
	 }
	 namespace second_space{
	 	void func() {
			cout << "Inside second_space" << endl;
		}
	 }
}
using namespace first_space::second_space;
#endif

int main()
{
#ifdef BASIC
	first_space::func();
	second_space::func();
#endif

#ifdef USING
	func();
	cout << "std::endl is used with std!" << std::endl;
#endif

#ifdef NEST
	func();
#endif

	return 0;
}
