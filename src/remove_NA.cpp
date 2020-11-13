#include <Rcpp.h>

#include "tidysq/exports.h"
#include "tidysq/remove_on_condition.h"

using namespace tidysq;

// [[Rcpp::export]]
Rcpp::List CPP_remove_NA(const Rcpp::List& x,
                         const bool by_letter,
                         const Rcpp::StringVector& NA_letter) {
    return export_to_R(remove_NA<RCPP>(import_from_R(x, NA_letter), by_letter));
}
