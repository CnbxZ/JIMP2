//
// Created by karmazynowykotletschabowy on 22.03.17.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>

using namespace std;

namespace tinyurl {

    unique_ptr<TinyUrlCodec> Init(){

        //int i =0;
        TinyUrlCodec LinkToCut;

        for (int i=0; i<6; ++i){ //Skrocenie do 6
            LinkToCut.hash[i] = 48; //48 = 0
        }

        auto toChange = make_unique<TinyUrlCodec>(LinkToCut);
        return toChange;
    }

    void NextHash(array<char, 6> *state){

        string distionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        array<char,6> toAdd = *state; int i = 5; // 6 do skrocenia do 6 linku

        int64_t url;
        int64_t parser;

        while(url > 0){
            parser = distionary[url % 62] + parser;
            url /= 62;
        }
        bool nexthash = true;

        while(nexthash){

            //1 - dla Wielkich Alfabetu 2 - dla malych alfabetu 3 - dla cyfr

            if((toAdd[i]>=65 && toAdd[i]<90) ||
                    (toAdd[i]>=97 && toAdd[i]<122) ||(toAdd[i]>=48 && toAdd[i]<57) ){

                toAdd[i] = toAdd[i] + 1;
                //Pseudo warunek stopu
                nexthash = false;

            }
            else if(toAdd[i] == 90){

                toAdd[i] = toAdd[i] + 7;
                //Pseudo warunek stopu
                nexthash = false;

            }
            else if(toAdd[i] == 122){

                toAdd[i] = 48;  i--;

            }
            else if(toAdd[i] == 57){

                toAdd[i] = toAdd[i] + 8;
                //Pseudo warunek stopu
                nexthash = false;

            }
        }
        *state = toAdd;
    }

    string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec){

        //int i =0;
        string result = "";

        string parser = "";


        (*codec)->prefiks.push_back(url);
        array<char,5> prefiks;

        for(int i = 0; i<6;++i){

            parser = parser + prefiks[i];

        }

        //skrocenie do 6
        array<char,6> hashV2 = (*codec)->hash;

        NextHash(&(*codec)->hash);

        for(int i=0;i<6;i++){

            result = result + hashV2[i];}

        return result;
    }

    string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash){

        string distionary = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int64_t url;
        int64_t parser;

        while(url > 0){
            parser = distionary[url % 62] + parser;
            url /= 62;
        }
        int64_t counterV2 = 0;

        int counter = 0, link[6];
        //int i =0;

        for(int i=0;i<6;i++){

            if(hash[i]>=48 && hash[i]<=57)
                link[i] = hash[i]-48;
            else if(hash[i]>=65 && hash[i]<=90)
                link[i] = hash[i] - 55;
            else
                link[i] = hash[i]-61;
        }
        counter = link[5] + link[4]*62 +
                link[3]*62*62 + link[2]*62*62*62 +
                link[1]*62*62*62*62 + link[0]*62*62*62*62*62;

        counterV2 = link[5] + link[4]*48+1 +
                    link[3]*62*62 + link[2]*62*62*62 +
                    link[1]*62*62*62*62 +
                    link[0]*62*62*62*57*57;

        //return counterV2;
        return codec->prefiks[counter];
    }
}
