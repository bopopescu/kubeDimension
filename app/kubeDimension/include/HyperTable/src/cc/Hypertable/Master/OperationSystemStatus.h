/* -*- c++ -*-
 * Copyright (C) 2007-2015 Hypertable, Inc.
 *
 * This file is part of Hypertable.
 *
 * Hypertable is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3 of the
 * License, or any later version.
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

#ifndef Hypertable_Master_OperationSystemStatus_h
#define Hypertable_Master_OperationSystemStatus_h

#include "OperationEphemeral.h"

#include <Hypertable/Master/DispatchHandlerOperationSystemStatus.h>
#include <Hypertable/Master/RangeServerConnection.h>

#include <Hypertable/Lib/Master/Response/Parameters/SystemStatus.h>

namespace Hypertable {

  using namespace Lib::Master;

  class OperationSystemStatus : public OperationEphemeral {
  public:
    OperationSystemStatus(ContextPtr &context, EventPtr &event);
    virtual ~OperationSystemStatus() { }

    void execute() override;
    const String name() override;
    const String label() override;
    void display_state(std::ostream &os) override { }

    /// Length of encoded operation result.
    /// This method returns the length of the encoded result
    /// @return length of encoded result
    /// @see encode_result() for encoding format.
    size_t encoded_result_length() const override;

    /// Encode operation result.
    /// This method is called to encode the result of the status operation.
    /// @param bufp Address of pointer to destination buffer
    void encode_result(uint8_t **bufp) const override;

  private:

    std::string status_text_from_result(DispatchHandlerOperationSystemStatus::Result &result);

    Response::Parameters::SystemStatus m_params;

  };

}

#endif // Hypertable_Master_OperationSystemStatus_h
