# hpxflow
HpxFlow is a unified Batch and Stream Processing framework, over [HPX](https://github.com/STEllAR-GROUP/hpx) (a C++ runtime
parallel programming models), partially based on [Google's DataFlow Model](http://www.vldb.org/pvldb/vol8/p1792-Akidau.pdf).

# Build

## Prequisites:

    CMake >= 3.0.0
    HPX >= 0.9.11
    Boost >= 1.58.0

## Building

    mkdir build
    cd build
    cmake -DHPX_ROOT=/path/to/hpx/source/tree -DBOOST_ROOT=/your_boost_directory -DMYSQL_ROOT=/your/mysql/path ..

## Options

* Build examples:  ```-DHPXFLOW_BUILD_EXAMPLE (Default=ON)```

