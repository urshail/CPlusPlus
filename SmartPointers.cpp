//Smart Pointers

#include<iostream>
#include<memory>
using namespace std;


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
#if __cplusplus < 199711L

    //auto pointer : object ownership
    {
      auto_ptr<Test> ap1(new Test);
      ap1->work();
      cout<<"first pointer value is            :"<<ap1.get()<<endl;
      auto_ptr<Test> ap2(ap1);
      cout<<"first pointer value after copy is :"<<ap1.get()<<endl;
      cout<<"second pointer value is           :"<<ap2.get()<<endl;
    }
#endif
#if __cplusplus > 199711L
    cout<<"========Shared Pointer=========="<<endl;
    //shared_ptr : refrence counting
    shared_ptr<Test> sp1(new Test);
    cout<<sp1.get()<<endl;
    sp1->work();
    shared_ptr<Test> sp2(sp1);
    cout<<sp1.get()<<endl;
    cout<<"no of ptr exist with first pointer  :"<<sp1.use_count()<<endl;
    cout<<"no of ptr exist with second pointer :" <<sp2.use_count()<<endl;
    sp1.reset();
    cout<<"no of ptr exist with second pointer aft firsst reset:" <<sp2.use_count()<<endl;
#endif

cin.get();
}
