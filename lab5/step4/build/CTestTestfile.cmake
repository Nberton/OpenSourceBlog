# CMake generated Testfile for 
# Source directory: /home/ubuntu/Documents/OpenSourceBlog/lab5/step4
# Build directory: /home/ubuntu/Documents/OpenSourceBlog/lab5/step4/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(TutorialComp25 "Tutorial" "25")
SET_TESTS_PROPERTIES(TutorialComp25 PROPERTIES  PASS_REGULAR_EXPRESSION "25 is 5")
ADD_TEST(TutorialComp-25 "Tutorial" "-25")
SET_TESTS_PROPERTIES(TutorialComp-25 PROPERTIES  PASS_REGULAR_EXPRESSION "-25 is 0")
SUBDIRS(MathFunctions)
