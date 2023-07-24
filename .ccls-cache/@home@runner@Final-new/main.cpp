#include <iostream>
#include <string>
//#include <cstring>
#include "queue.h"
#include "ll.h"
//#include "sorting.h"
using namespace std;

int main() {
  cout << "Data collector and filtering for Pet Store." << endl;
  cout << " Start queueing and collecting data" << endl<<endl;
  int n=1;
  Queue q;
  NodePtr t=new NODE[100];
  while(1){
    //q.enqueue(t);
    cout<< "Customer No: "<< n <<endl;
    cout<<"Name: ";
    string name;
    //cin>>name;
    cin>>(*(t+n-1)).owner_name;
    //(*(t+n-1)->set_ownername(name);
    //(*(t+n-1).owner_name;
    cout<<"age: ";
    int age;
    cin>>age;
    (*(t+n-1)).set_age(age);
    cout<<"Pets: ";
    string pets;
    cin>>pets;
    (*(t+n-1)).set_species(pets);
    cout<<"Pets name: ";
    string petname;
    cin>>petname;
    (*(t+n-1)).set_petname(petname);
    cout<<"Pets Age: ";
    int petage;
    cin>>petage;
    (*(t+n-1)).set_petage(petage);
    cout<<"Does the pet vaccinated: "<<endl;
    cout<<"1. Yes"<<endl<<"2. No"<<endl;
    int vac;
    cin>>vac;
    (*(t+n-1)).set_vac(vac);
    cout<<" Services?"<<endl;
    cout<< "1. Taking Vaccinces"<<endl<<"2. Buying pets food"<<endl;
    int choice;
    int petfood=0;
    cin>>choice;
    if (choice==1){
      (*(t+n-1)).set_vac(1);
      (*(t+n-1)).set_food(0);
    }
    if (choice==2){
      cout << "Which brand of pets food did the customer buy: " << endl;
    cout << "1. Purina Pro Plan" << endl
         << "2. Pedigree" << endl
         << "3. Royal chain" << endl
         << "4. Bil-Jac" << endl
         << "Order: ";
      cin>>petfood;
      (*(t+n-1)).set_food(petfood);
    }
    //NodePtr y = new NODE(*(t + n - 1)); // Create a new NODE object with data from the array
    q.enqueue(&(*(t + n - 1)));
    //t++;
    //t=&(*(t+1));
    n++;
    cout<<endl<<"Next customer?"<<endl;
    cout<<"1. Yes\n2. No"<<endl;
    int con;
    cin>>con;
    if (con==2){
      break;
    }
    cout<<"=============================================="<<endl;
  }
  
  LL l;
  int i;
  //NodePtr t;
  int size=q.get_size();
  cout<<size<<endl;
  for(i=0;i<size;i++){
    string y=q.get_name();
    NodePtr x = q.dequeue();
    cout<<"Bills customer no. "<<i+1<<" "<<"name: "<<y<<endl;
    cout<<"Profit earn: ";
    int profit;
    cin>>profit;
    l.add(x,profit);
  }
  
  cout<<"Finished Accouting"<<endl;
  cout<<endl;
  int a;
  while (1) {
    cout << "Choose what you want to do with the data " << endl;
    cout << "1. List of customers name from youngest to oldest" << endl
         << "2. Tell the most popular pets's food" << endl
         << "3. Tell me the youngest pet and the youngest customer" << endl
         << "4. Tell me the oldest pet and the oldest customer" << endl
         << "5. List me the vaccinated pet and unvaccinated pet" << endl
         << "6. Tell me the average age of customers and pets in the data list" << endl
         << "7. Summarize all data briefly" << endl
         << "8. Total profit" << endl
         << "9. Cancel the selection" << endl;
    cin>>a;
    if (a == 9) {
      cout << "Program terminated" << endl;
      break;
    }
    cout << "======================================================" << endl;
    if (a==3){
      l.lowest();
    }
    if (a==4){
      l.highest();
    }
    if (a==5){
      l.vac_check();
    }
    if (a==6){
      l.average();
    }
    if (a==7){
      cout<<"Number of customers in the data list: "<<l.get_size()<<endl;
      cout<<"Total Profit: "<<l.get_total_profit()<<endl;
      cout<<"Average customers age is "<<l.get_average_age()<<" years old."<<endl;
      cout<<"Average pets age is "<<l.get_average_petage()<<" years old."<<endl;
      cout<<"Number of vaccinated pets: "<<l.get_vaccinated()<<endl;
      cout<<"Number of unvaccinated pets: "<<l.get_unvaccinated()<<endl;
    }
    if (a==8){
      cout<<"Total Profit: "<<l.get_total_profit()<<endl;
    }
}
}