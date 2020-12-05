#pragma once

#include "tidysq/Sq.h"

namespace tidysq {
    inline Alphabet import_alphabet_from_R(const Rcpp::StringVector &letters,
                                           const Letter &NA_letter,
                                           const bool &ignore_case = false) {
        return Alphabet(util::convert_string_vector(letters),
                        util::sq_type_for_sq_type_abbr(letters.attr("type")),
                        NA_letter,
                        ignore_case);
    }

    inline Sq<RCPP_IT> import_from_R(const Rcpp::List &sq,
                                     const Letter &NA_letter) {
        if (!sq.hasAttribute("alphabet")) throw std::invalid_argument("Sq object should have 'alphabet' attribute.");
        Rcpp::StringVector alphabet = sq.attr("alphabet");
        return Sq<RCPP_IT>(sq, import_alphabet_from_R(alphabet, NA_letter));
    }

    template<typename PROTO>
    ProtoSq<RCPP_IT, PROTO> import_proto_from_R(const typename ProtoSq<RCPP_IT, PROTO>::ContentStorageType &proto,
                                                const Rcpp::StringVector &alphabet,
                                                const Letter &NA_letter,
                                                const bool &ignore_case) {
        return ProtoSq<RCPP_IT, PROTO>(proto,
                                       import_alphabet_from_R(alphabet, NA_letter, ignore_case));
    }
}