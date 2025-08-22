#include<bits/stdc++.h>
using namespace std;
class product{
    public:
        int price;
        string name;
    product(string name,int price){
        this->price=price;
        this->name=name;
    }
};

class Shopping_cart{
    private:
        vector<product*>products;
    
    public:
        void addproduct(product*p){// working as setter
            products.push_back(p);
        }
        const vector<product*>& getProducts(){// working as getter
            return products;
        }
        //calculating total price;
        double calculateTotal(){
            int total=0;
            for(auto p: products){
                total+=p->price;
            }
            return total;
        }
        //2. violating SRP ->> print invoice should be in separate class
        void printInvoice(){
            cout<<"Shopping cart Invoice:"<<endl;
            for(auto p:products){
                cout<<p->name<<" "<<"$"<<p->price<<endl;
            }
            cout<<"Total: $"<<calculateTotal()<<endl;
        }
         //2. violating SRP ->> SaveTodatabase should be in separate class
        void SaveTodatabase(){
            cout<<"Saving shopping cart to database..."<<endl;
        }
};
int main(){
    Shopping_cart*cart= new Shopping_cart();
    cart->addproduct(new product("Laptop",1500));
    cart->addproduct(new product("Mouse",50));

    cart->printInvoice();
    cart->SaveTodatabase();
}