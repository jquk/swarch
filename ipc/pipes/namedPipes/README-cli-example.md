Let's look at another command line example to get the gist of named pipes. Here are the steps:

    Open two terminals. The working directory should be the same for both.
    In one of the terminals, enter these two commands (the prompt again is %, and my comments start with ##):
```
    $ mkfifo tester  ## creates a backing file named tester
    $ cat tester     ## type the pipe's contents to stdout
```
    At the beginning, nothing should appear in the terminal because nothing has been written yet to the named pipe.
    In the second terminal, enter the command:
```
    $ cat > tester  ## redirect keyboard input to the pipe
    hello, world!   ## then hit Return key
    bye, bye        ## ditto
    <Control-C>     ## terminate session with a Control-C
```
    Whatever is typed into this terminal is echoed in the other. Once Ctrl+C is entered, the regular command line prompt returns in both terminals: the pipe has been closed.
    Clean up by removing the file that implements the named pipe:
```
    $ unlink tester
```

As the utility's name mkfifo implies, a named pipe also is called a FIFO because the first byte in is the first byte out, and so on.
There is a library function named mkfifo that creates a named pipe in programs and is used in the next example, which consists of two processes:
one writes to the named pipe and the other reads from this pipe.