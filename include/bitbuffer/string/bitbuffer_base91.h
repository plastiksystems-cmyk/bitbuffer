#pragma once

#include "class/bitbuffer_class.h"

static constexpr char BASE91_ALPHABET[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!#$%&()*+,./:;<=>?@[]^_`{|}~\"";

static std::string EncodeBase91(const std::string& Input) {
    std::string Output;

    unsigned int B = 0;
    unsigned int N = 0;

    for (unsigned char C : Input) {
        B |= static_cast<unsigned int>(C) << N;
        N += 8;

        if (N > 13) {
            unsigned int V = B & 8191;
            
            if (V > 88) {
                B >>= 13;
                N -= 13;
            } else {
                V = B & 16383;
                B >>= 14;
                N -= 14;
            }

            Output += BASE91_ALPHABET[V % 91];
            Output += BASE91_ALPHABET[V / 91];
        }
    }

    if (N) {
        Output += BASE91_ALPHABET[B % 91];
        if (N > 7 || B > 90) {
            Output += BASE91_ALPHABET[B / 91];
        }
    }

    return Output;
}

static int Base91Value(unsigned char C) {
    for (int i = 0; i < 91; i++) {
        if (BASE91_ALPHABET[i] == C) {
            return i;
        }
    }

    return -1;
}

static std::string DecodeBase91(const std::string& Input) {
    std::string Output;

    unsigned int B = 0;
    unsigned int N = 0;

    int V = -1;

    for (unsigned char C : Input) {
        int D = Base91Value(C);

        if (D == -1) continue;

        if (V == -1) {
            V = D;
        } else {
            V += D * 91;
            B |= static_cast<unsigned int>(V) << N;

            if ((V & 8191) > 88) {
                N += 13;
            } else {
                N += 14;
            }

            while (N >= 8) {
                Output += static_cast<char>(B & 255);

                B >>= 8;
                N -= 8;
            }

            V = -1;
        }

    }

    if (V != -1) {
        B |= static_cast<unsigned int>(V) << N;
        
        N += 7;

        while (N >= 8) {
            Output += static_cast<char>(B & 255);
            
            B >>= 8;
            N -= 8;
        }
    }

    return Output;
}

namespace bitbuffer {

std::string bitbuffer::to_base91(std::string string) {
    return EncodeBase91(string);
}

std::string bitbuffer::decode_base91(std::string string) {
    return DecodeBase91(string);
}

}