#include "assertDominionTest.h"
//Input: whether it worked or not, and a MSG to  be displated if failure
//Output: Error to STDERR if assertion is false
//Output: 1 if exit is requested 0 if continue.
//You can place this into an if(asserDom(x,y)){return 1}
bool assertDom(bool assertion, string MSG){
  if(!assertion){
    fprintf(stderr,"Errormessage: %s", MSG);
    cout << "Assertion Failed:" << MSG;
    cout << "Exit? (Y/N)";
    char choice;
    cin >> choice;
    if(choice == Y || choice == y){
      return true;
    }
    return false;
}
