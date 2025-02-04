/*
 * Copyright 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef SDF_SPHERE_HH_
#define SDF_SPHERE_HH_

#include <gz/math/Sphere.hh>

#include <sdf/Error.hh>
#include <sdf/Element.hh>
#include <sdf/sdf_config.h>

namespace sdf
{
  // Inline bracket to help doxygen filtering.
  inline namespace SDF_VERSION_NAMESPACE {
  //

  // Forward declare private data class.
  class SpherePrivate;

  /// \brief Sphere represents a sphere shape, and is usually accessed through a
  /// Geometry.
  class SDFORMAT_VISIBLE Sphere
  {
    /// \brief Constructor
    public: Sphere();

    /// \brief Copy constructor
    /// \param[in] _sphere Sphere to copy.
    public: Sphere(const Sphere &_sphere);

    /// \brief Move constructor
    /// \param[in] _sphere Sphere to move.
    public: Sphere(Sphere &&_sphere) noexcept;

    /// \brief Destructor
    public: virtual ~Sphere();

    /// \brief Assignment operator.
    /// \param[in] _sphere The sphere to set values from.
    /// \return *this
    public: Sphere &operator=(const Sphere &_sphere);

    /// \brief Move assignment operator.
    /// \param[in] _sphere Sphere to move.
    /// \return Reference to this.
    public: Sphere &operator=(Sphere &&_sphere);

    /// \brief Load the sphere geometry based on a element pointer.
    /// This is *not* the usual entry point. Typical usage of the SDF DOM is
    /// through the Root object.
    /// \param[in] _sdf The SDF Element pointer
    /// \return Errors, which is a vector of Error objects. Each Error includes
    /// an error code and message. An empty vector indicates no error.
    public: Errors Load(ElementPtr _sdf);

    /// \brief Get the sphere's radius in meters.
    /// \return The radius of the sphere in meters.
    public: double Radius() const;

    /// \brief Set the sphere's radius in meters.
    /// \param[in] _radius The radius of the sphere in meters.
    public: void SetRadius(const double _radius);

    /// \brief Get the Gazebo Math representation of this Sphere.
    /// \return A const reference to a gz::math::Sphered object.
    public: const gz::math::Sphered &Shape() const;

    /// \brief Get a mutable Gazebo Math representation of this Sphere.
    /// \return A reference to a gz::math::Sphered object.
    public: gz::math::Sphered &Shape();

    /// \brief Get a pointer to the SDF element that was used during
    /// load.
    /// \return SDF element pointer. The value will be nullptr if Load has
    /// not been called.
    public: sdf::ElementPtr Element() const;

    /// \brief Private data pointer.
    private: SpherePrivate *dataPtr;
  };
  }
}
#endif
