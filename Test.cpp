#include<iostream>
using namespace std;
class A{
public:
    void message(){
        cout<<"A"<<endl;
    }
};

class B{
public:
    void message(){
        cout<<"B"<<endl;
    };
};

class C:public A, public B{
public:
    void test(){
        B::message();
    };
};

int main()
{
    C c;
    c.test();

    return 0;
}
