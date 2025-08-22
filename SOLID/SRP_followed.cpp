#include<bits/stdc++.h>
using namespace std;

class product{
public:
    int price;
    string name;
    //default constructor
    product(int price,string name){
        this->price=price;
        this->name=name;
    }
};

class Shoppingcart{
    private:
        vector<product*>products;
    public:
        void addProduct(product*p){
            products.push_back(p);
        }

        const vector<product*>& getProduct(){
            return products;
        }
        double calculateTotal(){
            double total=0;
            for(auto p: products)
            total+=p->price;
            return total;
        }


};

//shopping cart Invoice printer
class printInvoice{
  private:
        Shoppingcart*cart;

    public:
        printInvoice(Shoppingcart*cart){
            this->cart=cart;
        }

    void printinvoice(){
        cout<< "Shopping cart invoice"<<endl;
        for(auto p: cart->getProduct()){
            cout<<p->name<<" "<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }

};

//shopping cart database storage 

class dbstorage{
    private:
    Shoppingcart* cart;

    public:
        dbstorage(Shoppingcart* cart){
            this->cart=cart;
        }
    
    void saveTodatabase(){
        cout<<"Saving shopping cart to database...."<<endl;
    }
};

int main(){
    Shoppingcart*cart=new Shoppingcart();

    cart->addProduct(new product(356,"sugar"));
     cart->addProduct(new product(320,"salt"));

     printInvoice*p=new printInvoice(cart);
     p->printinvoice();

     dbstorage*db =new dbstorage(cart);
     db->saveTodatabase();

}