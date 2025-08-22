#include<bits/stdc++.h>
using namespace std;

class car{
protected:
        string brand;
        string model;
        bool isEngineon;
        int currentSpeed;
        int CurrentGear;
public:
    car(string a,string b){
        this->brand=a;
        this->model=b;
        isEngineon=true;
        CurrentGear=0;
        currentSpeed=0;
    }
    virtual int accelerate()=0;//Abstract class defines inside child class
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
class Manualcar: public car{
    public:
        Manualcar(string a,string b):car(a,b){
        this->brand=a;
        this->model=b;
    }
        int accelerate() {
            currentSpeed+=20;
            cout<<brand <<" "<<model<<"Manual car is Acclerating with speed"<<currentSpeed<<endl;
        }
};
class ElectricCar : public car{
    public:
        ElectricCar(string a,string b):car(a,b){
        this->brand=a;
        this->model=b;
    }
        int accelerate(){
            currentSpeed+=15;
            cout<<brand <<" "<<model<<"Electric car is Acclerating with speed"<<currentSpeed<<endl;
        }
};
int main(){
   Manualcar* Mycar = new Manualcar("Mustang", "ABC");
   Mycar->startEngine();
   Mycar->shiftgear(1);
   Mycar->accelerate();
   Mycar->shiftgear(2);
   Mycar->brake();
   Mycar->stopEngine();


   cout<<" ---------------------------------------------"<<endl;

ElectricCar* Mycar1 = new ElectricCar("Suzuki","TVS");
   Mycar1->startEngine();
   Mycar1->shiftgear(1);
   Mycar1->accelerate();
   Mycar1->shiftgear(2);
   Mycar1->brake();
   Mycar1->stopEngine();


}