#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Framebuffer {
    size_t w, h;
    std::vector<uint32_t> buffer;
};

#endif
