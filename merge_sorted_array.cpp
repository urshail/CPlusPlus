#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void merge_sorted_vec(vector<int> v1,vector<int>v2)
{
}
int main()
{
        vector<int> v1={1,2,5,7,8,9};
        vector<int> v2={3,6,8,19};
        vector<int> v3;
        //copy(v1.begin(),v1.end(),ostream_iterator<int>(cout," "));
        //
        int i=0,j=0;
        int v1s=v1.size();
        int v2s=v2.size();
        vector<int>::iterator v1i=v1.begin(),v2i=v2.begin();
        while(i<v1s && j<v2s)
        {
                if(v1[i]<v2[j])
                        v3.push_back(v1[i++]);
                else
                        v3.push_back(v2[j++]);
        }
        while(i<v1s)
                v3.push_back(v1[i++]);
        while(j<v2s)
                v3.push_back(v2[j++]);
        cout<<endl;
        copy(v3.begin(),v3.end(),ostream_iterator<int>(cout," "));

        return 0;
}
