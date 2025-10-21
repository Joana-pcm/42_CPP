CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = BRAIN

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)

phony: clean fclean re