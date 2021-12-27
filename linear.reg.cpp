#include <iostream>
#include <string>
using namespace std;

int main(){
  string equations_t1[50] = {};
  string equations_t1x[50] = {};
  int counter = 0;
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      counter++;
      equations_t1[counter] = to_string(i);
      equations_t1x[counter] = to_string(j);
    }
  }
  for(int i=0; i<25; i++){
    cout << equations_t1[i+1] + ", ";
    cout << equations_t1x[i+1] + "\n";
  }
  return 0;
}
