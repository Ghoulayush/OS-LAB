# Operating Systems Laboratory Programs

[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![OS](https://img.shields.io/badge/Subject-Operating%20Systems-green.svg)](https://en.wikipedia.org/wiki/Operating_system)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

A comprehensive collection of Operating Systems laboratory programs implemented in C. This repository contains practical implementations of fundamental OS concepts including process management, scheduling algorithms, inter-process communication, memory management, and synchronization.

## 📚 Table of Contents

- [Programs Overview](#programs-overview)
- [Prerequisites](#prerequisites)
- [Compilation & Execution](#compilation--execution)
- [Program Categories](#program-categories)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)

## 🖥️ Programs Overview

| Program | Description | Concepts Covered |
|---------|-------------|------------------|
| **P1forkcall.c** | Fork System Call | Process creation, Parent-Child relationship |
| **P2oddevenfork.c** | Odd-Even using Fork | Process synchronization, Fork implementation |
| **P3waitfinal.c** | Wait System Call | Process synchronization, Parent waiting |
| **P4zombie-orphan.c** | Zombie and Orphan Processes | Process states, Zombie/Orphan handling |
| **P5FCFS.c** | First Come First Serve Scheduling | CPU Scheduling, Non-preemptive algorithm |
| **P6sjf.c** | Shortest Job First Scheduling | CPU Scheduling, SJF algorithm |
| **P7PriorityScheduling.c** | Priority Scheduling with Gantt Chart | Preemptive/Non-preemptive priority scheduling |
| **P8PipeSystemCall.c** | Pipe System Call | Inter-process communication, Pipes |
| **P9.1NamedPipesReaderSide.c** | Named Pipes (Reader) | FIFO, Named pipe communication |
| **P9.2NamedPipesWriterSide.c** | Named Pipes (Writer) | FIFO, Named pipe communication |
| **P10Sharedmemory.c** | Shared Memory | IPC using shared memory segments |
| **P11PageAlgo.c** | Page Replacement Algorithm | Memory management, FIFO paging |
| **P12LRU.c** | LRU Page Replacement | Memory management, LRU algorithm |
| **P13.1msg_recv.c** | Message Queue (Receiver) | IPC using message queues |
| **P13.2msg_send.c** | Message Queue (Sender) | IPC using message queues |

## 🔧 Prerequisites

- **Operating System**: Linux/Unix-based system
- **Compiler**: GCC (GNU Compiler Collection)
- **Libraries**: Standard C libraries, POSIX libraries
- **Knowledge**: Basic understanding of Operating Systems concepts

### System Requirements
```bash
# Install GCC if not already installed
sudo apt update
sudo apt install gcc

# For some programs, you might need additional packages
sudo apt install build-essential
```

## 🚀 Compilation & Execution

### Individual Program Compilation
```bash
# Generic compilation command
gcc -o output_filename program_name.c

# Examples:
gcc -o fork P1forkcall.c
gcc -o fcfs P5FCFS.c
gcc -o priority P7PriorityScheduling.c
```

### Execution
```bash
# Run the compiled program
./output_filename

# Examples:
./fork
./fcfs
./priority
```

### Compilation with Debugging
```bash
# For debugging purposes
gcc -g -o program_name program_name.c
gdb ./program_name
```

## 📂 Program Categories

### 🔄 Process Management
- **P1forkcall.c**: Demonstrates process creation using fork()
- **P2oddevenfork.c**: Shows process coordination for odd-even number generation
- **P3waitfinal.c**: Implements parent-child synchronization using wait()
- **P4zombie-orphan.c**: Illustrates zombie and orphan process concepts

### ⏰ CPU Scheduling Algorithms
- **P5FCFS.c**: First Come First Serve scheduling implementation
- **P6sjf.c**: Shortest Job First scheduling with turnaround time calculation
- **P7PriorityScheduling.c**: Priority-based scheduling with Gantt chart visualization

### 📡 Inter-Process Communication (IPC)
- **P8PipeSystemCall.c**: Anonymous pipe communication between processes
- **P9.1 & P9.2**: Named pipes (FIFO) for bidirectional communication
- **P10Sharedmemory.c**: Shared memory segment implementation
- **P13.1 & P13.2**: Message queue-based communication

### 💾 Memory Management
- **P11PageAlgo.c**: FIFO page replacement algorithm with hit/miss tracking
- **P12LRU.c**: Least Recently Used page replacement algorithm

## ✨ Features

### 🎯 Interactive Programs
- User-friendly input/output interfaces
- Clear prompts and instructions
- Detailed result displays

### 📊 Comprehensive Output
- **Scheduling Programs**: 
  - Process details (PID, Arrival Time, Burst Time, etc.)
  - Average waiting time and turnaround time
  - Gantt charts for visualization

- **Memory Management**: 
  - Page hit/miss tracking
  - Frame status visualization
  - Hit ratio calculations

- **IPC Programs**: 
  - Message passing demonstrations
  - Synchronization examples
  - Error handling

### 🔧 Code Quality
- Well-commented code for educational purposes
- Modular function design
- Error handling and validation
- Dynamic memory allocation where applicable

## 🏃‍♂️ Quick Start Guide

1. **Clone the repository**
   ```bash
   git clone https://github.com/Ghoulayush/OS-LAB-.git
   cd OS-LAB-
   ```

2. **Compile and run a program**
   ```bash
   # Example: Running the priority scheduling program
   gcc -o priority P7PriorityScheduling.c
   ./priority
   ```

3. **Follow the on-screen prompts**
   - Enter the required input values
   - Observe the algorithm execution
   - Analyze the results

## 📝 Sample Runs

### Priority Scheduling Example
```
Enter number of processes: 3
Process 1:
Arrival Time: 0
Burst Time: 6
Priority (lower = higher priority): 2

Process 2:
Arrival Time: 2
Burst Time: 8
Priority (lower = higher priority): 1

Process 3:
Arrival Time: 1
Burst Time: 7
Priority (lower = higher priority): 3

Choose Scheduling Type:
1. Non-Preemptive Priority
2. Preemptive Priority
Enter choice: 1

=== Results with Gantt Chart ===
```

### Page Replacement Example
```
Enter number of frames: 3
Enter length of reference string: 7
Enter reference string: 7 0 1 2 0 3 0

Page 7: [ 7  -  - ] - MISS
Page 0: [ 7  0  - ] - MISS
Page 1: [ 7  0  1 ] - MISS
Page 2: [ 2  0  1 ] - MISS
Page 0: [ 2  0  1 ] - HIT
Page 3: [ 2  3  1 ] - MISS
Page 0: [ 0  3  1 ] - MISS

Total Page Faults: 6
Total Page Hits: 1
```

## 📖 Learning Objectives

After working with these programs, you will understand:

- **Process Management**: How processes are created, managed, and terminated
- **CPU Scheduling**: Different algorithms and their performance metrics
- **Inter-Process Communication**: Various IPC mechanisms and their use cases
- **Memory Management**: Paging algorithms and their efficiency
- **Synchronization**: How processes coordinate and communicate

## 🤝 Contributing

Contributions are welcome! If you'd like to add more OS programs or improve existing ones:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Contribution Guidelines
- Follow consistent coding style
- Add comprehensive comments
- Include sample input/output
- Update README if adding new programs

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Operating Systems course curriculum
- System programming references
- Open source community

## 📞 Contact

**Author**: Ayush Ramola  
**Section**: C (G1)  
**Roll Number**: 17

---

⭐ **Star this repository if you found it helpful!**

*Happy Learning! 🚀*