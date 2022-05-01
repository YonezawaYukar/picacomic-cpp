#include <iostream>
#include <string>
#include "GenerateSignature.h"


using namespace std;

int main() {
    GenerateSignature Gen;
    cout<<Gen.set("uuid","0f7948f94d9046cbbe855bcb7d2c4644")
            ->set("time","1651418333")
            ->set("url","auth/sign-in")
            ->signature();
    return 0;
}
