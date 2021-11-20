https://opensource.com/article/19/4/interprocess-communication-linux-storage

## Shared Files
Shared files may be the most basic IPC mechanism.
Consider the relatively simple case in which one process (producer) creates and writes to a file, and another process (consumer) reads from this same file:
```
         writes  +-----------+  reads
producer-------->| disk file |<-------consumer
                 +-----------+
```

The obvious challenge in using this IPC mechanism is that a **race condition** might arise: the producer and the consumer might access the file at exactly the same time, thereby making the outcome indeterminate.

To avoid a race condition, the file must be locked and unlocked to alternate between w/w and w/r operations.
The locking API in the standard system library can be summarized as follows:

Exclusive locks:
- Allow to avoid race conditions on both read and write operations.
- Necessary for safely writing to the file.
- Only one process can get an exclusive lock at a time, thus ruling out a race condition.

Shared locks:
- Allow to avoid race conditions only for read operations.
- Minimum lock level necessary for safely reading a file.
- Multiple readers can hold a shared lock at the same time.
- Blocks any write access attempt.

The standard C I/O library includes a utility function named **fcntl** that can be used to inspect and manipulate both exclusive and shared locks on a file. The function works through a file descriptor, a non-negative integer value that, within a process, identifies a file (different file descriptors in different processes may identify the same physical file).

For file locking, Linux provides the library function flock, which is a thin wrapper around fcntl. The first example uses the fcntl function to expose API details.
