#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class particle{
public:
	int charge;
	float spin;
	double mass;
	int barion_n;
	vector <string> syns;
	particle(){
		charge = 100;
		spin = 100;
		mass = -1;
		barion_n = 100;
	};
	void setCharge(string newCharge);

};
class adron : public particle{
public:
	adron() : particle(){};

};
class barion : public adron{
public:
	barion() : adron(){
		barion_n = 1;
		spin = 1/2;
	};		
	
};
class p : public barion{
public:
	p() : barion(){
		charge = 1;
		mass = 938.272;
		syns.push_back("proton");
	};
	bool check_syns(string word){
		for (int i=0; i<syns.size();i++){
			if(syns[i]==word){
				return 1;
			}
		} 
		return 0;
	}
	~p();
};

int main(){
	p *proton = new p();
	printf("Begin\n");
	printf("%d\n", proton->check_syns("proton"));
	printf("%d\n", proton->check_syns("protom"));
	printf("End\n");
}	
