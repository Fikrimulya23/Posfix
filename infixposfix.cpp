//Fikri Mulya Permana  (1857051011)
//Fadhel Riyantyo	    (1817051065)
//M Arsyi Sobirin	    (1817051066)
//Achmad Kurnia Chandra(1817051070)*/


#include <iostream>
using namespace std;

struct Element{
 string Q[1000];
 int top;
};

class myStack {
 private:
  Element tumpuk;
  Element *head = NULL;
  
 public:
   void init(){
  tumpuk.top = 0;
 }
