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
auto function2(Args ... args){
    return (args - ...)
}

int main(){
    // sumowanie liczb z fun1 jako szablonu..
    cout << fun1(1,2,3,45,55,68) << endl;
    cout << fun1(1,2,10.f,15.50,7) << endl;
    cout << fun1(5.5,3.5,10.f) << endl;
    cout << fun1(1) << endl;
    cout << fun1() << endl;

    return 0;
}