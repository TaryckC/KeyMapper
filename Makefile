CXX = g++
CXXFLAGS = -std=c++20 -Wall `pkg-config --cflags Qt6Widgets`
LDFLAGS = `pkg-config --libs Qt6Widgets`

MOC_HEADERS = src/gui/KeyBindingInterface.hpp
MOC_SRC = $(MOC_HEADERS:%.hpp=%.moc.cpp)

SRC = src/Main.cpp src/gui/KeyBindingInterface.cpp $(MOC_SRC)
BIN = bin
OBJ = $(patsubst src/%, $(BIN)/%, $(SRC:.cpp=.o))
TARGET = ../keymapper

all: $(BIN) $(BIN)/gui $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $(BIN)/$@ $^ $(LDFLAGS)

$(BIN)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.moc.cpp: %.hpp
	/opt/homebrew/Cellar/qt/6.9.0/share/qt/libexec/moc $< -o $@

$(BIN):
	mkdir -p $(BIN)

$(BIN)/gui:
	mkdir -p $(BIN)/gui

clean:
	rm -f $(OBJ) $(BIN)/$(TARGET)