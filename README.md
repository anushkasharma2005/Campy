!!  This project is under development !!



## Introduction


Baically Im trying to create a compiler (to learn how they work ofc) for a language (yeah coulds have made it for c or smth but haha) that I call campy. 

ya thats it. will keep updating as the project progresses


## Run the project

This project uses CMake. From the project root, run:

```bash
cmake -S . -B build
cmake --build build
./build/cam
```

If CMake complains about an old cache or a different source path, delete the `build` directory first and then run the commands above again.

If you already have a configured `build` directory, you can just rebuild and run:

```bash
cmake --build build
./build/cam
```

The current program prints the path to the compiled executable.
