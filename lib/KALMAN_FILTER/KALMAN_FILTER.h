#ifndef _KALMAN_FILTER_h
#define _KALMAN_FILTER_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "arduino.h"
#else
    #include "WProgram.h"
#endif

#include <BasicLinearAlgebra.h>
using namespace BLA;

class KALMAN{

    public:
    KALMAN();
    ~KALMAN();

    BLA::Matrix<2,1> xk_pred(BLA::Matrix<2,2> F, BLA::Matrix<2,1> G, BLA::Matrix<2,1> xk_1, BLA::Matrix<1,1> uk_1);
    BLA::Matrix<2,2> Pk_pred(BLA::Matrix<2,2> F,BLA::Matrix<2,2> Pk_1_correc,BLA::Matrix<2,2> Qk_1);
    BLA::Matrix<2,1> Kk(BLA::Matrix<2,2> Pk_predict, BLA::Matrix<1,2> Hk, BLA::Matrix<1,1> Rk);
    BLA::Matrix<2,1> xk_correction(BLA::Matrix<2,1> xk_predict, BLA::Matrix<2,1> K1, BLA::Matrix<1,1> y, BLA::Matrix<1,2> Hk);
    private:

};

#endif