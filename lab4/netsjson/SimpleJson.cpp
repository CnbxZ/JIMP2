//
// Created by karmazynowykotletschabowy on 30.03.17.
//

#include "SimpleJson.h"
#include <string>
#include <experimental/optional>
#include <vector>
#include <iomanip>
#include <sstream>

namespace nets
{
    JsonValue::JsonValue(int v)
    {
        type = type_int;
        value = new int(v);
    }

    JsonValue::JsonValue(double v){
        type = type_double;
        value = new double(v);
    }
    JsonValue::JsonValue(std::string v){
        type = type_string;
        value = new std::string(v);
    }

    JsonValue::JsonValue(bool v) {
        type = type_bool;
        value = new bool(v);
    }

    JsonValue::JsonValue(std::vector<JsonValue> v) {
        type = type_vector;
        value = new std::vector<JsonValue>(v);
    }

    JsonValue::JsonValue(std::map<std::string, JsonValue> v) {
        type = type_map;
        value = new std::map<std::string, JsonValue>(v);
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        if (type != type_map)
            return std::experimental::optional<JsonValue>();
        auto map = (std::map<std::string, JsonValue>*) value;
        auto it = map -> find(name);
        if ( it == map -> end())
            return std::experimental::optional<JsonValue>();
        else
            return std::experimental::optional<JsonValue>( it -> second );
    }

    std::string JsonValue::ToString() const {
        switch(type) {
            case type_int: {
                return std::to_string (*((int *) value));
            }
            case type_double: {
                std::stringstream s;
                s << std::fixed << std::setprecision(2) << (*((double *) value)) ;
                return s.str();
            }
            case type_string: {
                return "\"" + (*(std::string *) value) + "\"";
            }
            case type_bool: {
                if (*((bool *) value)) return "true";
                else return "false";
            }
            case type_vector: {
                auto v = *((std::vector<JsonValue> *) value);
                std::string s;
                for (int i = 0; i < v.size (); i++) {
                    s = s + "[ " + v[i].ToString () + " ";
                }
                return s + "]";
            }
            case type_map: {
                auto map = *((std::map<std::string, JsonValue> *) value);
                std::string s;
                for (auto value: map) {
                    auto k = value.first;
                    auto v = value.second;
                    s = s + k + ":" + v.ToString();
                }
                return s;
            }
        }
    }

    JsonValue::~JsonValue() {
        switch(type)
        {
            case type_int: {
                auto v = (int *) value;
                delete v;
            }//delete v;
            case type_double: {
                auto v = (double *) value;
                delete v;
            }
            case type_string: {
                auto v = (std::string *) value;
                delete v;
            }
            case type_bool: {
                auto v = (bool *) value;
                delete v;
            }
            case type_vector: {
                auto v = (std::vector<JsonValue> *) value;
                delete v;
            }
            case type_map: {
                auto v = (std::map<std::string, JsonValue> *) value;
                delete v;
            }
        }

    }

    JsonValue::JsonValue(const JsonValue &rhs) {
        type = rhs.type;
        switch(type)
        {
            case type_int: {
                auto v = (int *) rhs.value;
                value = new int (*v);
            } break;
            case type_double: {
                auto v = (double *) rhs.value;
                value = new double (*v);
            } break;
            case type_string: {
                auto v = (std::string *) rhs.value;
                value = new std::string (*v);
            } break;
            case type_bool: {
                auto v = (bool *) rhs.value;
                value = new bool (*v);
            } break;
            case type_vector: {
                auto v = (std::vector<JsonValue> *) rhs.value;
                value = new std::vector<JsonValue> (*v);
            } break;
            case type_map: {
                auto v = (std::map<std::string, JsonValue> *) rhs.value;
                value = new std::map<std::string, JsonValue> (*v);
            } break;
        }
    }


};