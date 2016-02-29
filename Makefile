all:
	g++ src/canvas.cpp src/color.cpp src/drawer.cpp src/line.cpp src/point.cpp src/multiplication.cpp src/polygon.cpp src/main.cpp -o bin/main -lncurses

dpoint:
	g++ src/canvas.cpp src/color.cpp src/drawer.cpp src/line.cpp src/point.cpp src/multiplication.cpp src/polygon.cpp src/d_point.cpp -o bin/d_point -lncurses