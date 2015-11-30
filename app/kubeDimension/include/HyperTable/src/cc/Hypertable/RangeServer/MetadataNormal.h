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

#ifndef Hypertable_RangeServer_MetadataNormal_h
#define Hypertable_RangeServer_MetadataNormal_h

#include "Metadata.h"

#include <Hypertable/Lib/TableIdentifier.h>
#include <Hypertable/Lib/TableScanner.h>

#include <unordered_map>
#include <string>

namespace Hypertable {
  class MetadataNormal : public Metadata {

  public:
    MetadataNormal(const TableIdentifier *identifier, const String &end_row);
    virtual ~MetadataNormal();
    virtual void reset_files_scan();
    virtual bool get_next_files(String &ag_name, String &files, uint32_t *nextcsidp);
    virtual void write_files(const String &ag_name, const String &files, int64_t total_blocks);
    virtual void write_files(const String &ag_name, const String &files, int64_t total_blocks, uint32_t nextcsid);

  private:

    class AgMetadata {
    public:
      AgMetadata() : nextcsid(0) { }
      String files;
      uint32_t nextcsid;
    };
    typedef std::unordered_map<String, AgMetadata> AgMetadataMap;
    
    String          m_metadata_key;
    AgMetadataMap   m_ag_map;
    AgMetadataMap::iterator  m_ag_map_iter;
  };
}

#endif // Hypertable_RangeServer_MetadataNormal_h

