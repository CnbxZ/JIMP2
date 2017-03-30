//
// Created by karmazynowykotletschabowy on 30.03.17.
//

#include "SimpleTemplateEngine.h"
#include <iostream>

using ::std::string;
using ::std::unordered_map;
using namespace std;

namespace nets {

    View::View(string szablonek) {

        szablon = szablonek;

        int iloscnawejscie = 0, iloscnakoncu = 0;
        int iloscnawejscieV2 = 0, iloscnakoncuV2 = 0;
        int ilezmienic=0;

        size_t left = 0;
        size_t right = 0;

        string dozmiany;
        string wprowadz[100];

        dozmiany = szablonek;


            for(int j =0;j<dozmiany.size();j++){
                wprowadz[j] = dozmiany[j];
        }

        cout<<wprowadz<<endl;

        for(size_t i = 0; i < szablon.size(); i++){
            if(szablon[i] == '{') {
                iloscnawejscie++;
                left = i;
                if(iloscnawejscie > 2) {
                    iloscnawejscieV2 = iloscnawejscie;
                    iloscnawejscie = 2;
                }
            }
            else if(szablon[i] == '}'){
                iloscnakoncu++;
                if(iloscnakoncu > 2){
                    iloscnakoncuV2 = iloscnakoncu;
                    iloscnakoncu = 2;
                    right--;
                }
            }
            if(iloscnawejscie == 2 && iloscnakoncu == 2){
                if(iloscnawejscieV2 > 2 || iloscnakoncuV2 > 2){
                    iloscnawejscie = 0;
                    iloscnakoncu = 0;
                    iloscnawejscieV2 = 0;
                    iloscnakoncuV2 = 0;
                    continue;
                }
                left--;
                right = i;
                stringdowyjscia.push_back(szablon.substr
                        (left+2, right-left-3));
                toleft.push_back(left);
                toright.push_back(right);
                iloscnawejscie = 0;
                iloscnakoncu = 0;
            }
            else if(iloscnawejscie == iloscnakoncu){
                iloscnawejscie = 0;
                iloscnakoncu = 0;
            }
        }

        if(iloscnawejscie == ilezmienic) {
            if (ilezmienic == 0) {
                //stringdowyjscia.push_back(szablon.substr
                       // (left+2, right-left-3));
                toleft.push_back(left);
                toright.push_back(right);
                iloscnawejscie = 0;
                iloscnakoncu = 0;
            } else {
                left--;
                right++;
                iloscnawejscie = 0;
                iloscnakoncu = 0;
                iloscnawejscieV2 = 0;
                iloscnakoncuV2 = 0;
            }
        }
    }

    string View::Render(const unordered_map<string, string> &model) const {

        string text = szablon;

        long dodatkowe = 0;

        for(size_t i = 0; i < stringdowyjscia.size(); i++){

            auto search = model.find(stringdowyjscia[i]);

            

            if(search != model.end()){

                if(search->first == stringdowyjscia[i]) {
                    if(toleft[i] + dodatkowe >= 0){
                        text.replace(toleft[i] + dodatkowe, toright[i] - toleft[i] + 1, search->second);
                        dodatkowe+= search->second.size() - (toright[i] - toleft[i] + 1);
                    }
                }
            }
            else{
                if(toleft[i] + dodatkowe >= 0){
                    text.replace(toleft[i] + dodatkowe, toright[i] - toleft[i] + 1, "");
                    dodatkowe += 0 - (toright[i] - toleft[i] + 1);
                }
            }
        }
        return text;
    }
}
