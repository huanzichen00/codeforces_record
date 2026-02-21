ifneq ($(shell command -v g++-14 2>/dev/null),)
  CXX := g++-14
else ifneq ($(shell command -v g++-13 2>/dev/null),)
  CXX := g++-13
else ifneq ($(shell command -v g++-12 2>/dev/null),)
  CXX := g++-12
else ifneq ($(shell command -v g++ 2>/dev/null),)
  CXX := g++
else
  CXX := clang++
endif

CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wshadow -Iinclude
BUILD_DIR := build

.PHONY: help list build run clean

help:
	@echo "用法:"
	@echo "  make help                     # 查看帮助"
	@echo "  make list                     # 列出所有 .cpp 文件"
	@echo "  make build SRC=path/to/a.cpp  # 只编译"
	@echo "  make run SRC=path/to/a.cpp    # 编译并运行"
	@echo "  make clean                    # 清理 build 目录"
	@echo ""
	@echo "当前编译器: $(CXX)"

list:
	@find . -type f -name '*.cpp' | sed 's#^\./##' | sort

build:
	@test -n "$(SRC)" || (echo "错误: 请指定 SRC=xxx.cpp" && exit 1)
	@test -f "$(SRC)" || (echo "错误: 文件不存在: $(SRC)" && exit 1)
	@mkdir -p $(BUILD_DIR)
	@OUT="$(BUILD_DIR)/$$(echo "$(SRC)" | sed 's#^\./##; s#/#_#g; s#\.cpp$$##')"; \
	echo "[BUILD] $(SRC) -> $$OUT"; \
	$(CXX) $(CXXFLAGS) "$(SRC)" -o "$$OUT"

run: build
	@OUT="$(BUILD_DIR)/$$(echo "$(SRC)" | sed 's#^\./##; s#/#_#g; s#\.cpp$$##')"; \
	echo "[RUN] $$OUT"; \
	"$$OUT"

clean:
	rm -rf $(BUILD_DIR)
