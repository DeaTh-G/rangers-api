#pragma once


#define _CONCATX(x, y) x##y
#define _CONCAT(x, y)  _CONCATX(x, y)

#define CONCAT2(x, y) _CONCAT(x, y)

#define CHAR_BIT 8

#define INSERT_PADDING(length) char CONCAT2(pad, __LINE__)[length]

#define ASSERT(condition, message) static_assert(condition, message)

#define ASSERT_OFFSETOF(type, field, offset) \
    static_assert(offsetof(type, field) == offset, "offsetof assertion failed")

#define FUNCTION_PTR(returnType, callingConvention, function, location, ...) \
    returnType (callingConvention *function)(__VA_ARGS__) = (returnType(callingConvention*)(__VA_ARGS__))(location)
