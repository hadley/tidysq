#ifndef TIDYSQ_OPERATION_H
#define TIDYSQ_OPERATION_H

#include "../../types/general.h"

namespace tidysq {
    template<typename SEQUENCE_IN,
            typename SEQUENCE_OUT,
            typename ALPHABET>
    class OperationSq {
    public:
        virtual SEQUENCE_OUT operator() (const SEQUENCE_IN &sequence, const ALPHABET &alphabet) const = 0;
    };
}

#endif //TIDYSQ_OPERATION_H
