# OCCT Sandbox

Open Cascade Technology (OCCT) Sandbox. Place to play around with the API.

## Configure, Build and Run

To generate a build, I'm relying on a build system, **make**. However, the build system is created by **cmake**, a tool to generate a build system, platform independent. What it does, after some initial configuration, is building a *build* folder containing all necessary files and a preconfigured *Makefile* where all links and libraries locations are added to generate a binary using **make**.

In the main directory, simply run `make` to execute a couple of shell scripts that:
1. run `cmake` and make the *build* directory
2. run `make` inside the *build* directory
3. run the *binary* that has been created

You can have a look inside the *tools* directory what the shell scripts are doing.

As you probably noticed, `make` is used twice in this workflow. By running `make` inside the main directory, the *configure, build and run* procedure is started which consists of the 3 earlier discussed steps. In the second step, `make` is used to start the build in the *build* directory.

## Project structure

While I'm not following the *best practices* at the moment, this might change in the futur. I'll follow [this guideline](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#intro) whenever this project start to become bigger. 

## Installing Open Cascade

One of the dependencies is **Open Cascade** ofcourse. The installation procedure depends on the operating system you're running. Currently, I'm only including the installation process for linux and mac. 

We need to distinguish OCE and OCCT, both related to Open Cascade Technology, but the first one is the Community Edition. It includes a couple of patches. However, the ease of installation depends on the operating system. OCE is very easy to install on Ubuntu, while OCCT is the easiest on MacOS.  

### Ubuntu

Run the following:
```shell
sudo apt update -qq
sudo apt install -y liboce-*
```

### MacOS

First, install *Homebrew*, then run the following:
```
brew install opencascade
```

### Windows

Work in progress...

## Inspiration

I stumbled upon the *FindOpenCasCade.cmake* file by [FreeCAD](https://github.com/FreeCAD/FreeCAD/blob/5d49bf78de785a536f941f1a6d06d432582a95d3/cMake/FindOpenCasCade.cmake). This file contains a lot of intersting code I could use in this project. While FreeCAD depends on OCE, I adapted the script to search for OCCT on MacOS.
