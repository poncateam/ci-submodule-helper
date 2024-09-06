#include "testlib.h"

int main(int argc, char** argv)
{
    using namespace Ponca;

    using Scalar     = typename PointType::Scalar;
    using WeightFunc = DistWeightFunc<Point, SmoothWeightKernel<Scalar> >;
    using Plane      = Basket<Point, WeightFunc, CovariancePlaneFit> ;

    Plane p;
    p.setWeightFunc(WeightFunc(2.));

    return EXIT_SUCCESS;
}
