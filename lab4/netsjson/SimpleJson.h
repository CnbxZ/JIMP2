//
// Created by karmazynowykotletschabowy on 30.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <string>
#include <vector>
#include <map>
#include <experimental/optional>

namespace nets {
    class JsonValue {
    public:
        JsonValue(double v);

        JsonValue (int v);

        JsonValue (std::string );

        JsonValue (bool);

        JsonValue (std::vector < JsonValue > );

        JsonValue (std::map < std::string, JsonValue >);

        JsonValue (const JsonValue&);

        ~JsonValue();

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

    private:
        enum Type{ type_int, type_double, type_string, type_bool, type_vector, type_map };
        Type type;
        void *value;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H