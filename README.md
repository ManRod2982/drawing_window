# Drawing window

This is a simple window that allows to write in black and white.
The goal is to eventually integrate it with a neural network trained
on the MNIST data set to be able to detect drawn numbers.

![alt text](https://github.com/ManRod2982/drawing_window/raw/master/docs/window_example.png "Nmist window")

# Building the project

The project is built using CMake after installing the dependencies one can simply run

```
mkdir build
cmake -B build
cmake --build build
```

And the target binary will be built and can be executed as follows

`./build/window`

# Dependencies

This project uses CMake 3.10 or later and Gtkmm 3.0

```
sudo apt install cmake
sudo apt install libgtkmm-3.0-dev
```

# License

This software is available under the MIT license.