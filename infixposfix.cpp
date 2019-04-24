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
 char Top(){
		return tumpuk.q[tumpuk.top];
	}
	bool kosong(){
		if(tumpuk.top <= -1)
			return 1;
		else
			return 0;	
	}
	bool isOperand(char pus){
	int c = (int)pus;
	if(c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 97 && c <= 122)
		return true;
	else
		return false;
	}
	bool isOperator(char pus){
	int c = (int)pus;
	if(c == 94 || c >= 42 && c <= 43 || c == 45 || c == 47)
		return true;
	else
		return false;
	}
	int getlevel(char pus){
	if(pus == '^')
		return 3;
	else if(pus == '*' || pus == '/')
		return 2;
	else if(pus == '+' || pus == '-')
		return 1;
	else if(pus == '(' || pus == ')')
		return 0;
	else
		return -1;
	}
	bool precedence(char pus1, char pus2){
	int c1 = getlevel(pus1);
	int c2 = getlevel(pus2);

	if(c1 <= c2)
		return true;
	else
		return false;
	}
	void push(char puh){
		tumpuk.Q[tumpuk.top] = puh;
		tumpuk.top++;
	}
void pop(){
		tumpuk.top--;
	}
	
	string kondisi(string pus){
		init();
		int i=0;
		string P = "";
		while(pus[i] != '\0'){
			if(isOperand(pus[i])){
				P += pus[i];
			} else if(pus[i] == '(' ){
				push(pus[i]);
			} else if(pus[i] == ')' ){
				while(!kosong() && Top() == '(' ){
					P = P + " " + Top();
					pop();
				}
				pop();
			} else if (isOperator(pus[i])){
				if(kosong() || Top() == '('){
					push(pus[i]);
				}	
			} else {
				while(!kosong() && Top() != '(' && precedence(pus[i], Top()) ){
					P = P + " " + Top();
					pop();
				}
				push(pus[i]);
				}
				if(isOperator(pus[i]))
					P += " ";
					i++;
			}
			while(!kosong()){
			P = P + " " + Top();
			pop();
			} return P; 
		}
};
int main() {
	myStack s;
	string telor;
	cout<<"masukkan infix = ";
	cin>>telor;
	string P = s.kondisi(telor);
	cout<<endl<<"infix = "<<telor<<endl<<"Posfix = "<<P<<endl;
}
