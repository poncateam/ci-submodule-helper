#include <Ponca/src/Fitting/basket.h>
#include <Ponca/src/Fitting/covariancePlaneFit.h>
#include <Ponca/src/Fitting/weightFunc.h>
#include <Ponca/src/Fitting/weightKernel.h>

// Basic point
template<typename _Scalar, int _Dim>
class PointPositionNormal
{
public:
    enum {Dim = _Dim};
    typedef _Scalar Scalar;
    typedef Eigen::Matrix<Scalar, Dim,   1, Eigen::DontAlign>		VectorType;
    typedef Eigen::Matrix<Scalar, Dim+1, 1, Eigen::DontAlign>		HVectorType;
    typedef Eigen::Matrix<Scalar, Dim, Dim, Eigen::DontAlign>	MatrixType;
    typedef Eigen::Quaternion<Scalar, Eigen::DontAlign>			QuaternionType;

    PONCA_MULTIARCH inline PointPositionNormal(  const VectorType &pos = VectorType::Zero(),
                                                 const VectorType& normal = VectorType::Zero()
    )
            : m_pos(pos), m_normal(normal) {}

    PONCA_MULTIARCH inline const VectorType& pos()    const { return m_pos; }
    PONCA_MULTIARCH inline const VectorType& normal() const { return m_normal; }

    PONCA_MULTIARCH inline VectorType& pos()    { return m_pos; }
    PONCA_MULTIARCH inline VectorType& normal() { return m_normal; }

private:
    VectorType m_pos, m_normal;
};

using PointType = PointPositionNormal<float, 3>;

