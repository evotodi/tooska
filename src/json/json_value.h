#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include "../global.h"
#include <string>

TOOSKA_BEGIN_NAMESPACE(core)
class string_renderer;
TOOSKA_END_NAMESPACE

TOOSKA_BEGIN_NAMESPACE(serialization)
class token_serializer;
class token_serializer_writer;
TOOSKA_END_NAMESPACE

TOOSKA_BEGIN_NAMESPACE(json)
class json_array;
class json_object;
class json_value
{
    int _n;
    float _f;
    bool _b;
    std::string _s;

public:
    enum class type_t{
        invalid,
        null,
        bool_t,
        int_t,
        float_t,
        string_t,
        object_t,
        array_t
    };
    json_value();
    json_value(const bool &b);
    json_value(const int &n);
    json_value(const float &f);
    json_value(const std::string &value);
    virtual ~json_value();

    type_t type() const;
    bool is_valid() const;
    static json_value null();

    int to_int() const;
    float to_float() const;
    bool to_bool() const;
    std::string to_string() const;
    const json_object &to_object();
    const json_array &to_array();

protected:
    type_t _type;

private:
    virtual void render(core::string_renderer &r) const;

    friend class json_object;
    friend class json_array;
    friend class json_document;
    friend class tooska::serialization::token_serializer;
    friend class tooska::serialization::token_serializer_writer;
};

TOOSKA_END_NAMESPACE

#endif // JSON_VALUE_H
