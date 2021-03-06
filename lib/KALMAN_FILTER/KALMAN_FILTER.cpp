#include "KALMAN_FILTER.h"
#include <BasicLinearAlgebra.h>
using namespace BLA;



KALMAN::KALMAN()
{
};
KALMAN::~KALMAN()
{
};

BLA::Matrix<2,1> KALMAN::xk_pred(BLA::Matrix<2,2> F, BLA::Matrix<2,1> G, BLA::Matrix<2,1> xk_1, BLA::Matrix<1,1> uk_1)
{
    return (F*xk_1+G*uk_1);
}

BLA::Matrix<2,2> KALMAN::Pk_pred(BLA::Matrix<2,2> F,BLA::Matrix<2,2> Pk_1_correc,BLA::Matrix<2,2> Qk_1)
{

    return (F*Pk_1_correc)*(~F)+Qk_1;
}

BLA::Matrix<2,1> KALMAN::Kk(BLA::Matrix<2,2> Pk_predict, BLA::Matrix<1,2> Hk, BLA::Matrix<1,1> Rk)
{
    BLA::Matrix<1,1> temp = (Hk*Pk_predict*(~Hk)+Rk);
    return (Pk_predict*(~Hk)*temp.Inverse());
}

BLA::Matrix<2,1> KALMAN::xk_correction(BLA::Matrix<2,1> xk_predict, BLA::Matrix<2,1> K1, BLA::Matrix<1,1> y, BLA::Matrix<1,2> Hk)
{
    return (xk_predict+K1*(y-Hk*xk_predict));
}

BLA::Matrix<2,2> KALMAN::Pk_correction(BLA::Matrix<2,1> K1, BLA::Matrix<1,2> Hk, BLA::Matrix<2,2> Pk_predict)
{
    BLA::Matrix<2,2> temp;
    temp << 1, 1,
            1, 1;
    return (((temp)-(K1*Hk))*Pk_predict);
}