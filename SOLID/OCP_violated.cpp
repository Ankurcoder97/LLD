#include<bits/stdc++.h>
using namespace std;

class product{
    public:
        int price;
        string name;
    product(int price,string name){
        this->price=price;
        this->name=name;
    }
};

class ShoppingCart{
   public:
        vector<product*>products;
    void add_product(product*p){
        products.push_back(p);
    }

    const vector<product*>& get_product(){
        return products;
    }

    int calculateTotal(){
        int sum=0;
        for(auto ele: products){
            sum+=ele->price;
        }
        return sum;
    }
};

class PrintInvoice{
    private:
    ShoppingCart*cart;
    public:
        PrintInvoice(ShoppingCart*cart){
            this->cart=cart;
        }

    void bill_print(){
        cout<<"Invoice is....."<<endl;
        for(auto ele: cart->get_product()){
            cout<<ele->name<<" $"<<ele->price <<endl;
        }
        cout<<"Total="<<cart->calculateTotal();
    }
};

class StoreInDB{
    private:
          ShoppingCart*cart;
    public:
        StoreInDB(ShoppingCart*cart){
            this->cart=cart;
        }
    void StoreinSQL(){
        cout<<"Storing data in SQL.."<<endl;
    }

    void StoreinMongoDB(){
        cout<<"Storing data in MongoDB"<<endl;
    }
};
int main(){
    ShoppingCart*cart= new ShoppingCart();

    cart->add_product(new product(63000,"LAPTOP"));
    cart->add_product(new product(5000,"Keyboard"));

    PrintInvoice*p = new PrintInvoice(cart);
    p->bill_print();


    StoreInDB*db = new StoreInDB(cart);
    db->StoreinSQL();
    db->StoreinMongoDB();


}
