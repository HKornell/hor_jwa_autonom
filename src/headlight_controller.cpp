// ez lesz a subscriber node, amely szimulalja a fenyszoro felkapcsolasat

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class HeadlightController : public rclcpp::Node{
    public:
        HeadlightController(): Node("headlight_controller"), headlight_status(false){
            light_sub = this->create_subscription<std_msgs::msg::Int32>("/ambient_light", 1, std::bind(&HeadlightController::light_callback, this, std::placeholders=_1));
        }
    private:
        void light_callback(const std_msgs::msg::SharedPtr msg){
            int current_lux = msg->data;
            int threshold = 45;

            if (current_lux < treshold && headlight_status == false){
                RCLPP_INFO(this->get_logger(), "Sötétedik, fényszórók fel lettek kapcsolva!", current_lux);
                headlight_status = true;
            }
            else if (current_lux > treshold && headlight_status == true){
                RCLPP_INFO(this->get_logger(), "Világosodik, fényszórók le lettek kapcsolva!", current_lux);
                headlight_status = false;
            }
        }
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr light_sub;
        bool headlight_status;
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclpp::spin(std::make_shared<HeadlightController>());
    rclcpp::shutdown();
    return 0;
}