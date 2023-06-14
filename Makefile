WOLFRAM_APIID :=

.PHONY: build
build: configure
	cmake --build build

.PHONY: configure
configure:
	cmake -B build -DWOLFRAM_APIID=${WOLFRAM_APIID}

.PHONY: run
run:
	./build/answer_app

.PHONY: test
test:
	ctest --test-dir build -R "^answer."

.PHONY: clean
clean:
	rm -rf build

#
# Use Make to call CMake commands more conveniently：
#
#     make build WOLFRAM_APPID=xxx
#     make test
#     make run
#     make clean
#