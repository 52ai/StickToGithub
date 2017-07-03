#include <iostream>
using namespace std;
#define NDEBUG
int main(){
    #ifndef NDEBUG
    cerr << "staring main" <<endl;
    cerr << "Error: " << __FILE__<< ":line " << __LINE__ <<endl
         << "       Compiled on " << __DATE__ << " at " << __TIME__ <<endl;
    #endif // NDEBUG
    return 0;
}
