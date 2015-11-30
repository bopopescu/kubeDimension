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

#ifndef HYPERTABLE_LOAD_DATA_SOURCE_FILE_DFS_H
#define HYPERTABLE_LOAD_DATA_SOURCE_FILE_DFS_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <boost/iostreams/filtering_stream.hpp>

#include "Common/ByteString.h"
#include "Common/DynamicBuffer.h"
#include "Common/String.h"

#include "DataSource.h"
#include "FixedRandomStringGenerator.h"
#include "LoadDataSource.h"
#include "FsBroker/Lib/FileDevice.h"
#include "FsBroker/Lib/Client.h"

namespace Hypertable {

  class LoadDataSourceFileDfs: public LoadDataSource {

  public:
    LoadDataSourceFileDfs(FsBroker::Lib::ClientPtr &client, const std::string &fname,
                          const std::string &header_fname,
                          int row_uniquify_chars = 0, int load_flags = 0);

    ~LoadDataSourceFileDfs() { delete m_source;};

    uint64_t incr_consumed();

  protected:
    void init_src();
    FsBroker::Lib::FileSource *m_source;
    std::string m_fname;
    std::string m_header_fname;
    unsigned long m_cur_offset;
  };

} // namespace Hypertable

#endif // HYPERTABLE_LOADDATASOURCEFILELOCAL_H
