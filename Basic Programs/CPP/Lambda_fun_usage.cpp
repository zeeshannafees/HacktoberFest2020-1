#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class interval
{
    private:


    public:
        int id,start,finish;
        interval()
        {
        }

        void set_values(int s,int f)
        {

            start=s;
            finish=f;
        }
        void print()
        {
            cout<<start<<" "<<finish<<endl;
        }

};

int main()
{
    int a=20;
    vector<interval> it(5);
    cout<<"Lets take example of 5 intervals.\n";
    for(int i=0;i<5;i++)
    {
        int s,f;
        cout<<"Enter the start and finish time of "<<i+1<<" interval\n";
        cin>>s>>f;
        it[i].set_values(s,f);
    }
    auto compare = [](const interval &a,const interval &b) //lamda function
    {
       return a.start<b.start;
    };

    sort(it.begin(),it.end(),compare); //sorts the intervals based on start times

    cout<<"The intervals in sorted order by their start times are\n";
    for(int i=0;i<5;i++)
        it[i].print();
}
