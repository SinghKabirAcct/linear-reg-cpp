#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class holder{

  public:

    int vals[25] = {};

    void executeEquation(int t1[], int t1x[], int extent){

      for(int i = 0; i<extent; i++){
        for(int j = 0; j<5; j++){
          int tempval = 0;
          tempval = t1[i] + t1x[i]*j;
          vals[(i*5)+j] = tempval;
        }
      }

    }

};

int main(){

  int equations_t1[50] = {};
  int equations_t1x[50] = {};
  int counter = 0;

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      equations_t1[counter] = i;
      equations_t1x[counter] = j;
			counter++;
    }
  }

  for(int i=0; i<25; i++){
    cout << to_string(equations_t1[i]) + ", ";
    cout << to_string(equations_t1x[i]) + "\n";
  }

	holder holder;
	holder.executeEquation(equations_t1, equations_t1x, 25);
	
	for(int i=0; i<125; i++){
    cout << "value " << i % 5 << holder.vals[i] << endl;
  }

  return 0;

}
