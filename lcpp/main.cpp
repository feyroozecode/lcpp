//
//  main.cpp
//  lcpp
//
//  Created by Ibrahim Ahmad on 22/2/25.
//


// importsation de la library I/O
#include <iostream>


void fFoo(int){
    
}


const int numStandards = 7;
// The C++26 stdCode is a placeholder since the exact code won't be determined until the standard is finalized
const long stdCode[numStandards] = { 199711L, 201103L, 201402L, 201703L, 202002L, 202302L, 202612L};
const char* stdName[numStandards] = { "Pre-C++11", "C++11", "C++14", "C++17", "C++20", "C++23", "C++26" };

long getCPPStandard()
{
    // Visual Studio is non-conforming in support for __cplusplus (unless you set a specific compiler flag, which you probably haven't)
    // In Visual Studio 2015 or newer we can use _MSVC_LANG instead
    // See https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/
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


// funciton main
int main() {
    // insert code here...
    std::cout << "Salam ALeykoym !\n";
    
    unsigned int t {5*2};
    fFoo(t);

    for(int i = 0; i <= t; i++){
        std::cout << i <<"\n";
    }
    
    fVersion();
    
    return 0;
}
