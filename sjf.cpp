#include<iostream>
using namespace std;
class sjf{
    int pid,arrival_time,burst_time,completion_time,waiting_time,total_time;
    bool ch=false;
    public:
    void get(int x, int y, int z){
        pid=x; arrival_time=y; burst_time=z;
    }
    void calc(int a){
        completion_time=a;
        total_time=completion_time-arrival_time;
        waiting_time=total_time-burst_time;
        ch=true;
    }
    void display(){
        cout<<pid<<"  "<<arrival_time<<"  "<<burst_time<<"  "<<completion_time<<"  "<<waiting_time
        <<" "<<total_time<<endl;
    }
    int a(){ return arrival_time; }
    int b(){ return burst_time; }
    bool is(){ return ch; }
};

int main(){
    sjf obj[5];
    int a,b;
    for(int i=0;i<5;i++){
        cout<<"Enter arrival time and burst time"<<endl;
        cin>>a>>b;
        obj[i].get(i,a,b);
    }
    int completed=0, curr=0;
    while(completed!=5){
        int index=-1, min=999;
        for(int i=0;i<5;i++){
            if(obj[i].a()<=curr && !(obj[i].is())){
                if(obj[i].b()<min){
                    min=obj[i].b();
                    index=i;
                }
            }
        }
        if(index!=-1){
            curr+=obj[index].b();
            obj[index].calc(curr);
            completed++;
        }
        else curr++;
    }
    cout<<endl<<"pid arrival_time burst_time completion_time waiting_time total_time "<<endl;
    for(int i=0;i<5;i++) obj[i].display();
    return 0;
}
