#include<iostream>
#include<string>
#include<map>

using namespace std;



class part {
        string name;
        float q1;
        public:
        part(string,float);
        ~part(void);
        void print(void);
};

map<string, part* > m;

part::part(string n, float q) {
        name = n;
        q1 = q;
        m[name] = this;
        return;
};

part::~part(void) {}

void part::print(void) {
        cout << "print: name: " << name << endl;
        return;
}

int main (void) {
        part* p[3] = {
                new part("P",1.),
                new part("N",0.),
                0
        };

        m["N"] ->print();

        /*
        for (int i = 0; s[i] != "" ; i++) {
                cout << i << ": s: " << s[i] << " -> " << m[s[i]] << endl;
        }
        */
        return 0;
}
