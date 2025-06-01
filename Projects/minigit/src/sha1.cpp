#include "sha1.hpp"
#include <cstring>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdint>

namespace {

inline uint32_t leftRotate(uint32_t value, size_t bits) {
    return (value << bits) | (value >> (32 - bits));
}

std::vector<uint8_t> toBytes(const std::string& input) {
    return std::vector<uint8_t>(input.begin(), input.end());
}

std::string toHex(uint32_t val) {
    std::ostringstream oss;
    oss << std::hex << std::setw(8) << std::setfill('0') << val;
    return oss.str();
}

} // namespace

std::string sha1(const std::string& input) {
    std::vector<uint8_t> data = toBytes(input);

    // Initial hash values
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;
    uint32_t h4 = 0xC3D2E1F0;

    // Pre-processing
    size_t original_size = data.size() * 8;
    data.push_back(0x80);
    while ((data.size() * 8 + 64) % 512 != 0) {
        data.push_back(0x00);
    }

    for (int i = 7; i >= 0; --i) {
        data.push_back((original_size >> (i * 8)) & 0xFF);
    }

    // Process chunks
    for (size_t chunk = 0; chunk < data.size(); chunk += 64) {
        uint32_t w[80];
        for (int i = 0; i < 16; ++i) {
            w[i] = (data[chunk + i * 4 + 0] << 24) |
                   (data[chunk + i * 4 + 1] << 16) |
                   (data[chunk + i * 4 + 2] << 8)  |
                   (data[chunk + i * 4 + 3]);
        }
        for (int i = 16; i < 80; ++i) {
            w[i] = leftRotate(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
        }

        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;

        for (int i = 0; i < 80; ++i) {
            uint32_t f, k;
            if (i < 20) {
                f = (b & c) | ((~b) & d);
                k = 0x5A827999;
            } else if (i < 40) {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            } else if (i < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            uint32_t temp = leftRotate(a, 5) + f + e + k + w[i];
            e = d;
            d = c;
            c = leftRotate(b, 30);
            b = a;
            a = temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
    }

    return toHex(h0) + toHex(h1) + toHex(h2) + toHex(h3) + toHex(h4);
}
