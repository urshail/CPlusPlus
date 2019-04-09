#include<iostream>
using namespace std;

class base
{
protected:
int shaili;
public:
  virtual void fun(int tmp=11)
  {
     shaili=tmp;
     cout<<"inside base i is "<<shaili<<endl;
  }
};

class der : public base
{
public:
  void fun(int tmp=22)
  {
    shaili=tmp;
    cout<<"inside der, i is "<<shaili<<endl;
  }
};


int main()
{
        // No issue in these.
        //base o;   
        //o.fun();
        //der d;
        //d.fun();

        // can you predict it ?
        base* po = new der;
        po->fun();
        
        return 0;
}
