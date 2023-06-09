## Chapter 2.

### TOC

1. [2-1](#2-1)
2. [2-2](#2-2)
3. [2-3](#2-3)
4. [2-4](#2-4)
5. [2-5](#2-5)
6. [2-6](#2-6)
7. [2-7](#2-7)
8. [2-8](#2-8)
9. [2-9](#2-9)
10. [2-10](#2-10)
11. [2-11](#2-11)
12. [2-12](#2-12)
13. [2-13](#2-13)
14. [2-14](#2-14)
15. [2-15](#2-15)
16. [2-16](#2-16)
17. [2-17](#2-17)
18. [2-18](#2-18)
19. [2-19](#2-19)
20. [2-20](#2-20)
21. [2-21](#2-21)
22. [2-22](#2-22)
23. [2-23](#2-23)
24. [2-24](#2-24)
25. [Programming-1](#Programming-1)
26. [Programming-2](#Programming-2)

## [2-1](#TOC)

### Q

What is the purpose of system calls?

### A

System calls provide interfaces to user application program to use the hardware and OS resources.

#### solution ref)

## [2-2](#TOC)

### Q

What is the purpose of the command interpreter? Why is it usually separate from the kernel?

### A

1. Command interpreter provide interfaces to real user to use OS.
2. Users may want to use various command interpreter, but if CLI is in kernel, user can't have much choices.

#### solution ref)

## [2-3](#TOC)

### Q

What system calls have to be executed by a command interpreter or shell in order to start a new process on a UNIX system?

### A

`fork()` system call.

#### solution ref)

## [2-4](#TOC)

### Q

What is the purpose of system programs?

### A

System programs provide more useful environment to develop and execute program. Some of them are just user interface for system call, others are more complicated. They can be classified by below:

1. File management
2. Status info
3. File edit
4. Programing language support
5. Program loading and execution
6. Communication
7. Background service

#### solution ref)

## [2-5](#TOC)

### Q

What is the main advantage of the layered approach to system design? What are the disadvantages of the layered approach?

### A

1. Pros

   - Easy implementation: layers can use only itself and lower layers' service and functionality. Each Layer would communicate with interface. Each layers don't need to know other layers' implementation.
   - Easy debugging: If a bug occurred, engineer can debug from lowest layer. When it ends, next is second layer. Second layer only use lower layer(lowest, which is first) so if first layer is correct, bug would be upper first. In the same way, debugging goes from bottom to top, and when error is on specific layer, the lower layer are already debugged so bug is on that layer.

2. Cons
   - Hard architecturing: To make easily and efficiently working system, engineer should define each layers' functionality properly.
   - System overhead: To get proper functionality, some feature should go through several layers, and it makes some overhead.

#### solution ref)

## [2-6](#TOC)

### Q

List five services provided by an operating system, and explain how each creates convenience for users. In which cases would it be impossible for user-level programs to provide these services? Explain your answer.

### A

1. Process Control
   - Users can load and execute program, and manage processes. Users can stop or terminate process.
2. File Manipulation
   - Users can read/write files, create/delete files and directory, rename, enumerate files.
3. Device Management
   - Mount, release devices and request to use them. Read/write/reposition devices.
4. Information Maintenance
   - Get time/system data and get/set process/file/device attribute data.
5. Communication
   - Create/delete connection, send/recieve message, send status, attach/detach remote device.
6. Protection
   - get/set file permission

#### solution ref)

## [2-7](#TOC)

### Q

Why do some systems store the operating system in firmware, while others store it on disk?

### A

To load and start computer system faster. If OS is on disk, boot loader load kernel in disk and load it to memory and execute. It takes some time, while Os in firmware can just load it once and work well.

#### solution ref)

## [2-8](#TOC)

### Q

How could a system be designed to allow a choice of operating systems from which to boot? What would the bootstrap program need to do?

### A

Boot loader bootstraps os and boot loader can be exchanged. Bootstrap program need to load and execute OS program and check for memory, cpu, device status. Also initialize cpu register, device controller, main memory.. all aspect of systems.

#### solution ref)

## [2-9](#TOC)

### Q

The services and functions provided by an operating system can be divided into two main categories. Briefly describe the two categories, and discuss how they differ.

### A

#### solution ref)

1. System service
   - System service interact with hardware directly. They are low-level functionality, and manage process control, file manipulation, device manangement, information maintenance, communication and protection.
2. Application service
   - Application service interact with user or user program. They are high-level func, and they usually include web browser, word processor, text formatter, DB system, compiler, statistics packages, etc.

System service and application service have difference by how they used and by whom. System service usually used by other system service or user application, not user itself. But app service can be used by users itself.

## [2-10](#TOC)

### Q

Describe three general methods for passing parameters to the operating system.

### A

#### solution ref)

1. Register method

- passing parameters in registers
- accessed by the operating system to perform the required operation
- efficient because it avoids the need to push the arguments onto the stack
- limitations due to the limited number of registers available

2. Stack method

- passing parameters on the program stack
- arguments for a system call are pushed onto the stack&popped off the stack to perform the required operation
- more flexible than the register method because it can handle an arbitrary number of arguments
- requires more memory and is slower due to the overhead of push&pop data from the stack

3. Block/Structure method

- passing parameters as a block or a structure
- arguments for a system call are passed as a single unit, such as a block of memory or a data structure, which contains all the required parameters
- efficient because it avoids the overhead of pushing and popping data from the stack, and it is flexible because it can handle an arbitrary number of arguments
- requires more setup time to create the data structure and may result in additional memory overhead

## [2-11](#TOC)

### Q

Describe how you could obtain a statistical profile of the amount of time a program spends executing different sections of its code. Discuss the importance of obtaining such a statistical profile.

### A

Insert timer system call at section boundary. Then get execution time of each section then write it. It is important to check which section of program is bottle-neck.

#### solution ref)

## [2-12](#TOC)

### Q

What are the advantages and disadvantages of using the same system call interface for manipulating both files and devices?

### A

1. Pros
   - Files and devices are so much similar because of they are both relevant to I/O. Files can read/write, devices also read while input, write while output. So using same sys call interfaces makes users(programmers) easy to deal with both files and devices.
2. Cons
   - Files and devices are similar, though they are not same. Some devices is not similar to file(but i cannot give you example). In that case, same sys call interface would not fit to that device.

#### solution ref)

## [2-13](#TOC)

### Q

Would it be possible for the user to develop a new command interpreter using the system-call interface provided by the operating system?

### A

Yes. Many major command interpreters(shell) are just using few system calls like `fork()` and `exec()`: shells just get commands and make new process to execute the command's program.

#### solution ref)

## [2-14](#TOC)

### Q

Describe why Android uses ahead-of-time (AOT) rather than just-in-time (JIT) compilation.

### A

Android is for mobile device, and mobile devices have less CPU, memory, and power supply. JIT compilation can get performance improvement, but it should execute user program with compilation during runtime. But, AOT compilation compiles bytecode ahead, and hardware just execute the compiled machine code. It can reduce power consumption and get efficient application execution.

#### solution ref)

## [2-15](#TOC)

### Q

What are the two models of interprocess communication? What are the strengths and weaknesses of the two approaches?

### A

1. Message Passing

   - Communication overhead for message formatting
   - Easy implementation, no access conflict

2. Shared Memory
   - Fast access, easy communication for process
   - Hard implementation, need access syncronizing and protection

#### solution ref)

## [2-16](#TOC)

### Q

Contrast and compare an application programming interface (API) and an application binary interface (ABI).

### A

1. API

   - Interface for program, especially for specific programming language

2. ABI
   - Interface for architecture, also for specific OS platform
   - Include address length, way of passing parameters to sys call, runtime stack structure, sys lib binary format, data type size, etc.

#### solution ref)

## [2-17](#TOC)

### Q

Why is the separation of mechanism and policy desirable?

### A

Policy can flexible, be changed very often. If policy and mechanism are tightly coupled, if policy change, we must re-implement mechanism too. Assume that policy and mechanism are separated and policy are implemented to some parameters. Mechanism uses parameters to implement policies. That makes policies flexible.

#### solution ref)

## [2-18](#TOC)

### Q

It is sometimes difficult to achieve a layered approach if two components of the operating system are dependent on each other. Identify a scenario in which it is unclear how to layer two system components that require tight coupling of their functionalities.

### A

#### solution ref)

Virtual memory management VS Process Scheduling

Virtual memory management allows the operating system to allocate and manage virtual memory, which enables each process to have its own address space. Process scheduling determines which process should run next and allocates CPU time to that process.

The virtual memory manager needs to know the state of the process that is currently running, and the process scheduler needs to know the memory usage of each process. In addition, the virtual memory manager needs to allocate memory for the process being scheduled, and the process scheduler needs to consider the memory usage of each process when deciding which process to run next.

To address this issue, modern operating systems use a hybrid approach that combines both virtual memory management and process scheduling into a single component. This approach allows the operating system to balance the competing demands of memory management and process scheduling and ensures that these two critical components are tightly integrated and work together efficiently.

## [2-19](#TOC)

### Q

What is the main advantage of the microkernel approach to system design? How do user programs and system services interact in a microkernel architecture? What are the disadvantages of using the microkernel approach?

### A

1. Pros

   - Easy Expansion. All new services are in user area(user application program) so no change for kernel.
   - Highly portable. Easy to change such a stuffs which are dependent to hardware.
   - High security and trust. Many services are on user process, so one process' failure is not effective to kernel or other micorkernel components.

2. Cons
   - Communication overhead. If one service want to communicate to others, they are separated process so message should be copied.
   - Process switch overhead. Os services are process so process switch overhead occurs.

#### solution ref)

## [2-20](#TOC)

### Q

What are the advantages of using loadable kernel modules?

### A

1. Easy maintaining: kernel's each part has interface so easily set boundary and decoupling.
2. Flexibility: each module can call other modules to get proper works and easily insert and remove on runtime.
3. Efficiency: each module don't need to send messages, just call other module.

#### solution ref)

## [2-21](#TOC)

### Q

How are iOS and Android similar? How are they different?

### A

1. Similarity

   - Both for mobile device, so they provide graphic, audio, other hardwares' framework.
   - Both have hybrid, layered os architecture.

2. Difference
   - IOS and Android provide different application programming framework.
   - Android has its' own Hardware Abstraction Layer(HAL) because android should be portable to many device.
   - IOS use Mach kernel, Android use Linux kernel.

#### solution ref)

## [2-22](#TOC)

### Q

Explain why Java programs running on Android systems do not use the standard Java API and virtual machine.

### A

Android is for mobile device and mobile device has limited hardware resources, so Java programs should be efficient. Android RunTime(ART) is optimized on memory and cpu usage so Java programs can be executed more efficiently.

#### solution ref)

## [2-23](#TOC)

### Q

The experimental Synthesis operating system has an assembler incorporated in the kernel. To optimize system-call performance, the kernel assembles routines within kernel space to minimize the path that the system call must take through the kernel. This approach is the antithesis of the layered approach, in which the path through the kernel is extended to make building the operating system easier. Discuss the pros and cons of the Synthesis approach to kernel design and system-performance optimization.

### A

1. Pros: system-performance view
   - Sys call can pass less layer or no layer, so system-performance would be high.
2. Cons: kernel design view
   - Sys call path are optimized and integrated to kernel, so it would be hard to maintain and debug it.

#### solution ref)

## [2-24](#TOC)

### Q

In Section 2.3, we described a program that copies the contents of one file to a destination file. This program works by first prompting the user for the name of the source and destination files. Write this program using either the POSIX or Windows API. Be sure to include all necessary error checking, including ensuring that the source file exists.

Once you have correctly designed and tested the program, if you used a system that supports it, run the program using a utility that traces system calls. Linux systems provide the `strace` utility, and macOS systems use the `dtruss` command. (The `dtruss` command, which actually is a front end to `dtrace`, requires `admin` privileges, so it must be run using `sudo`.) These tools can be used as follows (assume that the name of the executable file is `FileCopy`:

**Linux**:

```
strace ./FileCopy
```

**macOS**:

```
sudo dtruss ./FileCopy
```

Since Windows systems do not provide such a tool, you will have to trace through the Windows version of this program using a debugger.

### A

See also `FileCopy.c`.

<img src="./images/2-24.png"/>

#### solution ref)

## [Programming-1](TOC)

### Q

Design a kernel module that creates a `/proc` file named `/proc/jiffies` that reports the current value of `jiffies` when the `/proc/jiffies` file is read, such as with the command

```sh
cat /proc/jiffies
```

Be sure to remove `/proc/jiffies` when the module is removed.

### A

See also `jiffies.c`.

1. Build kernal module with `make all`
2. Insert module with `sudo insmod MODULE_FILE_NAME.ko`
3. See result with `cat /proc/jiffies`

<img src="./images/PL_1.png"/>

## [Programming-2](TOC)

### Q

Design a kernel module that creates a proc file named `/proc/seconds` that reports the number of elapsed seconds since the kernel module was loaded. This will involve using the value of `jiffies` as well as the `HZ` rate. When a user enters the command

```sh
cat /proc/seconds
```

your kernel module will report the number of seconds that have elapsed since the kernel module was first loaded. Be sure to remove `/proc/seconds` when the module is removed.

### A

See also `seconds.c`.

1. Build kernal module with `make all`
2. Insert module with `sudo insmod MODULE_FILE_NAME.ko`
3. See result with `cat /proc/seconds`

<img src="./images/PL_2.png"/>
