#include <Ponca/src/Fitting/basket.h>
#include <Ponca/src/Fitting/covariancePlaneFit.h>
#include <Ponca/src/Fitting/weightFunc.h>
#include <Ponca/src/Fitting/weightKernel.h>

// Basic point
class PointType
{
public:
    enum {Dim = 3};
    typedef float Scalar;
    typedef Eigen::Matrix<Scalar, Dim,   1, Eigen::DontAlign>		VectorType;
    typedef Eigen::Matrix<Scalar, Dim+1, 1, Eigen::DontAlign>		HVectorType;
    typedef Eigen::Matrix<Scalar, Dim, Dim, Eigen::DontAlign>	MatrixType;
    typedef Eigen::Quaternion<Scalar, Eigen::DontAlign>			QuaternionType;

    PointType(  const VectorType &pos = VectorType::Zero(),
                const VectorType& normal = VectorType::Zero()
    );

    const VectorType& pos() const;
    const VectorType& normal() const;

    VectorType& pos();
    VectorType& normal();

private:
    VectorType m_pos, m_normal;
};


