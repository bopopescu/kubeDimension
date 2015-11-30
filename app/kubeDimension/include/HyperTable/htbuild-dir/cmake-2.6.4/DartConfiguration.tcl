# This file is configured by CMake automatically as DartConfiguration.tcl
# If you choose not to use CMake, this file may be hand configured, by
# filling in the required variables.


# Configuration directories and files
SourceDirectory: /src/app/kubeDimension/include/HyperTable/htbuild-dir/cmake-2.6.4
BuildDirectory: /src/app/kubeDimension/include/HyperTable/htbuild-dir/cmake-2.6.4

# Site is something like machine.domain, i.e. pragmatic.crd
Site: 1bed67c229f5

# Build name is osname-revision-compiler, i.e. Linux-2.4.2-2smp-c++
BuildName: Linux-g++

# Submission information
IsCDash: TRUE
DropSite: www.cdash.org
DropLocation: /CDash/submit.php?project=CMake
DropSiteUser: 
DropSitePassword: 
DropSiteMode: 
DropMethod: http
TriggerSite: http://public.kitware.com/cgi-bin/Submit-CMake-TestingResults.cgi
ScpCommand: /usr/bin/scp

# Dashboard start time
NightlyStartTime: 21:00:00 EDT

# Commands for the build/test/submit cycle
ConfigureCommand: "/src/app/kubeDimension/include/HyperTable/htbuild-dir/cmake-2.6.4/Bootstrap.cmk/cmake" "/src/app/kubeDimension/include/HyperTable/htbuild-dir/cmake-2.6.4"
MakeCommand: /usr/bin/make -i

# CVS options
# Default is "-d -P -A"
CVSCommand: CVSCOMMAND-NOTFOUND
CVSUpdateOptions: -d -A -P

# Subversion options
SVNCommand: /usr/bin/svn
SVNUpdateOptions: 

# Generic update command
UpdateCommand: 
UpdateOptions: 
UpdateType: 

# Dynamic analisys and coverage
PurifyCommand: 
ValgrindCommand: 
ValgrindCommandOptions: 
MemoryCheckCommand: MEMORYCHECK_COMMAND-NOTFOUND
MemoryCheckCommandOptions: 
MemoryCheckSuppressionFile: 
CoverageCommand: /usr/bin/gcov

# Testing options
# TimeOut is the amount of time in seconds to wait for processes
# to complete during testing.  After TimeOut seconds, the
# process will be summaily terminated.
# Currently set to 25 minutes
TimeOut: 1500
