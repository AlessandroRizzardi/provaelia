#include "linked_listV2.h"
#include <algorithm>
#include <string>


using namespace std;
using namespace llst;

void debug(string msg){
    cout << "DEBUG: " << msg << endl;
}


LinkedList* init(){

  LinkedList* list;

  list = new LinkedList;

  return list;
    
};

bool is_empty(LinkedList* ll){

  if(ll->head == NULL){

    return true;

  }else{

    return false;

  }
}


void add(LinkedList* ll, const char * label){    
  debug(string("adding ") + label );

  Node* q = new Node;

  q->label = label;

  q->next = ll->head;
    
  ll->head = q;
  
  if(ll->size == 0 ){
    ll->tail = q;
  }

  ll->size++;

}


string to_string(LinkedList* ll) {

  string s = "LinkedList: ";

  Node* current = ll->head;

  while (current != NULL){
       
    s += current->label;
    s += " ";

    current = current->next;

  }
  return s;
}


int size(LinkedList* ll){

  int count = 0;

  Node* current = ll->head;
  
  
  while (current != NULL){
    
    count++;

    current = current->next;

  }

  return count;

} 


bool search(LinkedList* ll, const char * label){

   Node* current = ll->head;

   while(current != NULL){

     if(strcmp(label,current->label) == 0){
       return true;
     }else{
       current = current->next;
     }
   }    
    
  return false;
}



const char* pop(LinkedList* ll){
        
  debug("popping last item...");

  Node* current = ll->head;
    

  if(ll->head == NULL){
   throw std::invalid_argument( "empty list!" );
  }else if(current->next == NULL){

    ll->head = NULL;
    ll->tail = NULL;
    return current->label;
    delete current;
    ll->size--;

  } else{
    
    while(current != NULL){

      if(current->next->next == NULL){

        Node* q = current->next;

        current->next = NULL;

        return q->label;

        delete q;

        ll->size--;

        ll->tail = current;

      }

      current = current->next;
    }
  }
} 


void destroy(LinkedList* ll){  

  while(ll->head != NULL){ 
    Node* current = ll->head;
    ll->head = current->next;
    delete current;
    ll->size--;
    
  }

  ll->head = NULL;
  ll->tail = NULL;
}

              
void append(LinkedList* ll, const char* label){

  debug((string)"adding in tail " + label);

  Node* q = new Node;
  q->label = label;
  q->next = NULL;
  ll->size++;

  if(ll->head == NULL){
    ll->head = q;
    ll->tail = q;
  } 
  ll->tail->next = q;
  ll->tail = q;
  
  /* funzione senza la tail
  debug((string)"adding in tail " + label);
  Node* current = ll->head;
  Node* q = new Node;
  ll->size++;
  q->next =NULL;
  q->label = label;
  if(ll->head == NULL){
    ll->head = q;
  }else{
    while(current->next != NULL){
    current = current->next;
    }
  }
  current->next = q;
  */
}


void remove(LinkedList* ll, const char * label){

  Node* current = ll->head;
  Node* q;

  if(ll->head == NULL){
    throw invalid_argument("List is empty");
  }else if(ll->head->label == label){

     delete ll->head;
     ll->head = NULL;
     ll->tail = NULL;
     ll->size--;

  }else if(ll->head->label != label && ll->head->next == NULL){

    throw invalid_argument("label not found!");

  }else{

    while(current->next->label != label ){

      current = current->next;

      if(current->next == NULL){
        throw invalid_argument("label not found!");
      }

    }

    if(current->next->next = NULL){
      
      ll->tail = current; 
    }

    q = current->next;
    current->next = current->next->next;

    delete q;
    ll->size--;
  }

    
}



void insert(LinkedList* ll, int i, const char * e){
  
  Node* q = new Node;
  ll->size++;
  q->label = e;

  Node* current = ll->head;

  if(ll->head == NULL && i == 1){

    ll->head = q;
    ll->head->next = NULL;

  }else if( ll->size == 1 && i==1){

    q->next = ll->head;
    ll->head = q;

  }else if(i <= ll->size){

  

    for(int j = 0; j < i - 2; j++){
      current = current->next;
    }

    q->next = current->next;
    current->next = q; 
    
    if(i == ll->size){
      ll->tail = q;
    }

  }else if(i > ll->size){
    delete q;
    ll->size--;
    throw invalid_argument("index out of bounds!");
  }
}