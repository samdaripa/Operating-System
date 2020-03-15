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
int tat[max],wt[max],st[max],ct[max]= {0},rt[max];
int check=-1,context;
float totwt=0,totta=0;
int remain=0,timee=0,smallest,endTime;

vector<process> getSystem()
{
    int n;
    cout<<"Enter no. of process : ";
    cin>>n;
    cout<<"Context switch : ";
    cin>>context;
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
        rt[i]=v[i].burst;
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

void priority_preemptive(vector<process>v)
{

    for(int i =0; i<v.size(); i++)
        rt[i]=v[i].burst;
    cout<<"\n\t\t\t\t       *** Gantt Chart ***\n\n";
    cout<<0;
    rt[9]=9999;
    v[9].priority=9999;
    for(timee=0; remain!=v.size(); timee++)
    {
        smallest=9;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i].arrival<=timee && rt[i]>0&&v[i].priority<v[smallest].priority)
            {
                smallest=i;
                 if(check==-1)
                    check=v[smallest].pid;
            }
        }
        rt[smallest]--;
       if(v[smallest].pid != check){
            check=v[smallest].pid;
             cout<<"-<"<<"IDEAL"<<">-"<<timee+context;
             timee+=context;
        }
        cout<<"-<p"<<v[smallest].pid<<">-"<<timee+1;

        if(rt[smallest]==0)
        {
            remain++;
            endTime=timee+1;

            ct[smallest]=endTime;
            tat[smallest]=ct[smallest]-v[smallest].arrival;
            wt[smallest]=tat[smallest]-v[smallest].burst;

            totwt+=endTime-v[smallest].burst-v[smallest].arrival;//totwt+=wt[smallest]
            totta+=endTime-v[smallest].arrival;//totta+=tat[smallest]
        }
    }
}
int main()
{
    vector<process>v=getSystem();
    priority_preemptive(v);
    printSystem(v);
    return 0;
}



