// =====================================================================================
//  Copyright (C) 2025 by Jiaxing Shao. All rights reserved

//  文 件 名:  random.h
//  作    者:  Jiaxing Shao, 980853650@qq.com
//  创建时间：  2025-09-19 10:20
//  描    述:
// =====================================================================================

#pragma once

#include <random>

namespace tyts {

class Random
{
public:
    Random();
    explicit Random(uint64_t seed);
    ~Random();

public:
    uint64_t random(uint64_t min, uint64_t max);

private:
    std::default_random_engine engine_;
};

} // namespace tyts