#include <setjmp.h>
#include <iostream>

using namespace std;

static jmp_buf g_stack_env;

class Test {
public:
    Test() {
        cout << "Constructor" << endl;
    }
    ~Test() {
        cout << "Destructor" << endl;
    }
};


static void func1(void)
{
	Test t;
	longjmp(g_stack_env, 1);
}

int main(void)
{
    int ret = setjmp(g_stack_env);
    if (0 == ret) {
        cout << "Normal flow" << endl;
        func1();
    } else {
        cout << "Longjump flow" << endl;
    }
    return 0;
}

