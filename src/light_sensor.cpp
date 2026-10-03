// ez lesz a publisher node, amely szimulalja a feny erzekeleset

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <chrono>

class LightSensor : public rclcpp::Node{
    public:
        LightSensor(): Node("light_sensor"){

        }
    private:
        void timer_callback(){

        }
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp:spin(std::make_shared<LightSensor>());
    rclcpp::shutdown();
    return 0;
}