#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <iomanip>   //setw..
#include <list>
#include <forward_list>
#include <typeinfo>
#include <string>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <typeinfo>
#include <iterator>
#include <set>
#include <chrono>
#include <thread>
#include <future>
#include "numbers.h"

using namespace std;

// Pozwala na skrocenie kodu.. => Korzystajac z mechaniki rekurencji ( szybkiej rekurencji )..

template<typename ... Args>
auto fun1(Args ... args){
    return (args + ... + 0);
}

// lewy folding i prawy folding..
template<typename ... Args>
auto fun2(Args ... args){
    return (args - ...);
}

template<typename ... Args>
auto fun3(Args ... args){
    return (... - args);
}

template<typename ... Args>
auto fun4(Args ... args){
    cout << "rozmiar: " << sizeof...(Args) << endl;
    return(... + (args + string( " " )));
}

template<typename C, typename ... Args>
auto countInside(const C& c, Args ... args){
    return(std::count(begin(c), end(c), args) + ...);
}


int main(){
    // sumowanie liczb z fun1 jako szablonu..
    cout << fun1(1,2,3,45,55,68) << endl;
    cout << fun1(1,2,10.f,15.50,7) << endl;
    cout << fun1(5.5,3.5,10.f) << endl;
    cout << fun1(1) << endl;
    cout << fun1() << endl;

    cout << endl;

    cout << fun2(100,50,20) << endl;  // 100 - (50 - 20) = wynik
    cout << fun2(150,90,50) << endl;  // 150 - (90 - 50) = wynik

    cout << fun3(170,45,32) << endl;  // (170 - 45) - 32 = wynik
    cout << fun3(90,42,32) << endl;   // (90 - 42) - 32 = wynik

    cout << endl;
    cout << endl;

    cout << fun4("Man1exter","love","CSGO","hekasz") << endl;
    cout << fun4("Slonik","love","kragliczne","okragliczne") << endl;

    cout << endl;
    cout << endl;

    // ile w zbiorze znajduje sie liczb.... (zbior,liczby) ==> po przecinki za zbiorem,liczba1,liczb2

    vector<int> vec{1,2,5,6,7,8,1,2,3,2,3,5,6,7,8};
    cout << countInside(vec,1,2,3) << endl;
 
    return 0;
}