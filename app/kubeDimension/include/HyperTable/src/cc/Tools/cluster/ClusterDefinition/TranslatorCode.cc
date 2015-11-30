/*
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

/// @file
/// Definitions for TranslatorCode.
/// This file contains type definitions for TranslatorCode, a class for
/// translating code block.

#include <Common/Compat.h>

#include "TranslatorCode.h"

#include <Common/Error.h>
#include <Common/Logger.h>

#include <boost/algorithm/string.hpp>

#include <cctype>

using namespace Hypertable;
using namespace Hypertable::ClusterDefinition;
using namespace std;

const string TranslatorCode::translate(TranslationContext &context) {
  return m_text;
}

