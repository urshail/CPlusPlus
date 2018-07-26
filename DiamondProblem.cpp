//Diamond problem 

#include<iostream>
using namespace std;
class A 
{
 public :
    A(){ cout<<"A construct"<<endl; }
    int a;
};
class B : virtual public A {};
class C : virtual public A {};
class D : public B,C 
{
};
int main()
{
D obj; // calls A constructor twice. One with B object and one with C's object.
obj.a=0;
cout<<obj.a<<endl;
return 0; 
}
