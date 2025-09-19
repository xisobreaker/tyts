#include "tyts/bytearray.h"

namespace tyts {

ByteArray::ByteArray()
{
}

ByteArray::ByteArray(const unsigned char *buf, unsigned int len) : buf_(buf), len_(len)
{
}

ByteArray::~ByteArray()
{
    if (buf_)
        delete[] buf_;
    buf_ = nullptr;
}

std::string ByteArray::bytes2hexstr(const unsigned char *buf, unsigned int len)
{
    static const char hex_table[] = "0123456789ABCDEF";

    if (buf == nullptr)
        return "";

    std::string message;
    message.reserve(len * 3);
    for (int i = 0; i < len; i++) {
        unsigned char byte = buf[i];
        message.push_back(hex_table[(byte >> 4) & 0x0F]);
        message.push_back(hex_table[byte & 0x0F]);
        if (i + 1 != len)
            message.push_back(' ');
    }
    return std::move(message);
}

int ByteArray::hexstr2bytes(const std::string &hexstr, unsigned char *buf, unsigned int maxlen)
{
    auto hex_value = [](char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        } else if (c >= 'a' && c <= 'f') {
            return c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            return c - 'A' + 10;
        }
        return 0;
    };

    int length = 0;
    int chSize = 0;
    for (size_t i = 0; i < hexstr.length(); i++) {
        if (hexstr.at(i) == ' ')
            continue;

        if ((chSize++) % 2 == 0) {
            buf[length] += (hex_value(hexstr.at(i)) << 4);
        } else {
            buf[length++] += hex_value(hexstr.at(i));
        }
    }
    return length;
}

std::string ByteArray::bytes2hexstr()
{
    return bytes2hexstr(buf_, len_);
}

} // namespace tyts