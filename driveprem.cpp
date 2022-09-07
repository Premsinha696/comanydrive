#include <iostream>
#include <map>
using namespace std;

class evaluate {
    map<string, int> price = {{"Leather wallet", 1100}, {"Umbrella", 900}, {"cigrate", 200}, {"Honey", 100}};
    map<string, int> gst = {{"Leather wallet", 18}, {"Umbrella", 12}, {"cigratte", 28}, {"Honey", 0}};
    map<string, int> quantity = {{"Leather wallet", 1}, {"Umbrella", 2}, {"cigratte", 3}, {"Honey", 4}};
    int maxGst = 0;
    string nameOfMaxGst ="";
    public:
    void insertItem(string name,int unitPrice, int gs, int qt) {
        price[name] = unitPrice;
        gst[name] = gs;
        quantity[name] = qt;
    }
    
    int calPrice() {
        int sum = 0;
        for(auto i: price) {
            int currPrice =  price[i.first]*quantity[i.first];
            
            int dis = 0;
            if(price[i.first] > 500) {
                dis = (5*price[i.first])*100;
            }
            int currgst = (gst[i.first]*currPrice)/100;
            if(currgst > maxGst) {
                maxGst = currgst;
                nameOfMaxGst = i.first;
            }
            sum+= (currPrice+dis+currgst);
        }
        return sum;
     
    }
    
    string calMaxGstName() {
            return nameOfMaxGst;
    }
    
};


int main()
{
    evaluate ob;
    
    cout<<"Total Price "<<ob.calPrice()<<"\n";
    cout<<"maximum GST paid "<<ob.calMaxGstName()<<"\n";

    return 0;
}