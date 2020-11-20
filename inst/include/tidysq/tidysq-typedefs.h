#pragma once

#include <string>
#include <unordered_map>

namespace tidysq {
    typedef unsigned long long int  LenSq;
    typedef unsigned char           ElementPacked;
    typedef unsigned char           ElementRaws;
    typedef unsigned short int      ElementInts;
    typedef std::string             ElementStrings;
    typedef char                    ElementStringSimple;
    typedef std::string             ElementStringMultichar;
    typedef unsigned short int      AlphSize;
    typedef unsigned short int      LetterValue;
    typedef std::string             Letter;
    typedef char                    SimpleLetter;

    typedef std::unordered_map<LetterValue, const LetterValue>          ComplementTable;
    typedef const std::unordered_map<LetterValue,
                const std::unordered_map<LetterValue,
                    const std::unordered_map<LetterValue,
                        const LetterValue>>>                            CodonTable;

    struct InternalType {};

    struct RCPP_IT : public InternalType {};
    struct STD_IT : public InternalType {};

    struct ProtoType {};

    struct RAWS_PT : public ProtoType {};
    struct INTS_PT : public ProtoType {};
    struct STRINGS_PT : public ProtoType {};
    struct STRING_PT : public ProtoType {};

    enum SqType {
        AMI_EXT,
        AMI_BSC,
        DNA_EXT,
        DNA_BSC,
        RNA_EXT,
        RNA_BSC,
        UNT,
        ATP,
        ENC
    };
}
