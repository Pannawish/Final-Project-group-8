#include "node.h"
#include <string>
using namespace std;

class Queue {
  NodePtr headPtr, tailPtr;
  int size;

public:
  string get_name(){return headPtr->get_name();}
  void enqueue(NodePtr x);
  NodePtr dequeue();
  int get_size();
  void print();
  Queue();
  ~Queue(); // dequeue all
};

Queue::Queue(){
  size=0;
  headPtr=NULL;
  tailPtr=NULL;
}

Queue::~Queue(){
 int i;
 int n=size;
  for(i=0;i<n;i++)
    dequeue();
  
}
void Queue::enqueue(NodePtr x) {
  NodePtr new_node = new NODE(*x); // 1.Create
  //if (new_node){
  if (size==0){
    //2.1 CHANGE HEAD
    headPtr=new_node;
  }
 // 2 Connect
else{
  //2.2 connect tail
  tailPtr->set_next(new_node);

// 3 change tai
    tailPtr=new_node;
}
// 4. increase size
  ++size;
  
  //}
}

NodePtr Queue::dequeue() {
  //int value;
  NodePtr t;
 if(headPtr){
  // 1. Save the node to be deleted  
  t=headPtr;
    // 1.5 take the value out to value
  //value=t->get_value();
    // 2. move (head)
  //cout<<t->get_name()<<endl;
  headPtr=headPtr->get_next();
    if(size==1) tailPtr=NULL;
   size--;
    // 3. delete
   NodePtr x=new NODE(*t);
   delete t;
   return x;
  }
  //return -1;
}
int Queue::get_size(){
  return size;
}
void Queue::print(){
  cout<<headPtr->get_name()<<endl;
}