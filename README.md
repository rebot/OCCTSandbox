# Hello World

First script in C++ I'm making.

## Configure, Build and Run

To generate a build, I'm relying on a build system, **make**. However, the build system is created by **cmake**, a tool to generate a build system, platform independent. What it does, after some initial configuration, is building a *build* folder containing all necessary files and a preconfigured *Makefile* where all links and libraries locations are added to generate a binary using **make**.

In the main directory, simply run `make` to execute a couple of shell scripts that:
1. run `cmake` and make the *build* directory
2. run `make` inside the *build* directory
3. run the *binary* that has been created

You can have a look inside the *tools* directory what the shell scripts are doing.

As you probably noticed, `make` is used twice in this workflow. By running `make` inside the main directory, the *configure, build and run* procedure is started which consists of the 3 earlier discussed steps. In the second step, `make` is used to start the build in the *build* directory.

### Project structure

While I'm not following the *best practices* at the moment, this might change in the futur. I'll follow [this guideline](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#intro) whenever this project start to become bigger. 