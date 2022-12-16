CF_CPP := $(wildcard cf/*/*.cpp)
CF_OBJ := $(patsubst cf/%,cf/bin/%,$(CF_CPP:.cpp=.o))
KT_CPP := $(wildcard kt/*/*/*.cpp)
KT_OBJ := $(patsubst kt/%,kt/bin/%,$(KT_CPP:.cpp=.o))

all: cf kt

cf: $(CF_OBJ)
kt: $(KT_OBJ)

cf/bin/%.o: cf/%.cpp
	mkdir -p $(dir $@)
	g++ --std=gnu++2a $^ -o $@

kt/bin/%.o: kt/%.cpp
	mkdir -p $(dir $@)
	g++ --std=gnu++17 $^ -o $@

clean:
	rm -rf cf/bin/* kt/bin/*