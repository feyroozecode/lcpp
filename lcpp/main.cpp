//
//  main.cpp
//  lcpp
//
//  Created by Ibrahim Ahmad on 22/2/25.
//


// importsation de la library I/O
#include <iostream>


void fFoo(int){}


const int numStandards = 7;
// The C++26 stdCode is a placeholder since the exact code won't be determined until the standard is finalized
const long stdCode[numStandards] = { 199711L, 201103L, 201402L, 201703L, 202002L, 202302L, 202612L};
const char* stdName[numStandards] = { "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" };

long getCPPStandard()
{
#if defined (_MSVC_LANG)
    return _MSVC_LANG;
#elif defined (_MSC_VER)
    // If we're using an older version of Visual Studio, bail out
    return -1;
#else
    // __cplusplus is the intended way to query the language standard code (as defined by the language standards)
    return __cplusplus;
#endif
}

void fVersion(){
    std::cout << "version showing \n";
    
    long standard = getCPPStandard();
    
    if(standard == -1){
        std::cout<< "Error:Unable to determine cpp language standard you're using";
    }
    
    for (int i = 0; i<stdCode[i]; i++){
        // If the reported version is one of the finalized standard codes
        // then we know exactly what version the compiler is running
        if (standard == stdCode[i])
        {
            std::cout << "Your compiler is using " << stdName[i]
                << " (language standard code " << standard << "L)\n";
            break;
        }

        // If the reported version is between two finalized standard codes,
        // this must be a preview / experimental support for the next upcoming version.
        if (standard < stdCode[i])
        {
            std::cout << "Your compiler is using a preview/pre-release of " << stdName[i]
                << " (language standard code " << standard << "L)\n";
            break;
        }
    }
    
}

void print(char* str){
    std::cout << str;
}

int add(int a, int b){
    return a+b;
}


// funciton main
int main() {
    std::cout << "Salam ALeykoym !\n";
    
    [[maybe_unused]]int x (32); // direct initialization
    [[maybe_unused]]int y {64}; // list initialization
    [[maybe_unused]]int z = {0}; // copy-lit initialization (used when value is needed like to prit it on cosole immediatly after init)
    
    unsigned int t {5*2};
    
    //static_cast<void>(std::cout << "x ="), static_cast<void>(x) ,static_cast<void>("y = "),static_cast<void>(y), static_cast<void>("t ="),static_cast<void>(t);
    
    for(int i = 0; i <= t; i++){
        for (int j = 1; j <i; j++){
            std::cout << "*" << "\n" "-" << std::endl;
        }
    }
    
    fVersion();
    
    // take data
    int age_d {};
    std::cout << "Enter your age :";
    
    std::cin>> age_d;
    
    std::cout<< "Salam "<< " ahmad " << " you'r "<< age_d << "\n";
    
    
    return 0;
}
