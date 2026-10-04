from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            namespace='light_sensor',
            executable='light_sensor',
            name='sensor'
        ),
        Node(
            package='light_control_pkg',
            namespace='headlight_controller',
            executable='headlight_controller',
            name='controller'
        )
    ])