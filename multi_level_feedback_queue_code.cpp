#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
struct process
{
    int id;     //id of process
    int init;   //initial queue of process
    int at;     //arrival time
    int bt;     //brust time
    bool done;
    int tl;
    int rr;
    int fl;
    int comp;
    int tat;
};
bool sortcal1(process *p1,process *p2)
{
    if(p1->at!=p2->at)
    {
        return (p1->at<p2->at);
    }
    return (p1->id<p2->id);
}
bool sortcal2(process *p1,process *p2)
{
    return (p1->id<p2->id);
}
bool sortcal3(process *p1,process *p2)
{
    if(p1->bt!=p2->bt)
    {
        return (p1->bt<p2->bt);
    }
    return (p1->id<p2->id);
}
bool sortcal4(process *p1,process* p2)
{
	return (p1->comp<p2->comp);
}
int main(int argc,char* argv[]) {
    int  Q,T;
    string F,P;
    Q=atoi(argv[1]);
    T=atoi(argv[2]);
    F=atoi(argv[3]);
    P=atoi(argv[4]);
    queue <process*> q4;
    vector <process*> vec;
    ifstream my_file(argv[3]);
	if (!my_file) 
	{
		cout << "No such input file"<<endl;
	}
	else 
	{
		while (1) 
		{
		    int t1,t2,t3,t4;
			my_file>>t1>>t2>>t3>>t4;
			process *p=new process();
			p->id=t1;
			p->init=t2;
			p->at=t3;
			p->bt=t4;
			p->done=false;
			p->tl=T;
			p->rr=Q;
			vec.push_back(p);
			if (my_file.eof())
			{
			    break;
			}
		}
    }
    my_file.close();
    int n=vec.size();
	vector <process*> vec4;
	vector <process*> vec3;
	vector <process*> vec2;
	vector <process*> vec1;
	n=vec.size();
	int nop=n;
	int t=0;
	int run=-1;
	sort(vec.begin(),vec.end(),sortcal1);
	//while adding processes to q4 there will be 3 ways ie) from q4 from q3 from process list, I am considering id is the tie breaker.
	//while adding processes to q3 if there are more than 1 process of shortest length then i am considering id as tie breaker. 
	//while adding processes to q2 if there are more than 1 process of shortest length then i am considering id as tie breaker.
	//while adding processes to q1 if there are more than 1 process of shortest length then i am considering id as tie breaker.
	while(nop!=0)
	{
	    for(int i=0;i<n;i++)
	    {
	        if(vec[i]->at==t)
	        {
	            if(vec[i]->init==4 && vec[i]->done==false)
                {
                    vec4.push_back(vec[i]);
                }
                else if(vec[i]->init==3 && vec[i]->done==false)
                {
                    vec3.push_back(vec[i]);
                }
                else if(vec[i]->init==2 && vec[i]->done==false)
                {
                    vec2.push_back(vec[i]);
                }
                else if(vec[i]->init==1 && vec[i]->done==false)
                {
                    vec1.push_back(vec[i]);
                }
	        }
	    }
	    sort(vec4.begin(),vec4.end(),sortcal2);
	    for(int i=0;i<vec4.size();i++)
	    {
	        q4.push(vec4[i]);
	    }
	    vec4.clear();
	    if(run==-1 && !q4.empty())
	    {
	        run=4;
	    }
	    else if(run==-1 && q4.empty() && !vec3.empty())
	    {
	        run=3;
	        sort(vec3.begin(),vec3.end(),sortcal3);
	    }
	    else if(run==-1 && q4.empty() && vec3.empty() && !vec2.empty())
	    {
	        run=2;
	        sort(vec2.begin(),vec2.end(),sortcal3);
	    }
	    else if(run==-1 && q4.empty() && vec3.empty() && vec2.empty() && !vec1.empty())
	    {
	        run=1;
	    }
	    if(run==4)
	    {
	        vector <process*> temp_vec;
	        for(int i=0;i<vec1.size();i++)
	        {
	            vec1[i]->tl--;
	            if(vec1[i]->tl>0)
	            {
	                temp_vec.push_back(vec1[i]);
	            }
	            else
	            {
	                vec2.push_back(vec1[i]);
	                vec1[i]->tl=T;
	            }
	        }
	        vec1.clear();
	        vec1=temp_vec;
	        temp_vec.clear();
	        for(int i=0;i<vec2.size();i++)
	        {
	            vec2[i]->tl--;
	            if(vec2[i]->tl>0)
	            {
	                temp_vec.push_back(vec2[i]);
	            }
	            else
	            {
	                vec3.push_back(vec2[i]);
	                vec2[i]->tl=T;
	            }
	        }
	        vec2.clear();
	        vec2=temp_vec;
	        temp_vec.clear();
	        for(int i=0;i<vec3.size();i++)
	        {
	            vec3[i]->tl--;
	            if(vec3[i]->tl>0)
	            {
	                temp_vec.push_back(vec3[i]);
	            }
	            else
	            {
	                vec4.push_back(vec3[i]);
	                vec3[i]->tl=T;
	            }
	        }
	        vec3.clear();
	        vec3=temp_vec;
	        temp_vec.clear();
	    }
	    if(run==3)
	    {
	        vector <process*> temp_vec;
	        for(int i=0;i<vec1.size();i++)
	        {
	            vec1[i]->tl--;
	            if(vec1[i]->tl>0)
	            {
	                temp_vec.push_back(vec1[i]);
	            }
	            else
	            {
	                vec2.push_back(vec1[i]);
	                vec1[i]->tl=T;
	            }
	        }
	        vec1.clear();
	        vec1=temp_vec;
	        temp_vec.clear();
	        for(int i=0;i<vec2.size();i++)
	        {
	            vec2[i]->tl--;
	            if(vec2[i]->tl>0)
	            {
	                temp_vec.push_back(vec2[i]);
	            }
	            else
	            {
	                vec3.push_back(vec2[i]);
	                vec2[i]->tl=T;
	            }
	        }
	        vec2.clear();
	        vec2=temp_vec;
	        temp_vec.clear();
	    }
	    if(run==2)
	    {
	        vector <process*> temp_vec;
	        for(int i=0;i<vec1.size();i++)
	        {
	            vec1[i]->tl--;
	            if(vec1[i]->tl>0)
	            {
	                temp_vec.push_back(vec1[i]);
	            }
	            else
	            {
	                vec2.push_back(vec1[i]);
	                vec1[i]->tl=T;
	            }
	        }
	        vec1.clear();
	        vec1=temp_vec;
	        temp_vec.clear();
	        for(int i=0;i<vec3.size();i++)
	        {
	            vec3[i]->tl--;
	            if(vec3[i]->tl>0)
	            {
	                temp_vec.push_back(vec3[i]);
	            }
	            else
	            {
	                vec4.push_back(vec3[i]);
	                vec3[i]->tl=T;
	            }
	        }
	        vec3.clear();
	        vec3=temp_vec;
	        temp_vec.clear();
	    }
	    if(run==1)
	    {
	        vector <process*> temp_vec;
	        for(int i=0;i<vec2.size();i++)
	        {
	            vec2[i]->tl--;
	            if(vec2[i]->tl>0)
	            {
	                temp_vec.push_back(vec2[i]);
	            }
	            else
	            {
	                vec3.push_back(vec2[i]);
	                vec2[i]->tl=T;
	            }
	        }
	        vec2.clear();
	        vec2=temp_vec;
	        temp_vec.clear();
	        for(int i=0;i<vec3.size();i++)
	        {
	            vec3[i]->tl--;
	            if(vec3[i]->tl>0)
	            {
	                temp_vec.push_back(vec3[i]);
	            }
	            else
	            {
	                vec4.push_back(vec3[i]);
	                vec3[i]->tl=T;
	            }
	        }
	        vec3.clear();
	        vec3=temp_vec;
	        temp_vec.clear();
	    }
	    if(run==4)
	    {
	        process* temp=q4.front();
            (temp->rr)--;
            (temp->tl)--;
            (temp->bt)--;
            if(temp->bt<=0)
            {
                temp->done=true;
                nop--;
                q4.pop();
                temp->fl=4;
                temp->comp=t+1;
                temp->tat=(temp->comp)-(temp->at);
                run=-1;
            }
            else if(temp->rr<=0)
            {
                q4.pop();
                vec4.push_back(temp);   
                temp->rr=Q;
            }
	    }
	    if(run==3)
	    {
	        process* temp=vec3[0];
	        temp->bt--;
	        vector <process*> temp_vec;
	        if(temp->bt<=0)
            {
                temp->done=true;
                nop--;
                temp->fl=3;
                temp->comp=t+1;
                temp->tat=(temp->comp)-(temp->at);
                run=-1;
            }
            else
            {
                temp_vec.push_back(vec3[0]);
            }
            for(int i=1;i<vec3.size();i++)
	        {
	            vec3[i]->tl--;
	            if(vec3[i]->tl>0)
	            {
	                temp_vec.push_back(vec3[i]);
	            }
	            else
	            {
	                vec4.push_back(vec3[i]);
	                vec3[i]->tl=T;
	            }
	        }
	        vec3.clear();
	        vec3=temp_vec;
	    }
	    if(run==2)
	    {
	        process* temp=vec2[0];
	        temp->bt--;
	        vector <process*> temp_vec;
	        if(temp->bt<=0)
            {
                temp->done=true;
                nop--;
                temp->fl=2;
                temp->comp=t+1;
                temp->tat=(temp->comp)-(temp->at);
                run=-1;
            }
            else
            {
                temp_vec.push_back(vec2[0]);
            }
            for(int i=1;i<vec2.size();i++)
	        {
	            vec2[i]->tl--;
	            if(vec2[i]->tl>0)
	            {
	                temp_vec.push_back(vec2[i]);
	            }
	            else
	            {
	                vec3.push_back(vec2[i]);
	                vec2[i]->tl=T;
	            }
	        }
	        vec2.clear();
	        vec2=temp_vec;
	    }
	    if(run==1)
	    {
	        process* temp=vec1[0];
	        temp->bt--;
	        vector <process*> temp_vec;
	        if(temp->bt<=0)
            {
                temp->done=true;
                nop--;
                temp->fl=1;
                temp->comp=t+1;
                temp->tat=(temp->comp)-(temp->at);
                run=-1;
            }
            else
            {
                temp_vec.push_back(vec1[0]);
            }
            for(int i=1;i<vec1.size();i++)
	        {
	            vec1[i]->tl--;
	            if(vec1[i]->tl>0)
	            {
	                temp_vec.push_back(vec1[i]);
	            }
	            else
	            {
	                vec2.push_back(vec1[i]);
	                vec1[i]->tl=T;
	            }
	        }
	        vec1.clear();
	        vec1=temp_vec;
	    }
	    t++;
	}
	sort(vec.begin(),vec.end(),sortcal4);
// 	for(int i=0;i<n;i++)
// 	{
// 	    cout<<vec[i]->id<<" "<<vec[i]->fl<<" "<<vec[i]->tat<<" "<<vec[i]->comp<<endl;
// 	}
    int ttat=0;
    ofstream file(argv[4]);
	if (!file) 
	{
		cout << "File not created!";
	}
	else 
	{
		for(int i=0;i<n;i++)
        {
            file<<"ID: "<<vec[i]->id<<"; Orig. Level: "<<vec[i]->init<<"; Final Level: "<<vec[i]->fl<<"; Comp. Time(ms): "<<vec[i]->comp<<"; TAT(ms): "<<vec[i]->tat<<endl;
            ttat+=(vec[i]->tat);
        }
        file<<"Mean Turnaround time: "<<((float)ttat/n)<<" (ms); Throughput: "<<((float)(1000*n)/t)<<" processes/sec"<<endl;
		file.close();
	}
}