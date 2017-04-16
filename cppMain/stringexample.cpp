#include <iostream>
using namespace std;

class StringExample
{
public:
    void main() {
        string s4(10, 'c');
        cout<<s4<<endl;

        string str("some string");
        for (auto c:str) {
            cout<<c<<endl;
        }

        for(auto &c: str) {
            c = toupper(c);
        }

        cout << str<<endl;

        if(!str.empty()) {

        }
    }
};

