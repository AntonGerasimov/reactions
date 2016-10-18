#include <string>
#include <vector>
using namespace std;

class particle{
public:
	particle();
	~particle();
	int charge;
	void setCharge(string newCharge);

};
class barion : public particle{

}
class p : public barion{
	charge = 1;
}

	
