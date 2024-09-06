#include "testlib.h"

PointType::PointType(  const PointType::VectorType &pos,
            const VectorType& normal)
        : m_pos(pos), m_normal(normal) {}

const PointType::VectorType& PointType::pos()    const { return m_pos; }
const PointType::VectorType& PointType::normal() const { return m_normal; }

PointType::VectorType& PointType::pos()    { return m_pos; }
PointType::VectorType& PointType::normal() { return m_normal; }

