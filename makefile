bin/cf/%.o: cf/%.cpp
	mkdir -p $(dir $@)
	g++ --std=gnu++2a $^ -o $@

bin/kattis/%.o: kattis/%.cpp
	mkdir -p $(dir $@)
	g++ --std=gnu++17 $^ -o $@

bin/ac/%.o: ac/%.cpp
	mkdir -p $(dir $@)
	g++ --std=gnu++17 $^ -o $@

bin/usaco/%.o: usaco/%.cpp
	mkdir -p $(dir $@)
	g++ --std=gnu++17 $^ -o $@

bin/euler/%.o: euler/%.cpp
	mkdir -p $(dir $@)
	g++ -std=c++20 $^ -o $@

bin/practice/%.o: practice/%.cpp
	mkdir -p $(dir $@)
	g++ --std=gnu++17 $^ -o $@

# all: bin/cf/%.o bin/kattis/%.o bin/ac/%.o bin/usaco/%.o bin/euler/%.o bin/practice/%.o

clean:
	rm -rf bin/*