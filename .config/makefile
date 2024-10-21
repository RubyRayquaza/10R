# Source files
SRCS = src/main.cpp src/autonomous.cpp src/drivetrain.cpp
OBJS = $(SRCS:.cpp=.o)

# Build target
TARGET = robot_program

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)
