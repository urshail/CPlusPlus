#include<iostream>
using namespace std;
class A
{

        public:
        static int i;
        static void printA()
        {
                cout<<"I am static in A"<<endl;
                cout<<"i is "<<i<<endl;
        }
};
class B:public A
{
        public:
        void static printA()
        {
                cout<<"I am static func A inside B"<<endl;
                cout<<"i is "<<i<<endl;
        }
                void printB()
                {
                i=8;
                cout<<"I am print in B"<<endl;
                printA();

                }
};
int A::i=9;
int main()
{
        A ao;
        ao.printA();
        B bo;
        bo.printB();
        return 0;
}
