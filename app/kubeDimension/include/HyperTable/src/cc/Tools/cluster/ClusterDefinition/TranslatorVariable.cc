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
/// Definitions for TranslatorVariable.
/// This file contains type definitions for TranslatorVariable, a class for
/// translating variable definition statements.

#include <Common/Compat.h>

#include "TranslatorVariable.h"

#include <Common/Error.h>
#include <Common/Logger.h>

#include <boost/algorithm/string.hpp>

#include <cctype>

using namespace Hypertable;
using namespace Hypertable::ClusterDefinition;
using namespace std;

const string TranslatorVariable::translate(TranslationContext &context) {
  string translation_text;
  size_t offset = m_text.find_first_of('=');
  if (offset == string::npos)
    HT_THROWF(Error::SYNTAX_ERROR, "Bad variable definition on line %d of '%s'",
              (int)m_lineno, m_fname.c_str());
  string name = m_text.substr(0, offset);
  boost::trim(name);
  string raw_value = m_text.substr(offset+1);
  boost::trim(raw_value);
  string preceding_whitespace;
  bool preceding_newline=false;
  string value;
  for (const char *ptr = raw_value.c_str(); *ptr; ptr++) {
    if (isspace(*ptr)) {
      preceding_whitespace.append(1, *ptr);
      if (*ptr == '\n')
        preceding_newline = true;
    }
    else {
      if (preceding_newline)
        value.append(" ");
      else
        value.append(preceding_whitespace);
      preceding_whitespace.clear();
      preceding_newline = false;
      value.append(1, *ptr);
    }
  }

  size_t whitespace_chars = 0;
  for (const char *ptr = m_text.c_str(); *ptr && isspace(*ptr); ptr++)
    whitespace_chars++;

  translation_text.append(m_text.c_str(), whitespace_chars);
  translation_text.append(name);
  translation_text.append("=${");
  translation_text.append(name);
  translation_text.append(":-");
  translation_text.append(value);
  translation_text.append("}\n");

  if (value.length() >= 2) {
    if ((value[0] == '\'' && value[value.length()-1] == '\'') ||
        (value[0] == '"' && value[value.length()-1] == '"'))
      value = value.substr(1, value.length()-2);
  }
  context.symbols[name] = value;
  return translation_text;
}

