# PYTHIA configuration file.
# Generated on Tuesday 30 January 2024 03:24:38 PM IST with the user supplied options:
# --with-root=/home/hep/cernroot/

# Install directory prefixes.
PREFIX_BIN=/home/hep/pythia8310/bin
PREFIX_INCLUDE=/home/hep/pythia8310/include
PREFIX_LIB=/home/hep/pythia8310/lib
PREFIX_SHARE=/home/hep/pythia8310/share/Pythia8

# Compilation flags (see ./configure --help for further documentation).
CXX=g++
CXX_COMMON=-O2 -std=c++11 -pedantic -W -Wall -Wshadow -fPIC -pthread
CXX_SHARED=-shared
CXX_SONAME=-Wl,-soname,
LIB_SUFFIX=.so
OBJ_COMMON=

EVTGEN_USE=false
EVTGEN_CONFIG=
EVTGEN_BIN=
EVTGEN_INCLUDE=
EVTGEN_LIB=

FASTJET3_USE=true
FASTJET3_CONFIG=fastjet-config
FASTJET3_BIN=/home/hep/fastjet/fastjet_install/bin/
FASTJET3_INCLUDE=-I/home/hep/fastjet/fastjet_install/include
FASTJET3_LIB=-L/home/hep/fastjet/fastjet_install/lib -Wl,-rpath,/home/hep/fastjet/fastjet_install/lib -lfastjet

HEPMC2_USE=false
HEPMC2_CONFIG=
HEPMC2_BIN=
HEPMC2_INCLUDE=
HEPMC2_LIB=

HEPMC3_USE=false
HEPMC3_CONFIG=
HEPMC3_BIN=
HEPMC3_INCLUDE=
HEPMC3_LIB=

LHAPDF5_USE=false
LHAPDF5_CONFIG=
LHAPDF5_BIN=
LHAPDF5_INCLUDE=
LHAPDF5_LIB=

LHAPDF6_USE=true
LHAPDF6_CONFIG=lhapdf-config
LHAPDF6_BIN=/home/hep/lhapdf/lhapdf_install/bin/
LHAPDF6_INCLUDE=-I/home/hep/lhapdf/lhapdf_install/include
LHAPDF6_LIB=-L/home/hep/lhapdf/lhapdf_install/lib -Wl,-rpath,/home/hep/lhapdf/lhapdf_install/lib -lLHAPDF

POWHEG_USE=false
POWHEG_CONFIG=
POWHEG_BIN=
POWHEG_INCLUDE=
POWHEG_LIB=

RIVET_USE=false
RIVET_CONFIG=
RIVET_BIN=
RIVET_INCLUDE=
RIVET_LIB=

ROOT_USE=true
ROOT_CONFIG=root-config
ROOT_BIN=/home/hep/cernroot/bin/
ROOT_INCLUDE=-I/home/hep/cernroot/include
ROOT_LIB=-L/home/hep/cernroot/lib -Wl,-rpath,/home/hep/cernroot/lib -lCore

GZIP_USE=false
GZIP_CONFIG=
GZIP_BIN=
GZIP_INCLUDE=
GZIP_LIB=

PYTHON_USE=true
PYTHON_CONFIG=python-config
PYTHON_BIN=/usr/include/python3.10/
PYTHON_INCLUDE=-I/usr/include/python3.10
PYTHON_LIB=-L/usr/include/python3.10 -Wl,-rpath,/usr/include/python3.10

MG5MES_USE=false
MG5MES_CONFIG=
MG5MES_BIN=
MG5MES_INCLUDE=
MG5MES_LIB=

OPENMP_USE=false
OPENMP_CONFIG=
OPENMP_BIN=
OPENMP_INCLUDE=
OPENMP_LIB=

MPICH_USE=false
MPICH_CONFIG=
MPICH_BIN=
MPICH_INCLUDE=
MPICH_LIB=

HDF5_USE=false
HDF5_CONFIG=
HDF5_BIN=
HDF5_INCLUDE=
HDF5_LIB=

HIGHFIVE_USE=false
HIGHFIVE_CONFIG=
HIGHFIVE_BIN=
HIGHFIVE_INCLUDE=
HIGHFIVE_LIB=
