#ifndef node_h
#define node_h
#include <string>
using namespace std;
//#include <string.h>

class NODE
{
private:
  NODE* nextptr;
  NODE* pptr;
  string species;
  int age, petage;
  //string owner_name;
  string pet_name;
  int vaccine;
  int petfood;
  int profit;
public:
  NODE();
string owner_name;
  void set_species(string t){species = t;}
  void set_age(int t){age=t;}
  void set_petage(int t){petage=t;}
  void set_ownername(string t){owner_name = t;}
  void set_petname(string t){pet_name=t;}
  void set_vac(int t){vaccine=t;}
  void set_food(int t){petfood=t;}
  void set_profit(int t){profit=t;}
  int get_profit(){return profit;}
  string get_name(){return owner_name;}
  NODE* get_next(){return nextptr;}
  int get_petage(){return petage;}
  string get_petname(){return pet_name;}
  string get_species(){return species;}
  int get_vac(){return vaccine;}
  int get_age(){return age;}
  void set_next(NODE*t){nextptr=t;}
  void set_prev(NODE*t){pptr=t;}
  ~NODE();
};

typedef NODE* NodePtr;

NODE::NODE(){
  species = "unidentified";
  age = 0;
  owner_name = "N/A";
  pet_name = "Unspecified";
  vaccine = 0;
  petfood=0;
  nextptr=NULL; 
  pptr=NULL;
}
NODE::~NODE(){
  
}
#endif

