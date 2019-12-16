# Lab 1. Git version-control system, AVR toolchain

#### Table of contents

1. [Lab prerequisites](#Lab-prerequisites)
2. [GitHub](#GitHub)
3. [Linux terminal](#Linux-terminal)
4. [Test toolchain](#Test-toolchain)
5. [Clean project and synchronize git](#Clean-project-and-synchronize-git)


## Lab prerequisites

Create an account on [GitHub](https://github.com/) server.


## GitHub

In GitHub, create a new public repository titled **Digital-electronics-2**. Initialize a README, .gitignore, and [MIT license](https://choosealicense.com/licenses/mit/). Modify your README file according to [How to make the perfect Readme.md on GitHub](https://medium.com/swlh/how-to-make-the-perfect-readme-md-on-github-92ed5771c061), [Basic writing and formatting syntax](https://help.github.com/en/articles/basic-writing-and-formatting-syntax) or [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) articles.


## Linux terminal

Try basic commands in the Linux terminal:

| **Command** | **Description** |
| ----------- | --------------- |
| `Ctrl+Alt+T` | Open Linux terminal in Ubuntu based distributions
| `Tab` | Automatic completion what you are typing or suggest options to you
| `Up/Down` | Browse command history
| `ls` | List directory contents
| `cd` | Change the current directory (change to parent directory: `cd ..`)
| `mkdir` | Make directories
| `cp` | Copy files and directories
| `pwd` | Print name of current/working directory
| `mc` | GNU Midnight Commander (file manager)

In the lab, make your own home folder within `Documents`, and with help of `git` command create a local copy of your public repository:

```bash
$ cd
$ pwd
/home/lab661

$ cd Documents/
$ mkdir your-name
$ cd your-name/
$ pwd
/home/lab661/Documents/your-name

$ git clone https://github.com/your-github-account/Digital-electronics-2
$ cd Digital-electronics-2/
$ ls
LICENSE  README.md
```

Download `docs` and `firmware` folders from [teacher's template](https://gitlab.com/tomas.fryza/avr-template) and copy them to your `Digital-electronics-2` local repository.

```bash
$ ls
docs  firmware  LICENSE  README.md
```


## Test toolchain

Run Visual Studio Code source code editor, open `Digital-electronics-2` folder, run internal terminal in menu **Terminal > New Terminal**, and change path to `firmware/01-demo`. What is the meaning of each part of source file `main.c`? What is the meaning of the following commands?

```bash
$ cd firmware/01-demo/
$ make all
$ make size
$ make flash
$ make clean
```

Run Saleae Logic software from VS Code terminal

```bash
$ Logic &
```

connect Channel 0 to Arduino board pin 13, and use logical analyzer to verify duration of `_delay_ms()` function.

![logic](../../images/screenshot_saleae.png "Saleae Logic software")

What is the meaning of `|`, `&`, `^`, `~`, `<<`, `_BV()` operations in C source file? See [AVR Libc Reference Manual](https://www.microchip.com/webdoc/AVRLibcReferenceManual/) for answer.


## Clean project and synchronize git

Remove all binaries and object files from the working directory by command

```bash
$ make clean
```

Use `cd ..` command in VS Code terminal and change the working directory to `Digital-electronics-2`. Then use [git commands](https://github.com/joshnh/Git-Commands) to add, commit, and push all local changes to your remote repository. Check the repository at GitHub web page for changes.

```bash
$ pwd
/home/lab661/Documents/your-name/Digital-electronics-2/firmware/01-demo

$ cd ..
$ cd ..
$ pwd
/home/lab661/Documents/your-name/Digital-electronics-2

$ git status
$ git add <your-modified-files>
$ git commit -m "[PROJECT] Adding 01-demo project"
$ git push
```
