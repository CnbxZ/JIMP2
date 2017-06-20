//
// Created by karmazynowykotletschabowy on 30.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <vector>

namespace nets{

    class View{

    public:
        View(std::string templ);

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

    private:
        std::string szablon;

        std::vector<size_t> toleft;

        std::vector<size_t> toright;

        std::vector<std::string> stringdowyjscia;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H