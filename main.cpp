#include <Ponca/src/Fitting/basket.h>
#include <Ponca/src/Fitting/covariancePlaneFit.h>
#include <Ponca/src/Fitting/weightFunc.h>
#include <Ponca/src/Fitting/weightKernel.h>


int main(int argc, char** argv)
{
    using namespace Ponca;

    using Scalar = double;
    const int Dim = 3;

    using Point      = PointPositionNormal<Scalar, Dim>;
    using WeightFunc = DistWeightFunc<Point, SmoothWeightKernel<Scalar> >;
    using Plane      = Basket<Point, WeightFunc, CovariancePlaneFit> ;

    Plane p;
    p.setWeightFunc(WeightFunc(2.));

    return EXIT_SUCCESS;
}
