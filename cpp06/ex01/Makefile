CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 

SRCS = main.cpp Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = Serializer
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)

phony: clean fclean re