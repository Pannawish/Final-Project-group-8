#include "node.h"

class LL {
  NodePtr hol; // head of linked list
  int size;
  int vaccinated=0, unvaccinated=0;
  int average_age=0, average_petage=0;
  int total_profit;
public:
  LL();
  int get_size(){return size;}
  int get_vaccinated(){return vaccinated;}
  int get_unvaccinated(){return unvaccinated;}
  int get_average_age(){return average_age;}
  int get_average_petage(){return average_petage;}
  int get_total_profit();
  void average();
  void vac_check();
  void add(NodePtr x, int y);
  void lowest();
  void highest();
  void insert(NodePtr x, int y);
  void printCustomerNames() const;
  //void printOldestToYoungest();
  void sorted();
  string mostPopularFood();
  ~LL();
};

LL::LL() {
  this->hol = NULL;
  //this->hol2 = NULL;
  size = 0;
}

LL::~LL() {
  cout << "deleting all nodes" << endl;
  NodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    hol = hol->get_next();
    delete t;
    t = hol;
  }
}

void LL::add(NodePtr x,int y){
  x->set_profit(y);
  NodePtr new_node=new NODE(*x);
  new_node->set_next(NULL);
  //delete x; //edit
  if (size==0){
    hol=new_node;
    //hol->set_next()=NULL;
  }
  else{
    NodePtr t=hol;
    while(t->get_next()) t=t->get_next();
    t->set_next(new_node);
  }
  size++;
}

void LL::lowest() {
    NodePtr x = hol;
    int min1 = 1000; // Initialize to a large value
    int min2 = 1000; // Initialize to a large value
    NodePtr temp1, temp2;

    for (int i = 0; i < size; i++) {
        int y = x->get_petage();
        int z = x->get_age();

        if (y < min1) {
            temp1 = x;
            min1 = y;
        }

        if (z < min2) {
            temp2 = x;
            min2 = z;
        }

        x = x->get_next();
    }

    cout << "The youngest pet is " << temp1->get_petname() << ", " << temp1->get_species() << ", " << temp1->get_petage() << " years old. Owner: " << temp1->get_name() << endl;
    cout << "The youngest customer is " << temp2->get_age() << " years old. Mr./Ms. "<<temp2->get_name() << endl;
}


void LL::highest(){
  int max1=0, max2=0, i;
  NodePtr x=hol;
  NodePtr temp1,temp2;
  for(i=0;i<size;i++){
    int y=x->get_petage();
    int z=x->get_age();
    if (y>max1){
      temp1=x;
      max1=y;
    }
    if (z>max2){
      temp2=x;
      max2=z;
    }
    x=x->get_next();
    }
  cout<<"The oldest pet is "<<temp1->get_petname()<<", "<<temp1->get_species()<<", "<<temp1->get_petage()<<" years old. Owner: "<<temp1->get_name()<<endl;
  cout<<"The oldest customer is "<<temp2->get_age()<< " years old. Mr./Ms. "<<temp2->get_name()<<endl;
}

void LL::vac_check(){
  NodePtr x=hol;
  int i;
  vaccinated=0; unvaccinated=0;
  cout << "List of vaccinated pets." << endl;
  for(i=0;i<size;i++){
  if (x->get_vac()==1){
    cout<<vaccinated+1<<". "<< x->get_petname()<<", "<<x->get_species()<<". Owner: "<<x->get_name()<<endl;
    vaccinated++;
    x=x->get_next();
  }
  }
  x=hol;
  cout << "List of unvaccinated pets." << endl;
  for(i=0;i<size;i++){
  if (x->get_vac()==2){
    cout<<unvaccinated+1<<". "<< x->get_petname()<<", "<<x->get_species()<<". Owner: "<<x->get_name()<<endl;
    unvaccinated++;
    x=x->get_next();
  }
  }
  cout<<"Number of vaccinated pets: "<<vaccinated<<endl;
  cout<<"Number of unvaccinated pets: "<<unvaccinated<<endl;
}

void LL::average(){
  NodePtr x=hol;
  int i;
  int c=0,p=0;
  for(i=0;i<size;i++,x=x->get_next()){
    c += x->get_age();
    //x=x->get_next();
  }
  x=hol;
  for(i=0;i<size;i++,x=x->get_next()){
    p += x->get_petage();
    //x=x->get_next();
  }
  average_age = c/size;
  average_petage = p/size;
  cout<<"Average customers age is "<<c<<" years old."<<endl;
  cout<<"Average pets age is "<<p<<" years old."<<endl;
}

int LL::get_total_profit(){
  NodePtr x=hol;
  int i;
  for (i=0;i<size;i++){
    total_profit += x->get_profit();
    x=x->get_next();
  }
  return total_profit;
}

void LL::printCustomerNames() const {
    NodePtr current = hol;

    cout << "Customer Names:" << endl;
    while (current) {
        cout << current->get_name() << endl;
        current = current->get_next();
    }
}


string LL::mostPopularFood(){
int i;
  NodePtr x=hol;
  int q = 0, w = 0, e = 0, r = 0;
  for (i = 0; i < size; i++) { // this code will check the most popular dog's food
    if (x->get_food() == 1)
      q++;
    if (x->get_food() == 2)
      w++;
    if (x->get_food() == 3)
      e++;
    if (x->get_food() == 4)
      r++;
    if(x->get_next()) x=x->get_next();
  }
  int max = q;
  if (max < w)
    max = w;
  if (max < e)
    max = e;
  if (max < r)
    max = r;
  string dogfood;
  if (max == q)
    dogfood = "Purina Pro Plan";
  if (max == w)
    dogfood = "Pedigree";
  if (max == e)
    dogfood = "Royal chain";
  if (max == r)
    dogfood = "Bil-Jac";
  return dogfood;
}

void LL::sorted() {
    int order_age[size];
    string name[size];
    NodePtr x = hol;

    for (int i = 0; i < size; i++) {
        order_age[i] = x->get_age();
        name[i] = x->get_name();
        if (x->get_next()) x = x->get_next();
    }

    // Sorting using selection sort
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (order_age[j] < order_age[min_index]) {
                min_index = j;
            }
        }

        // Swap the ages
        int temp = order_age[i];
        order_age[i] = order_age[min_index];
        order_age[min_index] = temp;

        // Swap the names
        string temp_name = name[i];
        name[i] = name[min_index];
        name[min_index] = temp_name;
    }

    // Print the sorted list of customers
    cout << "List of customers from oldest to youngest:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Name: " << name[i] << ", Age: " << order_age[i] << endl;
    }
}








/*
void LL::insert(NodePtr x, int y){
  NodePtr newPtr;      // pointer to new node
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list

  newPtr = x; // create node & put value in

  if (newPtr != NULL) { // is space available

    previousPtr = NULL;
    currentPtr = hol2;
    // loop to find the correct location in the list
    while (currentPtr != NULL && y > currentPtr->get_profit()) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
      
      } // end while

    // insert new node at beginning of list
      if(previousPtr==NULL){
        newPtr->set_next(hol);
      if (hol) 
        hol->set_prev(newPtr);
        hol = newPtr;
       
      }  // end if
    else { 
      // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      newPtr->set_prev(previousPtr);
      
      newPtr->set_next(currentPtr);
      if(currentPtr)
      currentPtr->set_prev(newPtr);
    } // end else
    ++size;
  } // end if
  else {
    cout << value << " not inserted. No memory available." << endl;
  } // end else
} // end function insert
}*/