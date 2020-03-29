#pragma once

#include <array>
#include "Types.hpp"

class IPv4
{
public:
    IPv4(const std::array<byte_t, 4>& bytes) : ipBytes_(bytes)
    {
    }

    constexpr size_t size() const {
        return ipBytes_.size();
    }

    const byte_t& operator[](size_t index) const {
        return ipBytes_.at(index);
    }

    byte_t& operator[](size_t index) {
        return ipBytes_.at(index);
    }

    IPv4 changeEndianess() const {
        std::array<byte_t, 4> newBytes = ipBytes_;
        std::reverse(newBytes.begin(), newBytes.end());

        return IPv4(newBytes);
    }

    IPv4 maskWith(const IPv4& mask) const {
        std::array<byte_t, 4> newBytes;
        for (int i = 0; i < ipBytes_.size(); i++)
            newBytes[i] = ipBytes_.at(i) & mask.ipBytes_.at(i);
        return IPv4(newBytes);
    }


private:
    std::array<byte_t, 4> ipBytes_;
};
