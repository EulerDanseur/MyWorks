#include <iostream>
#include <map>
using namespace std;
int main()
{
    std::multimap<string, std::string> studentMap2 = {
    {"first", "Tom"},
    {"second", "Mali"},
    {"third", "John"}};    


    studentMap2.insert(std::pair<std::string, std::string>("first", "Bob"));  
    
    std::multimap<std::string, std::string>::iterator itor_begin = studentMap2.lower_bound("first");
    std::multimap<std::string, std::string>::iterator itor_end   = studentMap2.upper_bound("first");
    while(itor_begin != itor_end) 
    {
        cout << itor_begin->first<<" "<< itor_begin++->second << endl;
        // cout << itor_begin->first<<" "<< itor_begin->second << endl;
        // itor_begin++;
    }

    cout << endl;
    cout << endl;

    std::cout << studentMap2.count("first") <<std::endl; // 输出为2

}
