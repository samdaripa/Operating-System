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
};
int tat[50],t=0,wt[50],st[50],ct[50]= {0},rt[50];
int remain=0,timee=0,i,check=0;
float totwt=0,totta=0;
int qt;
vector<process> getSystem()
{
    int n;
    cout<<"Enter no. of process : ";
    cin>>n;
    cout<<"Quantum time : ";
    cin>>qt;
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
        rt[i]=v[i].burst;
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
bool compare1(process a,process b)
{
    return a.arrival< b.arrival;
}

void rr(vector<process>v)
{
    cout<<"\n\t\t\t\t       *** Gantt Chart ***\n\n";
    cout<<0;
    int i;
    sort(v.begin(),v.end(),compare1);
    for(timee=0, i=0; remain!=v.size();)
    {

            if(rt[i]<=qt&&rt[i] >0)
            {
                timee+=rt[i];
                rt[i]=0;
                check=1;
                cout<<"-<p"<<v[i].pid<<">-"<<timee;
            }
            else if(rt[i]>qt)
            {
                timee+=qt;
               rt[i]=rt[i]-qt;
                cout<<"-<p"<<v[i].pid<<">-"<<timee;

            }
            if(rt[i]==0&&check==1)
            {
                remain++;
                ct[i]=timee;
                tat[i]=ct[i]-v[i].arrival;
                wt[i]=tat[i]-v[i].burst;

                totwt+=timee-v[i].burst-v[i].arrival;
                totta+=timee-v[i].arrival;
                check=0;
            }
            if(i == v.size() - 1)
            {
                  i = 0;
            }
            else if(v[i + 1].arrival <= timee)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
        }
}
int main()
{
    vector<process>v=getSystem();
    rr(v);
    //ganttChart(v);
    printSystem(v);
    return 0;
}

