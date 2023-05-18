# $ - Simple Shell

A simple UNIX command interpreter written as part of the low-level programming in Software Engineering track at ALX.

## Description

**Simple Shell** is a simple UNIX command language interpreter that reads commands from standard input and executes them.

## Invocation

### To compile, execute this command

``` bash
gcc *.c -o hsh
```

**Simple Shell** can be invoked both interactively and non-interactively. If **Simple Shell** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

### Work like this in non-interactive mode

``` bash
$ echo "echo hello world" | ./hsh
hello world
$
```

### Work like this in interactive mode

``` bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) ls
hsh main.c shell.c
($)
($) exit
$
```

## Exit Status

**Simple Shell** returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.

If a command is not found, the return status is `127`; if a command is found but is not executable, the return status is 126.

All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

## Signals

To **exit** the interactive mode you can press **Ctrl+d**, **Ctrl+c** or type **exit**

## Builtin Commands

### env

* Usage: `env`
* Prints the current environment.

Example:

``` bash
$ ./hsh
$ env
SHELL=/bin/bash
...
```

### exit

* Usage: `exit [STATUS]`
* Exits the shell.
* The `STATUS` argument is the integer used to exit the shell.
* If no argument is given, the command is interpreted as `exit 0`.
Example:

``` bash
$ ./hsh
 ($) exit 98
$ echo $?
98
```

## Authors

* Yusuf EL-Swaify <[Yusuf-ELSwaify](https://github.com/Yusuf-ELSwaify)>
* Asmaa Mohamed <[AsmaaMohamed95](https://github.com/AsmaaMohamed95)>

