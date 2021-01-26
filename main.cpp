/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define M 1000001
using namespace std;
unordered_map<string,int> solution(unordered_map<string,int>D){
    // Using Tomohiko Sakamoto’s Algorithm for finding days of the week.
    vector<int>dayName(8,M);
    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    for(auto m: D){
        string date = m.first;
        //Dividing date string into day month and year.
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        if (month < 3) year -= 1;
        //Tomohiko Sakamoto Formula
        int w = ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7);
        if(w==0) w=7;
        //if w==1 then monday, if w==2 then tuesday and so on.
        if(dayName[w]==M){
            dayName[w]=m.second;
        }
        else{
            dayName[w]=dayName[w]+m.second;
        }
    }
    //This is for the case when week days are missing. In such cases, value of that day will be mean of prev and next day.
    for(int i=1;i<8;i++){
        if(dayName[i]==M){
            int n1 = dayName[i-1];
            int j=i+1;
            while(dayName[j]==M) j++;
            int n2 = dayName[j];
            dayName[i] = (n1+n2)/2;
        }
    }
    //Building final Output Dictionary.
    unordered_map<string,int>weekDays;
    weekDays["Mon"] = dayName[1];
    weekDays["Tues"] = dayName[2];
    weekDays["Wed"] = dayName[3];
    weekDays["Thur"] = dayName[4];
    weekDays["Fri"] = dayName[5];
    weekDays["Sat"] = dayName[6];
    weekDays["Sun"] = dayName[7];
    return weekDays;
}

int main()
{
    
    unordered_map<string,int>D;
    D["2020-01-01"] = 6;
    D["2020-01-02"] = 4;
    D["2020-01-03"] = 6;
    D["2020-01-04"] = 12;
    D["2020-01-05"] = 14;
    D["2020-01-06"] = 2;
    D["2020-01-07"] = 4;
    D["2020-01-08"] = -2;
    //Printing Solution
    for(auto p: solution(D)){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    return 0;
}
