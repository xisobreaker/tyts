// =====================================================================================
//  Copyright (C) 2025 by Jiaxing Shao. All rights reserved

//  文 件 名:  bytearray.h
//  作    者:  Jiaxing Shao, 980853650@qq.com
//  创建时间：  2025-09-19 13:23
//  描    述:
// =====================================================================================

#pragma once

#include <string>

namespace tyts {

class ByteArray
{
public:
    ByteArray();
    explicit ByteArray(const unsigned char *buf, unsigned int len);
    ~ByteArray();

public:
    static std::string bytes2hexstr(const unsigned char *buf, unsigned int len);
    static int         hexstr2bytes(const std::string &hexstr, unsigned char *buf, unsigned int maxlen);
    std::string        bytes2hexstr();

private:
    const unsigned char *buf_;
    unsigned int         len_;
};

} // namespace tyts