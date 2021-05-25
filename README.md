# A simulator for a wireless charger placement algorithm in WRSN(Wireless Rechargable Sensor Network)
> An undergraduate project in SiChuan University directed by [Prof. Lin](http://cs.scu.edu.cn/info/1292/13645.htm)

Simulated the solutions in the following thesis:

[Y. Li, Y. Chen, C. S. Chen, Z. Wang and Y. Zhu, "Charging While Moving: Deploying Wireless Chargers for Powering Wearable Devices," in IEEE Transactions on Vehicular Technology, vol. 67, no. 12, pp. 11575-11586, Dec. 2018, doi: 10.1109/TVT.2018.2871870.](https://ieeexplore.ieee.org/document/8470952)

Implemented the Greedy based solution and the D&C-PSO solution and the main work of the project is to evaluate those solutions from the simulation results.

# Requirements:
- Cmake/3.16(Jetbrains Clion 2020.1.2 bundled version)
- Conan/1.35.0
- boost/1.75.0 (install it using conan)

# Build:

Regular Cmake building procedure, with `conanbuildinfo.cmake` placed under the cmake-debug-build folder.

# Results Plotting:

Jupyter notebook/6.0.3
Python/3.6.1
Numpy/1.18.5

File for plotting the result --> result_plotting.ipynb

# Run:

Just run the main function 😊;
