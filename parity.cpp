#include<iostream>
#include<bits/stdc++.h>
#define max 30
using namespace std;
class process
{
public:
    int pid;
    int arrival;
    int burst;
    int priority;
};
int tat[50],t=0,wt[50],st[50],ct[50]= {0};
float totwt=0,totta=0;

vector<process> getSystem()
{
    int n;
    cout<<"Enter no. of process : ";
    cin>>n;
    vector<process>v(n);
    system("cls");
    for(int i=0; i<n; i++)
    {
        v[i].pid=i+1;
        cout<<"PROCESS : "<<v[i].pid<<endl;
        cout<<"Arrival Time : ";
        cin>>v[i].arrival;
        cout<<"Burst Time : ";
        cin>>v[i].burst;
        cout<<"Priority : ";
        cin>>v[i].priority;
        ct[i]=0;
        cout<<"_______________\n\n";
    }
    return v;
}
void printSystem(vector<process>v)
{
    cout<<"\n\t\t\t\t       *** OUR SYSTEM ***\n\n";
    cout<<"--------------------------------------------------------------------------------------------------\n";

    cout << "Processes  "<< " Arrival time  "<< " Burst time  "<< " complete time  "
         << " Waiting time  " << " Turn around time\n";
    cout<<"---------------------------------------------------------------------------------------------------\n";
    for(int i=0; i<v.size(); i++)
    {
        cout << "   " << v[i].pid << "\t\t" << v[i].arrival << "\t\t" << v[i].burst<< "\t\t" << ct[i]<<"\t    "
             << wt[i] <<"\t\t  "<< tat[i] <<endl;
    }
    cout<<endl<<"Average Waiting Time :"<<totwt/v.size();
    cout<<endl<<"Average Turn around Time :"<<totta/v.size();
}

bool compare3(process a,process b)
{
    return a.priority< b.priority;
}
void ganttChart(vector<process>v)
{
    cout<<"\n\t\t\t\t       *** Gantt Chart ***\n\n";
    for(int i=0; i<v.size(); i++)
    {
        cout<<ct[i]-v[i].burst<<"-<p"<<v[i].pid<<">-"<<ct[i]<<endl;
    }
}
void priority(vector<process>v)
{
    sort(v.begin(),v.end(),compare3);
    for(int i=0; i<v.size(); i++)
    {
        if(i==0)
            st[i]=v[i].arrival;
        else
            st[i]=ct[i-1];
        wt[i]=st[i]-v[i].arrival;
        ct[i]=st[i]+v[i].burst;
        tat[i]=ct[i]-v[i].arrival;
        totwt+=wt[i];
        totta+=tat[i];
    }
}
int main()
{
    vector<process>v=getSystem();
    priority(v);
    ganttChart(v);
    printSystem(v);
    return 0;
}

