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

class Shoppingcart{
    public:
        vector<product*>products;
        void add_product(product*p){
            products.push_back(p);
        }

        const vector<product*>& get_product(){
            return products;
        }

    int  calculate_total(){
        int total=0;
        for(auto ele: products){
            total+=ele->price;
        }
        return total;
    }
};

class print_Invoice{
private:
    Shoppingcart*cart=new Shoppingcart();
public:
    print_Invoice(Shoppingcart*cart){
        this->cart=cart;
    }

    void print_bill(){
        cout<<"Invoice....."<<endl;
        for(auto p: cart->get_product()){
            cout<<p->name<<" $"<<p->price<<endl;
        }
        cout<<"Total="<<cart->calculate_total()<<endl;
    }
};

class DbPersistence{
    private:
    Shoppingcart*cart;
    public:
        virtual void save(Shoppingcart*cart) = 0;
};

class SqlperSistence:DbPersistence{
    public:
    void save(Shoppingcart*cart){
        cout<<"Saving shopping to SQL DB........"<<endl;
    }
};

class MongoPersistence:DbPersistence{
    public:
    void save(Shoppingcart*cart){
        cout<<"Saving shopping to Mongo DB......"<<endl;
    }
};

class FilePersistence:DbPersistence{
    public:
    void save(Shoppingcart*cart){
        cout<<"Saving shopping to File......"<<endl;
    }
};


int main(){
    Shoppingcart*cart = new Shoppingcart();
    cart->add_product(new product(5000,"Whey"));
    cart->add_product(new product(200,"Cretine"));
    cart->add_product(new product(500,"Peanut Butter"));
    cart->add_product(new product(1500,"PreWorkOut"));
    cart->add_product(new product(3000,"chicken"));

    print_Invoice*p = new print_Invoice(cart);
    p->print_bill();

//save to sql   
SqlperSistence*sql= new SqlperSistence();
sql->save(cart);
//save to mongo
MongoPersistence*mongo = new MongoPersistence();
mongo->save(cart);
//save to file
FilePersistence*file = new FilePersistence();
file->save(cart);


}