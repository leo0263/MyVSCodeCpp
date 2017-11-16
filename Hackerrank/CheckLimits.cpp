#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int imin = std::numeric_limits<int>::min(); // minimum value
    int imax = std::numeric_limits<int>::max();
    cout << "int [" << imin << "] to [" << imax << "]" << endl;

    unsigned int uimin = std::numeric_limits<unsigned int>::min(); // minimum value
    unsigned int uimax = std::numeric_limits<unsigned int>::max();
    cout << "unsigned int [" << uimin << "] to [" << uimax << "]" << endl;

    long lmin = std::numeric_limits<long>::min(); // minimum positive value
    long lmax = std::numeric_limits<long>::max();
    cout << "long [" << lmin << "] to [" << lmax << "]" << endl;

    long long llmin = std::numeric_limits<long long>::min(); // minimum positive value
    long long llmax = std::numeric_limits<long long>::max();
    cout << "long long [" << llmin << "] to [" << llmax << "]" << endl;

    unsigned long ulmin = std::numeric_limits<unsigned long>::min(); // minimum positive value
    unsigned long ulmax = std::numeric_limits<unsigned long>::max();
    cout << "unsigned long [" << ulmin << "] to [" << ulmax << "]" << endl;

    float flmin = std::numeric_limits<float>::min(); // minimum positive value
    float flmax = std::numeric_limits<float>::max();
    cout << "float [" << flmin << "] to [" << flmax << "]" << endl;

    return 0;
}