#pragma once
#include <iostream>
#include <raylib.h>
#include "space.h"
#include "handleEvent.h"

struct Simulation {

    uint16_t HEIGHT  = 720;
    uint16_t LENGTH = 1280;

    space terrain;
    Log logger;

    void init() const;
    void run();
};