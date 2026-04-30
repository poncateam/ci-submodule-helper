#include "testlib.h"

int main(int argc, char** argv)
{
    using namespace Ponca;

    using Scalar       = typename PointType::Scalar;
    using WeightFilter = DistWeightFilter<PointType, SmoothWeightKernel<Scalar> >;
    using Plane        = Basket<PointType, WeightFilter, CovariancePlaneFit> ;

    Plane p;
    p.setNeighborFilter(WeightFilter(PointType::VectorType::Zero(), 2.));

    return EXIT_SUCCESS;
}
