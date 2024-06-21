    📍️  UNIVERSITY : IBU, FENMS, IT - IT 204 Operating Systems - Project 1 (2)
    📅️  DATE : March 2024, Sarajevo

    👥️  TEAM MEMBERS : Belma Sehic*, Amina Srna*
    👥️  CONTACT : belma.sehic@stu.ibu.edu.ba* , amina.srna@stu.ibu.edu.ba*

    📁️  FILES INCLUDED : task1 (basic, advanced), task2 (basic, intermediate, advanced), task3 (basic, intermediate, forkbomb), task4 along with screenshots for better representation of every task

    🌐️  SOURCES : GeeksForGeeks, StackOverflow, ChatGPT, LMS Materials...

    📝️  PROBLEMS : While working on these tasks, we faced a few issues, including permission denials and non-functional commands caused by a compromised installation. Additionally, the potential consequences of implementing a fork bomb were daunting enough to lead us to provide a detailed explanation rather than executing it as a program.

    📝️  OVERVIEW : Writing C programs using Virtual Box, Ubuntu terminal and further exploring commands such as ls, mkdir, uptime, and sl provides practical insights into command execution, shell, system functionality, error handling, security, and their practical applications within system administration. By switching between our regular operating systems (Mac and Windows) and Linux, we also saw the difference between operating systems and importance of having a skill to handle them.

    ❓️  QUESTIONS CAN BE FOUND IN THE DOCUMENT.
    ❓️  Question 1.5.1 

-Both reading from disk and accessing the hardware clock require the utilization of kernel mode since they involve accessing specific hardware resources or instructions. 
- For reading from disk, the application needs to interact with storage-related hardware such as hard drives or SSDs, necessitating privileged access managed by the operating system to ensure security and resource management.
- Similarly, accessing the hardware clock to retrieve the current time involves hardware resources and has potential implications on system functionality and security, thus requiring privileged access typically managed by the operating system in kernel mode.

    ❓️  Question 1.5.2 

-Certain services, when needed, can be requested from the operating system and for that purpose, the system calls serve as an interface for the user-level process. System calls, on the other hand, communicate with the kernel of the operating system. System calls are primarily used to give user programs a safe and regulated way to communicate with the underlying hardware and operating system-managed resources. This “interface” can provide many important things such as memory management, process management, I/O activities or so. 

Below, some of the most important system call types are listed along with their corresponding examples: 

Memory Management: 
malloc(): Allocates a block of memory from the heap. 
mmap(): Maps files or devices into memory. 

File Management: 
open(): Opens a file and returns a file descriptor for further operations. 
read(): Reads data from an open file descriptor into a buffer. 

Device Management: 
ioctl(): Performs I/O control operations on devices (e.g., setting device parameters). 
write(): Writes data from a buffer to a specified device. 

Information Maintenance: 
getpid(): Returns the process ID of the calling process. 
time(): Retrieves the current system time. 

Communication: 
socket(): Creates a new communication endpoint (socket) for network communication. 
send(): Sends data over a network socket.

    ❓️  Question 1.5.3 

-This program utilizes a fork() system call to create a new process, followed by an exec() system call to replace the child process with a new program. In the event of a successful fork and exec, the child process executes its code block, printing "Hello1", while the parent process waits for termination and prints "Hello3" after completion. If the fork fails, the program prints "Hello4". In case of a failed exec, the child process prints "Hello1" and "Hello2" before encountering the failed exec call, while the parent process still prints "Hello3" after waiting, resulting in a possible output sequence of "Hello1", "Hello2", "Hello3".
