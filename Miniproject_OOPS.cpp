#include<iostream>
#include<exception>
#include<math.h>
#include<iomanip>
using namespace std;
class BankValidationException:public exception{
public:
    char* what() const throw(){
        return "Invalid Data";
    }
};
class Account{
  public:
    float p;
    int t;
    float rateOfInterest;
Account(float principal,int tenure, int age, string gender){
    p=principal;
    t=tenure;
    if(gender=="Male"){
          if(age<60)
            rateOfInterest=9.8;
          else if(age>=60)
            rateOfInterest=10.5;
    }
    else if(gender=="Female"){
          if(age<58)
            rateOfInterest=10.2;
          else if(age>=58)
            rateOfInterest=10.8;
     }
}
virtual float calculateInterest()=0;
};
class RDAccount:public Account{
    public:
    float n=4,a,i,amount=0;
    string g;
   float r=rateOfInterest/100;
    BankValidationException e;
RDAccount(float principal,int tenure,int age,string gender):Account(principal,tenure,age,gender){
        g=gender;
        a=age;
}
float calculateInterest(){
    //cout<<"Principal"<<" "<<"Rate"<<"   "<<"Months"<<"  "<<"Years "<<"  "<<"cRate  "<<"    "<<"Interest paid"<<endl;
        for( i=(t*12);i>0;i--){
    //  cout<<"  "<<p<<"    "<<r<<"    "<<i<<"    "<<<<(i/12)<<"     "<<pow((1+r/n),(n*i/12))-1<<" "<<p*(pow((1+r/n),(n*i/12))-1)<<endl;
           amount+=p*(pow((1+r/n),(n*i/12))-1);
        }
        return amount;
}
void validateData(){
        try{
          if((p>=500)&&(t==5||t==10)&&(g=="Male"||g=="Female")&&(a>1||a<100))
        cout<<"Total Interest: "<<calculateInterest();
          else
             throw e;
        }
        catch(exception &ex){
          cout<<ex.what();
        }
}
};
int main(){
int y,a;
float x;
string g;
cin>>y>>x>>a>>g;
RDAccount r(x,y,a,g);
r.validateData();
return 0;
}
