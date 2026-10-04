// ez lesz a publisher node, amely szimulalja a feny erzekeleset

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <chrono>

class LightSensor : public rclcpp::Node{
    public:
        LightSensor(): Node("light_sensor"), lux_lvl(100), step(-10){
            light_pub = this->create_publisher<std_msgs::msg::Int32>("/ambient_light", 1);
            timer = this->create_wall_timer(std::chrono::seconds(1), std::bind(&LightSensor::timer_callback, this));
        }
    private:
        void timer_callback(){
            auto message = std_msgs::msg::Int32();
            message.data = lux_lvl;
            light_pub->publish(message);
            RCLCPP_INFO(this->get_logger(), "Jelenlegi fényerő: %d", message.data);

            lux_lvl += step;
            
            if (lux_lvl > 100 || lux_lvl < 10){
                step = step*(-1);
            }
        }
        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr light_pub;
        int lux_lvl;
        int step;
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LightSensor>());
    rclcpp::shutdown();
    return 0;
}