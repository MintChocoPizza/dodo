#include <ios>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, long double> myMap;

int main()
{
    string str;
    string space = " ";
    long double sum = 0;
    long double gradeSum = 0;
    myMap["4.0"] = 4.0;
    myMap["3.0"] = 3.0;
    myMap["2.0"] = 2.0;
    myMap["1.0"] = 1.0;
    myMap["A+"] = 4.5;
    myMap["A0"] = 4.0;
    myMap["B+"] = 3.5;
    myMap["B0"] = 3.0;
    myMap["C+"] = 2.5;
    myMap["C0"] = 2.0;
    myMap["D+"] = 1.5;
    myMap["D0"] = 1.0;
    myMap["F"] = 0.0;

    for(int i=0; i<20; i++)
    {
        string name = "";
        string credit = "";
        string grade = "";
        
        int cur_position = 0;
        int position;

        getline(cin, str);

        while((position = str.find(space, cur_position)) != std::string::npos)
        {
            int len = position - cur_position;
            if(name.empty())
                name = str.substr(cur_position, len);
            else
                credit = str.substr(cur_position, len);
            cur_position = position+1;
        }
        grade = str.substr(cur_position);

        if(grade != "P")
        {
            gradeSum += myMap[credit];
            sum += myMap[credit]*myMap[grade];
        }
    }
    
    cout<< fixed;
    cout.precision(6);
    cout << sum/gradeSum;

    return 0;
}


// 나는 병신이다.... 나는 왜 cin이 안됬을까???
// 다음부터 안돼는 코드를 다 저장해야함.......
