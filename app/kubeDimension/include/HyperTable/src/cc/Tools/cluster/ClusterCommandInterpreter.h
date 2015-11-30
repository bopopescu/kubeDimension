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

/// @file
/// Declarations for ClusterCommandInterpreter.
/// This file contains type declarations for ClusterCommandInterpreter, a class
/// for handling interactive command execution for the cluster tool.

#ifndef Tools_cluster_ClusterCommandInterpreter_h
#define Tools_cluster_ClusterCommandInterpreter_h

#include <Tools/Lib/CommandInterpreter.h>

#include <string>

namespace Hypertable {

  using namespace std;

  /// @addtogroup cluster
  /// @{

  /// Executes interactive cluster tool commands
  class ClusterCommandInterpreter : public CommandInterpreter {
  public:

    /// Constructor.
    /// @param script Absolute pathname of command script
    ClusterCommandInterpreter(const string &script);

    /// Executes a command line.
    /// This function executes the command or task contained in <code>line</code>
    /// which was read from the interactive shell.  It interprets commands or
    /// tasks in one of the formats described in the table below.
    ///
    /// <table>
    /// <tr>
    /// <th> Format </th>
    /// <th> Description </th>
    /// </tr>
    /// <tr>
    /// <td><code> command</code></td>
    /// <td> Runs <code>command</code> on all roles by invoking the
    ///      <code>with</code> function of the command script and passing in
    ///      <code>all</code> for the target roles</td>
    /// </tr>
    /// <tr>
    /// <td><code> on &lt;hostspec&gt; command</code></td>
    /// <td> Runs <code>command</code> on all the hosts
    ///      specified by <code>&lt;hostspec&gt;</code> (see HostSpecification)
    ///      by launching the ht_ssh tool</td>
    /// </tr>
    /// <tr>
    /// <td><code> with &lt;role-list&gt; command</code></td>
    /// <td> Runs <code>command</code> by invoking the <code>with</code>
    ///      function of the command script and passing in
    ///      <code>&lt;role-list&gt;</code> (comma-separated, no spaces) for the
    ///      target roles</td>
    /// </tr>
    /// <tr>
    /// <td> <code> !task</code> </td>
    /// <td> Runs <code>task</code> by invoking the <code>task</code> function
    ///      of the command script.</td>
    /// </tr>
    /// </table>
    ///
    /// @param line Command or task specification (see table)
    /// @return Command return code
    int execute_line(const string &line) override;

  private:

    /// Pathname of command script
    string m_command_script;

  };

  /// @}

}

#endif // Tools_cluster_ClusterCommandInterpreter_h
