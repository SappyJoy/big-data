# Everything that you need to know to configure this project

This project works fine in Visual Studio Code with configured clangd, CMake and git.  

## [Clang Format hook](https://github.com/barisione/clang-format-hooks)

To configure clangd you need to pull clang-format-hooks submodule and register it:

```sh
git submodule update --init
cd clang-format-hooks && ./git-pre-commit-format install
```

## [Clangd](https://clangd.llvm.org/installation)

To clangd understand your source code you need to have `compile_commands.json` in root of your project. You can generate this file by building project:

```sh
mkdir build
cmake -S . -B build
cmake --build build -j <number of jobs>
ln -s build/compile_commands.json .
```

## clang-17

To build project with clang-17 set CC and CXX environment variables
