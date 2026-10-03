// ez lesz a subscriber node, amely szimulalja a fenyszoro felkapcsolasat

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class HeadlightController : public rclcpp::Node{
    public:
        HeadlightController(): Node("headlight_controller") {

        }
    private:
        light_callback(){
            
        }
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclpp::spin(std::make_shared<HeadlightController>());
    rclcpp::shutdown();
    return 0;
}