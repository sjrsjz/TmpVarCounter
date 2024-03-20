#include "TmpVarCounter.h"
#include <iostream>
class MyClass
{
	
public:
	Counter;
	MyClass();
	~MyClass();
	int data{};
private:
	
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
MyClass f()
{
	MyClass a;
	a.data = 1;
	std::cout << "f1:" << a.__TmpVarCounter.getcount() << std::endl;
	std::cout << "f1:" << a.__TmpVarCounter.getaccumulator() << std::endl;
	MyClass b;
	std::cout << "f2:" << a.__TmpVarCounter.getcount() << std::endl;
	std::cout << "f2:" << a.__TmpVarCounter.getaccumulator() << std::endl;
	MyClass c;
	std::cout << "f3:" << a.__TmpVarCounter.getcount() << std::endl;
	std::cout << "f3:" << a.__TmpVarCounter.getaccumulator() << std::endl;
	return a;
}

int main()
{
	MyClass a1[100];
	MyClass a;
	std::cout << "1:" << a.__TmpVarCounter.getcount() << std::endl;
	std::cout << "1:" << a.__TmpVarCounter.getaccumulator() << std::endl;
	MyClass b = f();
	std::cout << "2:" << a.__TmpVarCounter.getcount() << std::endl;
	std::cout << "2:" << a.__TmpVarCounter.getaccumulator() << std::endl;
	MyClass c = f();
	std::cout << "3:" << a.__TmpVarCounter.getcount() << std::endl;
	std::cout << "3:" << a.__TmpVarCounter.getaccumulator() << std::endl;
}