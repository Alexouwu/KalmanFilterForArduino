#include <Arduino.h>
#include <KALMAN_FILTER.h>
#include <BasicLinearAlgebra.h>

using namespace BLA;
Kalman kalmanazo;

void setup()
{

  Serial.begin(9600);
  // put your setup code here, to run once:
  BLA::Matrix<2, 2> F;
  F << 1, 0.5,
      0, 1;

  BLA::Matrix<2, 1> G;
  G << 0,
      0.5;

  BLA::Matrix<1, 1> u;
  u << -2;

  BLA::Matrix<2, 2> Pk_1;
  Pk_1 << 0.01, 0,
      0, 1;

  BLA::Matrix<2, 1> Xk_1;
  Xk_1 << 0,
      5;

  BLA::Matrix<2, 2> Q;
  Q << 0.1, 0,
      0, 0.1;

  delay(1000);

  Serial << "Xk: " << kalmanazo.xk_pred(F, G, Xk_1, u) << '\n';
  Serial << "Pk_predict" << kalmanazo.Pk_pred(F, Pk_1, Q) << '\n';
}

void loop()
{

}