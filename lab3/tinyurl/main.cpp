//
// Created by karmazynowykotletschabowy on 22.03.17.
//

#include <iostream>
#include "TinyUrl.h"

using namespace std;
using namespace tinyurl;

int main(){

    auto codec = Init();

    auto full = Encode("http://ai.ia.agh.edu.pl/wiki/pl:dydaktyka:jimp2:2017:labs:pamiec2",&codec);
    cout<<"Result 1:"<<full<<endl;

    auto shortt = Decode(codec,full);
    cout<<"Result 2:"<<shortt<<endl;

}

