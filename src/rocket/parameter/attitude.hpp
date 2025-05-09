// ******************************************************
// Project Name    : ForRocket
// File Name       : attitude.hpp
// Creation Date   : 2019/12/04
//
// Copyright (c) 2019 Susumu Tanaka. All rights reserved.
// Copyright (c) 2025 Yo Tobetto. All rights reserved.
// ******************************************************

#ifndef ATTITUDE_HPP_
#define ATTITUDE_HPP_

#define EIGEN_MPL2_ONLY
#include "Eigen/Core"

#include "environment/coordinate.hpp"

namespace forrocket {
    class Attitude {
        public:
            Eigen::Vector3d euler_angle;
            // double& azimuth = euler_angle(0);
            // double& elevation = euler_angle(1);
            // double& roll = euler_angle(2);
            Eigen::Vector4d quaternion;

            Attitude();

            void Initialize(const Eigen::Vector3d& euler_angle);
            void Update(const Eigen::Vector4d& quaternion, Coordinate& coordinate);
            
        private:

    };
}

#endif
