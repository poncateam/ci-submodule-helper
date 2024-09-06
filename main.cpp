#include "testlib.h"

int main(int argc, char** argv)
{
    using namespace Ponca;

    using Scalar     = typename PointType::Scalar;
    using WeightFunc = DistWeightFunc<PointType, SmoothWeightKernel<Scalar> >;
    using Plane      = Basket<PointType, WeightFunc, CovariancePlaneFit> ;

    Plane p;
    p.setWeightFunc(WeightFunc(2.));

    return EXIT_SUCCESS;
}
