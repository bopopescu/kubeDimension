/* -*- c++ -*-
 * Copyright (C) 2007-2015 Hypertable, Inc.
 *
 * This file is part of Hypertable.
 *
 * Hypertable is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or any later version.
 *
 * Hypertable is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

/// @file
/// Declarations for Status response parameters.
/// This file contains declarations for Status, a class for encoding and
/// decoding response paramters from the <i>status</i> file system broker
/// function.

#ifndef FsBroker_Lib_Response_Parameters_Status_h
#define FsBroker_Lib_Response_Parameters_Status_h

#include <Common/Serializable.h>

#include <string>

#include <Common/Status.h>

using namespace std;

namespace Hypertable {
namespace FsBroker {
namespace Lib {
namespace Response {
namespace Parameters {

  /// @addtogroup FsBrokerLibResponseParameters
  /// @{

  /// %Response parameters for <i>open</i> requests.
  class Status : public Serializable {
  public:

    /// Constructor.
    /// Empty initialization for decoding.
    Status() {}

    /// Constructor.
    /// Initializes with parameters for encoding.  Initializes #m_status with
    /// <code>status</code>.
    /// @param status Status information
    Status(const Hypertable::Status &status) : m_status(status) {}

    /// Gets status information
    /// @return Status information
    const Hypertable::Status &status() const { return m_status; }

  private:

    uint8_t encoding_version() const override;

    size_t encoded_length_internal() const override;

    void encode_internal(uint8_t **bufp) const override;

    void decode_internal(uint8_t version, const uint8_t **bufp,
			 size_t *remainp) override;

    /// Status information
    Hypertable::Status m_status;

  };

  /// @}

}}}}}

#endif // FsBroker_Lib_Response_Parameters_Status_h
