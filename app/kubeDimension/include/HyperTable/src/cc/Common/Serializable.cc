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
/// Definitions for Serializable.
/// This file contains definitions for Serializable, a mixin class that
/// provides a serialization interface.

#include <Common/Compat.h>

#include "Serializable.h"

#include <Common/Error.h>
#include <Common/Logger.h>
#include <Common/Serialization.h>

using namespace Hypertable;

size_t Serializable::encoded_length() const {
  size_t length = encoded_length_internal();
  return 1 + Serialization::encoded_length_vi32(length) + length;
}

/**
 * @details
 * Encoding is as follows:
 * <table>
 * <tr>
 * <th>Encoding</th>
 * <th>Description</th>
 * </tr>
 * <tr>
 * <td>1 byte</td>
 * <td>Encoding version as returned by encoding_version()</td>
 * </tr>
 * <tr>
 * <td>vint</td>
 * <td>Length of encoded object as returned by encoded_length_internal()</td>
 * </tr>
 * <tr>
 * <td>variable</td>
 * <td>Object encoded with encode_internal()</td>
 * </tr>
 * </table>
 */
void Serializable::encode(uint8_t **bufp) const {
  Serialization::encode_i8(bufp, encoding_version());
  Serialization::encode_vi32(bufp, encoded_length_internal());
  encode_internal(bufp);
}

void Serializable::decode(const uint8_t **bufp, size_t *remainp) {
  uint8_t version = Serialization::decode_i8(bufp, remainp);
  if (version > encoding_version())
    HT_THROWF(Error::PROTOCOL_ERROR, "Unsupported version %d", (int)version);
  size_t encoding_length = Serialization::decode_vi32(bufp, remainp);
  const uint8_t *end = *bufp + encoding_length;
  size_t tmp_remain = encoding_length;
  decode_internal(version, bufp, &tmp_remain);
  HT_ASSERT(*bufp <= end);
  *remainp -= encoding_length;
  // If encoding is longer than we expect, that means we're decoding a newer
  // version, so skip the newer portion that we don't know about
  if (*bufp < end)
    *bufp = end;
}
