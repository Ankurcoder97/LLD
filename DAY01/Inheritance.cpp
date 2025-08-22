#include<bits/stdc++.h>
using namespace std;
class car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
public:
    car(string a,string b){
        this->brand=a;
        this->model=b;
        isEngineOn=false;
        currentSpeed = 0;
    }
    //common methods for all cars
            void startEngine(){
            isEngineOn=true;
            cout<<brand<<" "<<model<< "Engine starts with a roar"<<endl;
        }


        void accelerate(){
            if(!isEngineOn){
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
            isEngineOn=false;
            currentSpeed=0;
            cout<<brand <<" "<<model<<":Engine turned off!"<<endl;
        }

};

class Manualcar : public car{//Inherits from car
private:
    int currentGear=0;//specific to manual car
public:
    Manualcar(string b,string m):car(b,m){
        currentGear=0;
    }
    //specialized method for manual car

    void shiftGear(int Gear){//uniquemethod for manual car
        currentGear=Gear;
             cout << brand << " " << model << ": Shifted to gear " << currentGear << endl;

    }
};



class ElectricCar : public car{//Inherits from car
    private:
        int battery_capacity;
public:
        void batteryCapacity(int capacity){
            this->battery_capacity=capacity;
            cout<<"The Battery Capacity is="<<capacity<<endl;
        }
};

int main(){
    
}