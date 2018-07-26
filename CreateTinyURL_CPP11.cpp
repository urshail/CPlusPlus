//Create Tiny URL  ( created with c++ 11 )

#include<iostream>
#include <string>
//rand
#include <cstdlib>
#include <map>
using namespace std;


class TinyUrl
{
        map<string,string> urlC;

public:
       /* TinyUrl(){}
        explicit TinyUrl(const TinyUrl& obj)
        {
        }
        TinyUrl(TinyUrl&& obj)
        {
        }
        TinyUrl& operator=(const TinyUrl& obj)
        {
          return *this;
        }*/
        string createTinyUrl(string url)
        {
                string tinyUrl = "ns"+url.substr( url.find_first_of('.')+1, 2)  + to_string(rand()%1000);
                urlC.insert(std::pair<string,string>(tinyUrl,url));
                return tinyUrl;
        }
        void printUrl()
        {
                map<string,string>::iterator itr = urlC.begin();
                while(itr!=urlC.end())
                {
                        cout<<itr->first<<" => "<<itr->second<<endl;
                        itr++;
                }
        }
        string findFullUrl(string url)
        {
                return urlC[url];
        }
        void deleteUrl(string url)
        {
                urlC.erase(url);
        }
};

int main()
{
TinyUrl obj;
cout<< " tinyurl is "<< obj.createTinyUrl("www.google.com");
obj.createTinyUrl("www.google.com/project1.php");
obj.createTinyUrl("www.google.com/project2.php");
obj.createTinyUrl("www.google.com/project3.php");

string s4=obj.createTinyUrl("www.google.com/project4.php");
cout<<endl;
obj.printUrl();
cout<<endl;
cout<<"value of "<<s4<<" is "<< obj.findFullUrl(s4)<<endl;
cout<<"deleting value of s4"<<endl;
obj.deleteUrl(s4);
cout<<endl<<"list of all Urls :"<<endl;
obj.printUrl();

return 0;
}
