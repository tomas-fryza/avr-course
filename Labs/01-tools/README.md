# Lab 1: Git version-control system, AVR tools

### Learning objectives

The purpose of this laboratory exercise is to learn how to use the git versioning system, write the markdown readme file, learn the basic structure of C code, and learn how to use development tools to program a microcontroller on the Arduino Uno.


## Preparation tasks (done before the lab at home)

Create an account on [GitHub](https://github.com/). Optionally, you can prepare the development chain on your own computer as follows.


### Windows

Download [Atmel Studio 7](https://www.microchip.com/mplab/avr-support/atmel-studio-7) and [SimulIDE](https://www.simulide.com/p/home.html). Alternatively, follow the instructions for [Windows](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Docs/HOWTO_windows.md) and create an entire comand-line toolchain instead of using Atmel Studio. Install [GitHub Desktop](https://desktop.github.com/) or [GitKraken](https://www.gitkraken.com/) to make working with git easier.


### Ubuntu-based Linux distributions

Download [SimulIDE](https://www.simulide.com/p/home.html). Follow the instructions for [Linux](https://github.com/tomas-fryza/Digital-electronics-2/blob/master/Docs/HOWTO_linux.md) and create an entire comand-line toolchain. Install [GitKraken](https://www.gitkraken.com/) to make working with git easier.


## Part 1: GitHub

GitHub is a code hosting platform for collaboration and version control. GitHub lets you (and others) work together on projects.

In GitHub, create a new public repository titled **Digital-electronics-2**. Initialize a README, .gitignore, and [MIT license](https://choosealicense.com/licenses/mit/).

Use manuals [How to make the perfect Readme.md on GitHub](https://medium.com/swlh/how-to-make-the-perfect-readme-md-on-github-92ed5771c061), [Basic writing and formatting syntax](https://help.github.com/en/articles/basic-writing-and-formatting-syntax) or [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) and add the following parts in your README file.

   * Headers
   * Emphasis (italics, bold)
   * Lists (ordered, unordered)
   * Links
   * Table
   * Listing of C source code


## Part 2: Local repository

In the lab, make your own home folder within `Documents`, and with help of `git` command of any Git GUI client clone a local copy of your public repository:




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

Download `Docs` and `Examples` folders from [this repository](https://github.com/tomas-fryza/Digital-electronics-2) and copy them to your `Digital-electronics-2` local repository.

```bash
$ ls
Docs  Labs  LICENSE  README.md
```


## Part 3: Test toolchain(s)

1. Run Visual Studio Code source code editor, open `Digital-electronics-2` folder, run internal terminal in menu **Terminal > New Terminal**, and change path to `Labs/01-demo`. What is the meaning of each part of source file `main.c`? What is the meaning of the following commands?

    ```bash
    $ cd Labs/01-demo/
    $ make all
    $ make size
    $ make flash
    $ make clean
    ```

2. Run Saleae Logic software from VS Code terminal

    ```bash
    $ Logic &
    ```

    connect Channel 0 to Arduino board pin 13, and use logical analyzer to verify duration of `_delay_ms()` function.

    ![logic](../../Images/screenshot_saleae.png "Saleae Logic software")

3. What is the meaning of `|`, `&`, `^`, `~`, `<<` operations in C source file? See [AVR Libc Reference Manual](https://www.microchip.com/webdoc/AVRLibcReferenceManual/) for answer.


## Synchronize git

Remove all binaries and object files from the working directory by command

```bash
$ make clean
```

Use `cd ..` command in Linux console terminal and change the working directory to `Digital-electronics-2`. Then use [git commands](https://github.com/joshnh/Git-Commands) to add, commit, and push all local changes to your remote repository. Check the repository at GitHub web page for changes.


```bash
$ pwd
/home/lab661/Documents/your-name/Digital-electronics-2/Examples/blink

$ cd ..
$ cd ..
$ pwd
/home/lab661/Documents/your-name/Digital-electronics-2

$ git status
$ git add <your-modified-files>
$ git status
$ git commit -m "[LAB] AVR toolchain tested"
$ git status
$ git push
$ git status
```





## Experiments on your own

1. Install AVR development tools on your computer.

2. Modify the blink example to repeatedly display the `DE2` string on the LED in Morse code.

3. Simulate the previous task in SimulIDE.


## Lab assignment

1. Link to your GitHub repository.

2. Blink example. Submit:
    * Answers to questions: What is the meaning of `|`, `&`, `^`, `~`, `<<` operations in C source file?

3. Morse code. Submit:
    * C code (`main.c`).

The deadline for submitting the task is the day before the next laboratory exercise. Use [BUT e-learning](https://moodle.vutbr.cz/) web page and submit a single PDF file.
