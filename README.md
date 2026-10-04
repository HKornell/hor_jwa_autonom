# `light_control` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)
A "light_control" package 2 node-ból áll. A publisher node a "light_sensor", ami a fényerősség mérésének szimulációjáért felelős.
A "headlight_controller" a subscriber node, ez szimulálja a fényszóró automatikus vezérlését a fényerősség függvényében. Ha a fény adott érték alatt van felkapcsolja, ha adott érték felett, akkor pedig le. 
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/sze-info/ros2_cpp_template
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select ros2_cpp_template --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch ros2_cpp_template launch_example1.launch.py
```
