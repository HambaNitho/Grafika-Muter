all:
	g++ src/canvas.cpp src/color.cpp src/drawer.cpp src/line.cpp src/point.cpp src/multiplication.cpp src/polygon.cpp src/main.cpp src/fill.cpp -o bin/main

dpoint:
	g++ src/canvas.cpp src/color.cpp src/drawer.cpp src/line.cpp src/point.cpp src/multiplication.cpp src/polygon.cpp src/d_point.cpp src/fill.cpp -o bin/d_point