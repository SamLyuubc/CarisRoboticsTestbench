execute_process(COMMAND "/home/samlyu/testbench_ws/build/catkin/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/samlyu/testbench_ws/build/catkin/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
