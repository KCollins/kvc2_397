  

    cmake_minimum_required(VERSION 2.8.3)

# Here is what your project (package) is called.  Should be the same as your package.xml package name.
project(kvc2_397)

## This is where you put all of the dependencies for the package.
## When using catkin_create_pkg, this is one of the places where 
## the dependencies are auto-placed.  If you need to add more later
## on, you need to put them in manually. 

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Tell catkin about your services here so it will properly generate
## the required header files

add_service_files(
	FILES
	ampfreq.srv
)

## Message / service dependencies go here!  Ie, if you have a 
## geometry_msgs/Twist in your message / service, you should
## put 'geometry_msgs' here.
generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

## This stuff tells catkin to compile your node!
add_executable(minimal_commander src/minimal_commander.cpp)
target_link_libraries(minimal_commander
   ${catkin_LIBRARIES}
)

## This stuff tells catkin to compile your node!
add_executable(minimal_captain src/minimal_captain.cpp)
target_link_libraries(minimal_captain
   ${catkin_LIBRARIES}
)

   ## This stuff tells catkin to compile your node!
add_executable(minimal_simulator src/minimal_simulator.cpp)
target_link_libraries(minimal_simulator
   ${catkin_LIBRARIES}
)

      ## This stuff tells catkin to compile your node!
add_executable(minimal_controller src/minimal_controller.cpp)
target_link_libraries(minimal_controller
   ${catkin_LIBRARIES}
)
