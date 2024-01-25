## makefile

TARGET = test

SRC = useful_func.cc

CXXFLAGS = -std=c++11 -Wall

# g++命令编译程序
$(TARGET):$(SRC)
	g++ -o $(TARGET) $(SRC) $(CXXFLAGS)

clean:
	rm -f $(TARGET)
