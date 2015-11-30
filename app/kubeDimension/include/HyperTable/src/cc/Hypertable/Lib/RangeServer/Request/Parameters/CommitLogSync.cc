/*
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
/// Definitions for CommitLogSync request parameters.
/// This file contains definitions for CommitLogSync, a class for encoding and
/// decoding paramters to the <i>commit log sync</i> %RangeServer function.

#include <Common/Compat.h>

#include "CommitLogSync.h"

#include <Common/Logger.h>
#include <Common/Serialization.h>

using namespace Hypertable;
using namespace Hypertable::Lib::RangeServer::Request::Parameters;

uint8_t CommitLogSync::encoding_version() const {
  return 1;
}

size_t CommitLogSync::encoded_length_internal() const {
  return 8 + m_table.encoded_length();
}

/// @details
/// Encoding is as follows:
/// <table>
/// <tr>
/// <th>Encoding</th>
/// <th>Description</th>
/// </tr>
/// <tr>
/// <td>i64</td>
/// <td>Cluster ID</td>
/// </tr>
/// <tr>
/// <td>TableIdentifier</td>
/// <td>%Table identifier</td>
/// </tr>
/// </table>
void CommitLogSync::encode_internal(uint8_t **bufp) const {
  Serialization::encode_i64(bufp, m_cluster_id);
  m_table.encode(bufp);
}

void CommitLogSync::decode_internal(uint8_t version, const uint8_t **bufp,
                                    size_t *remainp) {
  m_cluster_id = Serialization::decode_i64(bufp, remainp);
  m_table.decode(bufp, remainp);
}



