# hpxflow
HpxFlow is a unified Batch and Stream Processing framework, over [HPX](https://github.com/STEllAR-GROUP/hpx) (a C++ runtime
parallel programming models), partially based on [Google's DataFlow Model](http://www.vldb.org/pvldb/vol8/p1792-Akidau.pdf).
* Current work include phase 1 implementation of algorithm's needed for batch processing, such as: K-Mean Clustering , algorithms, Eucledian Distance, Density Based Clustering, Region Query, Dijkstra, and other mathematical operations like: grt, lst, grt_equal, lst_equal, summation, etc.
* Given framework uses Fluent Interface API, along with lambda to have expressions like: 

```ifstream stream1("test.txt");```

```ifstream infile; ```

```infile.open("test.txt"); ```

```Test t("test.txt");```

```t.map([](std::string i) { return std::stoi(i)*2; }).reduce([](std::string i) {hpx::flow::count() });```

# Build

## Prequisites:

* CMake >=
* HPX >=
* Boost >=

## Building

mkdir build && cd build 
cmake \
-DBOOST_ROOT=<path to boost installation> \
..

## Options

* Build examples:  -DHPXFLOW_BUILD_EXAMPLE (Default=OFF)

