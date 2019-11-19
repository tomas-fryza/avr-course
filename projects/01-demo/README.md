
# Lab 1. Git version-control system, GitHub, AVR toolchain

#### Table of Contents

1. [GitHub](#GitHub)
2. [Linux Terminal](#Linux-Terminal)
3. [Software](#software)
4. [References](#references)


## GitHub

Create your account on the server [https://github.com/](https://github.com/). Create a new public repository titled `Digital-electronics-2`. Initialize a README, .gitignore, and MIT license ([Licenses & Standards](https://opensource.org/licenses/)).

Modify README file according to [Basic writing and formatting syntax](https://help.github.com/en/articles/basic-writing-and-formatting-syntax) or [Mastering Markdown](https://guides.github.com/features/mastering-markdown/).


## Linux Terminal

Try basic commands in the Linux terminal:

| **Command** | **Description** |
| ----------- | --------------- |
| `Ctrl+Alt+T` | Open Linux Terminal in Ubuntu based distributions
| `Tab` | Automatic completion what you are typing or suggest options to you
| `Up/Down` | Browse command history
| `ls` | List directory contents
| `cd` | Change the current directory (change to parent directory: `cd ..`)
| `mkdir` | Make directories
| `cp` | Copy files and directories
| `pwd` | Print name of current/working directory
| `mc` | GNU Midnight Commander (file manager)

Within `Documents` folder, make your own home folder, and with help of `git` command create a local copy of your public repository:

```console
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

Download `docs` and `firmware` folders from teacher's template [https://gitlab.com/tomas.fryza/avr-template](https://gitlab.com/tomas.fryza/avr-template) and copy it to your `Digital-electronics-2` local repository.

```console
$ ls
docs  firmware  LICENSE  README.md
```


## Test toolchain

Run Visual Studio Code editor ([VS Code](https://code.visualstudio.com/)), open `Digital-electronics-2` folder, use editor's internal terminal (**Terminal > New Terminal**) and change path to `firmware/01-demo`. What is the function of each part of source file `main.c`? What is the meaning of the following commands?

```console
$ cd firmware/01-demo/
$ make
$ make size
$ make flash
$ make clean
```

Run Saleae Logic software ([Logic](https://www.saleae.com/downloads/)) from VS Code terminal

```console
$ Logic &
```

connect Channel 0 to Arduino board pin 13, and use logical analyzer to verify duration of `_delay_ms()` function.

**TODO: Include Logic screenshot**

What is the meaning of `|=`, `&=`, `^`, `~`, `<<`, `_BV()` operations in C source file? See [AVR Libc Reference Manual](https://www.microchip.com/webdoc/AVRLibcReferenceManual/) for answer.


## Clean folder and synchronize git

Remove all binaries and object files from the working directory by command

```console
$ make clean
```

Use `cd ..` command in VS Code terminal and change the working directory to `Digital-electronics-2`. Then use [git commands](https://github.com/joshnh/Git-Commands) and push all local changes to your remote repository. Check the repository at GitHub web page for changes.

```console
$ pwd
/home/lab661/Documents/your-name/Digital-electronics-2/firmware/01-demo
$ cd ..
$ cd ..
$ pwd
/home/lab661/Documents/your-name/Digital-electronics-2
$ git status
$ git add <your-modified-files>
$ git commit -m "First project added"
$ git push
```


## References

1. Licenses & Standards, [https://opensource.org/licenses/](https://opensource.org/licenses/)

2. Basic writing and formatting syntax, [https://help.github.com/en/articles/basic-writing-and-formatting-syntax](https://help.github.com/en/articles/basic-writing-and-formatting-syntax)

3. Mastering Markdown, [https://guides.github.com/features/mastering-markdown/](https://guides.github.com/features/mastering-markdown/)

4. AVR template for bachelor course Digital Electronics 2, [https://gitlab.com/tomas.fryza/avr-template](https://gitlab.com/tomas.fryza/avr-template)

5. Visual Studio Code - Code Editing, [https://code.visualstudio.com/](https://code.visualstudio.com/)

6. Logic analyzer software from Saleae, [https://www.saleae.com/downloads/](https://www.saleae.com/downloads/)

7. AVR Libc Reference Manual, [https://www.microchip.com/webdoc/AVRLibcReferenceManual/](https://www.microchip.com/webdoc/AVRLibcReferenceManual/)

8. Git Commands, [https://github.com/joshnh/Git-Commands](https://github.com/joshnh/Git-Commands)
