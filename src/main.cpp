#include "linked_listV2.h"

using namespace std;
using namespace llst;

int main(int, char**){ 

    LinkedList* ll = init();

    add(ll, "a");
    add(ll, "b");
    add(ll, "c");

        
    cout << to_string(ll) << endl;

    cout << "size:" << size(ll) << endl;

    add(ll, "d");

    cout << to_string(ll) << endl;

    cout << "size:" << size(ll) << endl;


    cout << "search(ll,\"a\"): " << (search(ll, "a") ? "true" : "false") << endl;

    cout << "search(ll,\"z\"): " << (search(ll, "z")  ? "true" : "false") << endl;
    
    append( ll, "h");

    cout << to_string(ll) << endl;

    insert(ll, 3,"l");

    cout << to_string(ll) << endl;
    
    remove(ll,"l");

     cout << to_string(ll) << endl;

    cout << pop(ll) << endl;    
    
    cout << to_string(ll) << endl;

    cout << pop(ll) << endl;    

    cout << to_string(ll) << endl;

    cout << pop(ll) << endl;    
    
    cout << to_string(ll) << endl;

    cout << pop(ll) << endl;    
    
    cout << to_string(ll) << endl;

    // to test exception
    // cout << pop(ll) << endl;            

    destroy(ll);

    cout << "destroyed"  << endl;    

} 