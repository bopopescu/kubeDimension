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

#ifndef Tools_client_rangeserver_TableInfo_h
#define Tools_client_rangeserver_TableInfo_h

#include <Hypertable/Lib/Schema.h>
#include <Hypertable/Lib/TableIdentifier.h>

#include <Hyperspace/Session.h>

#include <Common/String.h>

namespace Tools {
namespace client {
namespace rangeserver {

  class TableInfo {
  public:
    TableInfo(const String &toplevel_dir, const String &table_id);

    void load(Hyperspace::SessionPtr &hyperspace);

    TableIdentifier *get_table_identifier() { return &m_table; }
    void get_schema_ptr(SchemaPtr &schema) { schema = m_schema; }

  private:
    TableIdentifierManaged m_table;
    SchemaPtr m_schema;
    String m_toplevel_dir;
  };
}}}

#endif // Tools_client_rangeserver_TableInfo_h
