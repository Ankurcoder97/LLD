#include<bits/stdc++.h>
using namespace std;

//Real life car
class car{
public:
    virtual void startEngine()=0;
    virtual void shiftgear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual ~car(){}//virtual constructor
};
class Sportscar:public car{//child 
    public:
        string brand;
        string model;
        bool isEngineon;
        int currentSpeed;
        int CurrentGear;

        Sportscar(string b,string a){//constructor
            this->brand=b;
            this->model=a;
            isEngineon=false;
            currentSpeed=0;
            CurrentGear=0;
        }

        void startEngine(){
            isEngineon=true;
            cout<<brand<<" "<<model<< "Engine starts with a roar"<<endl;
        }

        void shiftgear(int gear){
            if(!isEngineon){
                cout<<brand<<" "<<model<<"Engine is off! cannot shift the gear";
                return;
            }
            CurrentGear=gear;
             cout << brand << " " << model << ": Shifted to gear " << CurrentGear << endl;

        }

        void accelerate(){
            if(!isEngineon){
                cout<<brand<<" "<<model<<"Engine is off! cannot be accelerated";
                return;
            }
            currentSpeed+=20;
            cout<<brand<<" "<<model<<":Accelerating to"<<currentSpeed<<"km/h"<<endl;
        }

        void brake(){
            currentSpeed-=20;
            if(currentSpeed<0) currentSpeed=0;
            cout<<brand<<" "<<model<<":braking speed is now"<<currentSpeed<<"km/h"<<endl;
        }
        
        void stopEngine(){
            isEngineon=false;
            CurrentGear=0;
            currentSpeed=0;
            cout<<brand <<" "<<model<<":Engine turned off!"<<endl;
        }

};
int main(){
    car* mycar = new Sportscar("ford","Mustang");
    mycar->startEngine();
    mycar->shiftgear(1);
    mycar->accelerate();
    mycar->shiftgear(2);
    mycar->brake();
    mycar->stopEngine();

}