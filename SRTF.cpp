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
int tat[50],t=0,wt[50],rt[50],ct[50]= {0};
float totwt=0,totta=0;
int remain=0,timee=0,smallest,endTime;

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

void srtf(vector<process>v){

    for(int i =0;i<v.size();i++)
        rt[i]=v[i].burst;
    cout<<"\n\t\t\t\t       *** Gantt Chart ***\n\n";
    cout<<0;
   rt[9]=9999;
    for(timee=0;remain!=v.size();timee++)
    {
        smallest=9;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].arrival<=timee && rt[i]<rt[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }
        rt[smallest]--;
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
    srtf(v);
    printSystem(v);
    return 0;
}

