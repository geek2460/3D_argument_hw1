# 3D_argument_hw1
visual studio 2013 with openCV 3.0.0
$(OPENCV_DIR) = C:\opencv\build\x86\vc12

set property:

project -> VC++ directory -> excutable directories -> C:\opencv\build\include

project -> VC++ directory -> library directories -> $(OPENCV_DIR)\lib    

C/C++ -> Additional Include directories -> C:\opencv\build\include

linker -> input -> additional dependencies -> edit -> opencv_ts300.lib,opencv_world300.lib

