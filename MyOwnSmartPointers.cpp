//Smart Pointers

#include<iostream>
using namespace std;
template <class T>
class SP
{
      T* ptr;
      public:
      SP(T *p=0):ptr(p)
      {
           cout<<"assigned value. ptr is "<<ptr<<endl;
           cout<<typeid(ptr).name()<<endl;
      }
      T& operator*()
      {
            return *ptr;
      }
      T* operator->()
      {
            return ptr;
      }
      SP& operator=(SP& obj)
      {
            ptr=obj.ptr;
      }
      ~SP()
      {
           if(ptr) delete ptr;
           cout<<"going out of scope now"<<endl;
      }
};
class Test
{
      public:
      void work()
      {
            cout<<"work started"<<endl;
      }
      ~Test()
      {
             cout<<"Destructor of Test got called"<<endl;
      }
};
int main()
{
    {
      SP<Test> mysh(new Test[4]);
      mysh->work();
    }
    cin.get();
}
