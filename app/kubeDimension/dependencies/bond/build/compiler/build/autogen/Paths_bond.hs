module Paths_bond (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch

version :: Version
version = Version [0,3,0,5] []
bindir, libdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/src/app/find-object/dependencies/bond/compiler/.cabal-sandbox/bin"
libdir     = "/src/app/find-object/dependencies/bond/compiler/.cabal-sandbox/lib/x86_64-linux-ghc-7.6.3/bond-0.3.0.5"
datadir    = "/src/app/find-object/dependencies/bond/compiler/.cabal-sandbox/share/x86_64-linux-ghc-7.6.3/bond-0.3.0.5"
libexecdir = "/src/app/find-object/dependencies/bond/compiler/.cabal-sandbox/libexec"
sysconfdir = "/src/app/find-object/dependencies/bond/compiler/.cabal-sandbox/etc"

getBinDir, getLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "bond_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "bond_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "bond_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "bond_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "bond_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
