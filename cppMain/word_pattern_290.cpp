#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

class word_pattern_290
{
public:
    word_pattern_290(){

    }

public:
    vector<string> splitBySpace(string s) {
        vector<string> result;

        std::istringstream iss(s);

        do
        {
            std::string sub;
            iss >> sub;
            if(sub != "")
                result.push_back(sub);
        } while (iss);
        return result;
    }

    bool wordPattern(string pattern, string str) {
        std::unordered_map<char, std::string> map;
        std::hash<std::string> h;
        vector<string> s = splitBySpace(str);
        cout<<s.size()<<endl;
        if(s.size() != pattern.size()) return false;

        for(int i=0;i<pattern.size();i++) {
            char c = pattern[i];
            if(map.count(c) ) {

                if(map[c] != s[i])
                return false;
            }
            else {
                map[c] = s[i];

            }
        }

        return true;

    }

    void main() {
        cout<<wordPattern("abba","dog dog dog dog")<<endl;
    }

};
