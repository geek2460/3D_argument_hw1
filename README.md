# 3D_argument_hw1
visual studio 2013 with openCV 3.0.0

set property:

project -> VC++ directory -> excutable directories -> $(OPENCV_DIR)\..\..\include

project -> VC++ directory -> library directories -> $(OPENCV_DIR)\lib    

linker -> input -> additional dependencies -> edit -> opencv_ts300.lib,opencv_world300.lib

