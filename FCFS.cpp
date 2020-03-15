#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class process
{
public:
    int pid;
    int arrival;
    int burst;
};
int tat[50],t=0,wt[50],ct[50]= {0};
vector<process> getSystem()
{
    int n;
    cout<<"Enter no. of process : ";
    cin>>n;
    vector<process>v(n);
    system("cls");
    for(int i=0; i<v.size(); i++)
    {
        v[i].pid=i+1;
        cout<<"PROCESS : "<<v[i].pid<<endl;
        cout<<"Arrival Time : ";
        cin>>v[i].arrival;
        cout<<"Burst Time : ";
        cin>>v[i].burst;
        ct[i]=0;
        cout<<"_____________\n\n";
    }
    return v;
}
void printSystem(vector<process> v)
{
    cout<<"\n\t\t        *** OUR SYSTEM ***\n";
   cout << "Processes  "<< " Arrival time  "<< " Burst time  "<< " complete time  "
         << " Waiting time  " << " Turn around time\n";
    for(int i=0; i<v.size(); i++)
    {
        cout << "   " << v[i].pid << "\t\t" << v[i].arrival << "\t\t" << v[i].burst<< "\t\t" << ct[i]<<"\t    "
            << wt[i] <<"\t\t  "<< tat[i] <<endl;
    }
}
bool compare(process a,process b)
{
    return a.arrival< b.arrival;
}
void fcfs(vector<process>v)
{
    sort(v.begin(),v.end(),compare);
    ct[0]=v[0].burst+v[0].arrival;
    tat[0]=ct[0]-v[0].arrival;
    wt[0]=tat[0]-v[0].burst;
    for(int i=1; i<v.size(); i++)
    {
        ct[i]=ct[i-1] + v[i].burst;
        tat[i]= ct[i]- v[i].arrival;
        wt[i]=tat[i]-v[i].burst;
    }
}
void chart(vector<process>v)
{
    cout<<"\n\t\t\t\t       *** Gantt Chart ***\n\n";
    for(int i=0;i<v.size();i++)
    {
            cout<<ct[i]-v[i].burst<<"-<p"<<v[i].pid<<">-"<<ct[i]<<endl;
    }
}

int main()
{
    vector<process>v=getSystem();
    fcfs(v);
    chart(v);
    printSystem(v);
    return 0;
}
