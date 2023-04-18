# OS 期中共筆
# 考古題
:::spoiler 106
https://moptt.tw/p/NTU-Exam.M.1530812862.A.148?fbclid=IwAR2AOBMl-OL3Gil3IMHIoSZiFBhjeA42uNp7KtL9_VAEcaMIwKJMsTYnzus
:::
:::spoiler 104
https://www.ptt.cc/bbs/b04902xxx/M.1493626843.A.E8F.html
:::
:::spoiler 103
ptt.cc/bbs/b04902xxx/M.1493626830.A.20B.html
:::
:::spoiler 102
https://www.ptt.cc/bbs/b04902xxx/M.1493626789.A.684.html
:::
:::spoiler 101
https://www.ptt.cc/man/NTU-Exam/DE0A/D245/D298/DE44/D23E/D8BD/M.1418816812.A.01A.html
:::
:::spoiler 100
https://www.ptt.cc/bbs/NTU-Exam/M.1335413893.A.32B.html
:::
# Solution to Term Definition:
:::spoiler **Implicit Threading**
Transfer the creation and management of the threading from the application developers to compilers and run-time libraries.
e.g. OpenMP, Intel API, 
:::
:::spoiler **Context Switch**
Save the state of the old process and load the state of the newly scheduled process. The state is saved in PCB. Pure overhead.
:::
::: spoiler  **FIFOS of UNIX**
Named pipes of UNIX. It is a file in the file system and created by mkfifo(). It offers Half Dulex and Byte-Oriented Transmissions.
:::
::: spoiler **Memory Protection (Hint: Hardware Protection)**
Prevent a user program from modifying the code or data structures of either the OS or other users!
:::
:::spoiler Operating System
* User view: many POV: e.g. ease of use, interaction, or no user view(embedded system)
* System view: resource allocator, control program
:::
:::spoiler Hardware interrupt
Triggered by sending a signal to the CPU, who stops immediately and transferes execution to a fixed location (interrupt handler)
:::
::: spoiler Software interrupt (aka **trap** into system)
A specific request from a user program that an operating-system service be performed by executing **system call**.
i.e. **System call can trap into system.**
:::
::: spoiler Dual-Mode
Kernel and user-mode instructions, where privileged instructions are machine instructions that may cause harm.
:::
::: spoiler A Modular Kernel
A set of core components with characteristics: layer-like - modules; microkernel-like - the primary module.
:::
::: spoiler Computing Environments includes
Traditional, Mobile, Client-server, P2P, Cloud computing(SaaS, PaaS, IaaS), Real-time embedded system
:::
::: spoiler Process vs program

| Process | Program| 
| :--------: | :--------: | 
| Active     | Passive   |
:::
::: spoiler Process Control Block (PCB) includes
* Process state
* PID
* Program counter: address of the next instruction to be executed
* CPU register
* CPU scheduling info: priority, queue pointers, etc.
* various info (IO, CPU, usage, etc.)
:::
::: spoiler Thread Control Block (TCB) includes
* TID
* Program counter
* Register set
* stack
* shared: code, data, other resources
:::
::: spoiler degree of multiprogramming
The number of process currently in memory.
:::
::: spoiler Cascading termination:
If a process terminates, then all its children must also be terminated.
:::
::: spoiler Why zombie state?
Without this state, the termination status may loss.x
:::
::: spoiler Remote Procedure Call
RPC abstracts the procedure-call mechanism between systems with network connections without knowing the implementation behind.
:::
::: spoiler Multiprogramming
We want to run many programs at the same time
:::
# Chapter 1
### Interrupt 

# Chapter 2
### Computation modes:
1. **Batch mode**: *one process needs to be completed ASAP.*
    * *Performance metrics*: Completion time per process.
    * *Resource allocation policy*: Allocate enough resources before the process starts in order to reduce execution time. 
    * *Goal*: Efficiency
3. **Online mode/interactive mode**:
    * *Performance metrics*: Throughput.
    * *RA policy*: Fair sharing of resources. No process should occupy CPU/memory for too long. 
    * *Goal*: Responsiveness
5. **Real-time mode**:
    * *Performance metrics*: Tardiness.
    * *RA policy*: Guarantee resources for each running process at all time for consistent result.
    * *Goal*: Predictability 
### Operating System Structure
*	Monolithic Structure
	*	把所有東西喇成一個 kernel
	*	優點：簡單，performance 很好
	*	缺點：難以維護和擴展
	*	Known as a tightly-coupled system(changes to one part can have wide-ranging effects on other parts)
*	Layered Approach
	![](https://i.imgur.com/HQQnLIl.png)

	*	loosely coupled system
	*	operating system is broken into a number of layers(layer 0 is hardware, while the highest layer is user interface)
	*	優點：簡化 debugging and system verification(有點像網路架構，每層都只 call 他上一層的函式)
*	Microkernels
	![](https://i.imgur.com/Zn4yyDd.png)

	*	Mach, mid-1980s
	*	provide communication between the client program and various services
	*	優點：可延伸性高，高安全性及可靠性
	*   例子：Darwin, QNX	
*	Modules
	*	loadable kernel modules(LKMs)
	*	LKMs is inserted into kernel when system booting
*	Hybrid System
	*	Linux: monolithic and modular
	*	Windows: monolithic and some behaviors of microkernel(ex. providing support for separate subsystems, known as operating-system personalities) and LKMs
	*	macOS and iOS
	*	Android
*   Booting: 
	*   bootstrap program(boot loader) locates the kernel
		1.   Boot loader located in nonvolatile firmware aka **BIOS** load a second boot loader.
		2.   Boot loader(must fit in a single disk block) located at a fixed disk location called **boot block** loads the entire operating system into memory and begin its execution
	*   UEFI(Unified Extensible Firmware Interface) vs. BIOS-based 
		*   better support for 64-bit system and larger disk
		*   single complete boot manager, which is faster than multistage BIOS boot process
	*   kernel is loaded into memory and started
	*   kernel initializes hardware
	*   root file system is mounted
	*   GRUB 
		*   a open-source bootstrap for Linux and UNIX system
		*   Boot parameters for the system are set in a GRUB configuration file
	*   recovery mode and single-user mode
	*   BCC(BPF Compiler Collection)
### OS for distributed systems:
1. _**NOS(network OS)**_: Loosely-coupled OS for heterogeneous multicomputers
    * **Goal**: offer local services to remote clients. 
2. _**DOS(distributed OS)**_: Tightly-coupled OS for multi-processors and homogeneous multicomputers
    * **Goal**: hide and manage hardware resources.
3. _**Middleware**_: Additional layer atop of NOS implementing general purpose services
    * **Goal**: provide distribution transparency.
# Chapter 3 Process
*	A program is a passive entity, while a process is an active entity
![](https://i.imgur.com/Fi0hvHG.png)
*	Process state
	*	New
	*	Running 
	*	Waiting
	*	Ready
		![](https://i.imgur.com/VpSaQX7.png)
*	Process Control Block(PCB, task control block)
	*	include
		*	Process state
		*	Program counter
		*	CPU registers
		*	CPU-scheduling information
		*	Memory-management information
		*	Accounting information
		*	I/O status information
*	Degree of multiprogramming
	*	the number of processes currently in memory.
*	I/O-bound process
	*	spend more of time doing I/O than doing computations
*	CPU-bound process
	*	using more of its time doing computations
*	Dispatch
	*	A process in ready queue is selected for execution
	![](https://i.imgur.com/bzx7Qd1.png)
	![](https://i.imgur.com/0XSpW75.png)
*	Swapping
	*	remove a process from memory and thus reduce the degree of multiprogramming
	*	a process can be “swapped out” from memory to disk
	*   only necessary when memory has been overcommitted and must be freed up.
	*   More discussion in Chapter 9
*   Context Switch
	*   requires performing a state save of the current process and a state restore of a different process
	![](https://i.imgur.com/fUEuTlX.png)
*	Process Creation
	*	Two possibilities for parent process after creating a child process
		1. continues to execute concurrently with its children
		2. waits until some or all of its children have terminated
	*	Two possibilities for child process 
		1. being a duplicate of the parent process (it has the same program and data as the parent)
		2. has a new program loaded into it

![](https://i.imgur.com/nDS6FnO.png)
*	Cascading Termination
	*	In some systems, if a process terminates, all of its children must be terminated
*	Zombie process
	*	A process that has terminated, but whose parent has not yet called wait()
*	Orphan process
	*	whose parent did not invoke wait() and instead terminated
*   Interprocess Communication
	*   Reasons
		*   Information sharing
		*   Computation speedup
		*   Modularity
	*   Methods
		*   Shared memory
		*   Message passing
		   ![](https://i.imgur.com/PAIxj0A.png)
	*   Shared Memory 
		*   Produer
			*   produce information
		*   Consumer
			*   consume information
		*   Buffers
			*   unbounded buffer
				*   no practical limit on the size of the buffer
			*   bounded buffer
				*	assume a fixed buffer size
	*	Message Passing
		*	Direct vs. indirect
			*	Direct
				*	must explicitly name the recipient or sender of the communication
			*	Indirect
				*	messages are sent to and received from mailboxes or ports
		*	Synchronous vs. Asynchronous
			*	blocking vs. non-blocking
			*	rendezvous between sender and receiver when blocking
		*	Buffering
			*	Zero capacity
				*	block
			*	bounded capacity
			*	unbounded capacity
				*	never block
	*	anonymous pipe
	*	named pipe
	*	socket
		*	an endpoint for communication
		*	TCP(Connection oriented) vs. UDP(Connectionless)
		*	127.0.0.1: loopback
			*	When a computer refers to IP address 127.0.0.1, it is referring to itself.
	*	Remote Procedure Calls
		*	stub
			*	provided on client side
			*	When the client invokes a remote procedure, the RPC system calls the appropriate stub, passing it the parameters provided to the remote procedure.
		*	marshals
			*	stub 序列化 RPC 的參數
		*	how does a client know the port numbers on the server?
			1.   binding information may be predetermined, in the form of fixed port addresses.
			2.   binding can be done dynamically by a rendezvous mechanism. An operating system provides a rendezvous (also called a matchmaker) daemonon a fixed RPC port
	   
# Chapter 4 Threads
![](https://i.imgur.com/tGzOcZ2.png)
*	Benefits
	*	Responsiveness
	*	Resource sharing
	*	Economy
	*	Scalability
*	Amdahl's law
	*	$speedup \leq \frac{1}{S + \frac{(1 - S)}{N}}$
		![](https://i.imgur.com/YindqtZ.png)
*	Programming Challenges
	*	Identifying tasks
	*	Balance
	*	Data splitting
	*	Data dependency
	*	Testing and debugging
*	Data Parallelism vs. Task Parallelism
	*	Data Parallelism
		*	focus on distributing subsets of the same data across multiple computing cores and performing the same operation on each core.
	*	Task Parallelism
		*	involves distributing not data but tasks (threads) across multiple computing cores.
		![](https://i.imgur.com/gvI3ZA8.png)
*	Multithreading Models
	*	Many-to-one Model
		*	Green threads
			*	a thread library available for Solaris using many-to-one model
			![](https://i.imgur.com/45EBP4J.png)
	*	one-to-one model
		![](https://i.imgur.com/pjs5MZ6.png)
	*	many-to-many model
		*	two-level model
		![](https://i.imgur.com/5ck7dsv.png)
*	Threading Library
	*	Pthreads(系程用過)
*	Implicit Threading(重要，打星星)
	*	better support the design of concurrentand parallel applications is to transfer the creation and management of threading from application developers to compilers and run-time libraries.
*	Thread pools
	*	create a number of threads at start-up and place them into a pool
	*	benefits
		*	Servicing a request with an existing thread is often faster than waiting to create a thread
		*	Separating the task to be performed from the mechanics of creating the task allows us to use different strategies for running the task. For example,the task could be scheduled to execute after a time delay or to execute periodically.
*	Fork-join model
	*	the main parent thread creates(forks) one or more child threads and then waits for the children to terminate and join with it
*	OpenMP
	*	identifies parallel regions
*	Grand Central Dispatch(GCD)
	*	dispatch queue
		*	serial
			*	FIFO order
			*	each process has its own serial queue(known as its **main queue**)
		*	concurrent
*	Thread Cancellation
	*	the thread is to be canceled is referred to as **target thread**
	*	Asynchronous cancellation
		*	the target thread is terminated immediately
	*	Deferred cancellation
		*	the target thread periodically check whether is should terminate
	*	cancellation point
	*	cleanup handler
*	Thread-local storage(TLS)
	*	in some circumstances, each thread might need its own copy of certain data
*   Scheduler Activation
	*   lightweight process(LWP)
		*   intermediate data structure between user and kernel threads
		*   each LWP is attached to a kernel thread
	*   The kernel provides an application with a set of virtual processors (LWPs) 
	*   upcall
		*   application schedule user threads onto an available virtual processor. Furthermore, the kernel must inform an application about certain events
		*   upcall handler
		![](https://i.imgur.com/YHqbLIy.png)
# Chapter 9 Main Memory
*	stall
	*	CPU doesn't have the data required to complete instruction that it is executing(我不太確定，有人知道更正一下)
	*	CPU在等所有需要的資料從Memory進來的狀態，有cache的話就會比較短
*	cache
*	base register
	*	hold the smallest legal physical memory address
*	limit register 
	*	specifies the size of the range
	![](https://i.imgur.com/6L5Vmrk.png)
*	Address binding
	*	Can be finished along
		*	Compile time
			*	absolute code can be generated
		*	Load time
			*	relocatable code
			*	binding is delayed until load time
			*	If the starting address changes, we need only reload the user code to incorporate this changed value
		*	Execution time
			*	the process can be moved during its execution from one memory segment to another
			*	Special hardware must be available for this scheme to work
			![](https://i.imgur.com/f8cg7af.png)
	
*   logical address
	*   address generated by CPU
*	physical address
	*	the one loaded into **memory-address register**
	*	address seen by the memory unit
*	memory-management unit(MMU)
    *	Hardware device performing run-time mapping from virtual to physical addresses
	*	The base register is called a relocation register.
    ![](https://i.imgur.com/I3a2OAm.png)
	![](https://i.imgur.com/o5GJS33.png)
*	Dynamic Loading
	*	a routine is not loaded until it is called
*	Dynamic Linking and Shared Library
	*	Dynamically linked libraries (DLLs)
		*	system libraries that are linked to user programs when the programs are run
	*	vs. static linking
*	Contiguous Memory Allocation
	*	each process is contained in a single section of memory that is contiguous to the section containing the next process
*	Memory Protection
	*	the dispatcher loads the relocation and limit registers with the correct values as part of the context switch.
	![](https://i.imgur.com/FPqVLz8.png)
*	Memory Allocation
	*	variable-partition scheme
		*    assign processes to variably sized partitions in memory, where each partition may contain exactly one process
		*    operating system keeps a table indicating which parts of memory are available and which are occupied
		*    memory contains a set of holes of various sizes
		    ![](https://i.imgur.com/p9ywq7v.png)
	*	hole
	*	dynamic storage allocation problem
		*	First-fit
			*	Allocate the first hole that is big enough
			*	Searching can start either at the beginning of the set of holes or at the location where the previous first-fit search ended
			*	stop searching as soon as we find a free hole that is large enough
		*	Best-fit
			*	Allocate the smallest hole that is big enough
			*	search the entire list, unless the list is ordered by size
			*	produces the smallest leftover hole
		*	Worst-fit
			*	Allocate the largest hole
			*	search the entire list, unless it is sorted by size
			*	produces the largest leftover hole
*   Fragmentation
	*   external fragmentation
		*   first-fit and best-fit suffer from it
		*   there is enough total memory space to satisfy a request but the available spaces are not contiguous
		*   No matter which algorithm is used, however, external fragmentation will be a problem
		*   Solution
			*    compaction
				*   shuffle the memory contents so as to place all free memory together in one large block
				*   is not always possible
				*   expensive
			*	permit the logical address space of processes to be noncontiguous
				*	paging
	*   50-percent rule
		*   given N allocated blocks, another 0.5 N blocks will be lost to fragmentation
	*   internal fragmentation
		*   unused memory that is internal to a partition
*   Paging
	*   memory management scheme that permits a process’s physical address space to be noncontiguous
	*   implemented through cooperation between the operating system and the computer hardware
	*   breaking physical memory into fixed-sized blocks called frames
	*   breaking logical memory into blocks of the same size called pages
	*   a process can have a logical 64-bit address space even though the system has less than $2^{64}$ bytes of physical memory
	*   Every address generated by the CPU is divided into page number (p) and page offset (d)
		![](https://i.imgur.com/FimLTPM.png)
	*   Page number is used as an index into a per-process **page table**
	*   MMU translate a logical address to a physical address
		*   Extract the page number p and use it as an index into the page table
		*   Extract the corresponding frame number f fromthe page table
		*   Replace the page number p in the logical address with the frame number f
		*   Notice that offset d didn't change
		![](https://i.imgur.com/STSTf4w.png)
	*   page size
		*   defined by the hardware
		*   a power of 2
		*   typically varying between 4 KB and 1 GB per page
	*   overhead is involved in each pagetable entry
	*   huge pages
		*   優點：low overhead
		*   缺點：more internal fragmentation
	*	frame table
		*	one entry for each physical page frame 
			*    whether the latter is free or allocated
			*    if it is allocated, to which page of which process
	*	缺點：increases the context-switch time
	*	page-table base register(PTBR)
		*	Changing page tables requires changing only this one register, substantially reducing context-switch time
	*	Translation Look-Aside Buffer(TLB)
		*	page table result in slower memory access times
		*	a special, small, fast-lookup hardware cache
		*	Component
			*	a key(or tag)
			 			*	a value

 			![](https://i.imgur.com/XO7vbFr.png)
 		*	TLB miss
 			*	a page number is not in the TLB
 		*	Replacement Policy when TLB is already full
 			*	least recently used(LRU)
 			*	round-robin
 			*	random
 		*	wired down
 			*	some TLB entries cannot be removed from the TLB
 		*	address-space identifier (ASIDs)
 			*	identifies each process
 			*	provide address-space protection for that process
 			*	When the TLB attempts to resolve virtual page numbers, it ensures that the ASID for the currently running process matches the ASID associated with the virtual page
 			*	TLB must be flushed(erased) if not support ASIDs
 		*	hit ratio
 			*	the page number of interest is found in the TLB
 		*	effective memory-access time(EAT，重要重要，打星星)
 			*	memory-access time 的期望值
 			*	hit ratio * memory-access time if the page is in TLB + (1 - hit ratio) * memory-access time if the page is not in TLB
 	*	Protection
 		*	valid-invalid bit
 			*	attached to each entry in the page table
 		*   page-table length register (PTLR)
 			*	indicate the size of the page table
 	*	Shared Pages
 		*	reentrant code can be shared
 	*	Page table
 		*	Hierarchical Paging
 			*	two-level paging
 				*	forward-mapped page table
 				![](https://i.imgur.com/zKeHpSc.png)
 				![](https://i.imgur.com/s0NXrH5.png)
 		*	Hashed Page Tables
 			*	clustered page tables
 				*	a variation of Hashed Page Tables
 				*	each entry in the hash table refers to several pages (such as 16)
 				*	particularly useful for sparse address spaces
 			![](https://i.imgur.com/foOR5jN.png)	
 		*	Inverted Page Tables
 			*	has one entry for each real page(or frame) of memory
 			*	Each entry consists of the virtual address of the page stored in that real memory
 			*	only one page table is in the system, and it has only one entry for each page of physical memory
 			![](https://i.imgur.com/aOALFVP.png)
*	Swapping
	*	process, or a portion of a process, be swapped temporarily out of memory to a backing store and then brought back into memory for continued execution
		![](https://i.imgur.com/VFkyIBt.png)
	*	
	*	makes it possible for the total physical address space of all processes to exceed the real physical memory of the system
	*	increasing the degree of multiprogramming
	*	backing store 
		*	commonly fast secondary storage
		*	must be large enough to accommodate
	*	page out
		*	moves a page from memory to the backing store
	*	page in
		![](https://i.imgur.com/dV77Lfo.png)
	*	IA-32 Architecture(這個上課有講嗎?)、x86_64

# Chapter 10 Virtual Memory
*	involves the separation of logical memory as perceived by developers from physical memory
![](https://i.imgur.com/05bDqcn.png)
*	Demand Paging
	![](https://i.imgur.com/KvAz8CJ.png)
	*	pages are loaded only when they are demanded during program execution
		1.   check internal table (usually kept with the process control block) for this process to determine whether the reference was a valid or an invalid memory access.
		2.   If the reference was invalid, terminate the process. If it was valid but have not yet brought in that page, page it in.
		3.   find a free frame
		4.   schedule a secondary storage operation to read the desired page into the newly allocated frame
		5.   When the storage read is complete,we modify the internal table kept with the process and the page table to indicate that the page is now in memory
		6.   restart the instruction that was interrupted by the trap. The process can now access the page as though it had always been in memory
		![](https://i.imgur.com/Bhpstll.png)
	*	page fault
	*	pure demand paging
		*	each process starts with no page
		*	never bring a page into memory until it is required
	*	locality of reference
		*	some programs could access several new pages of memory with each instruction execution (one page for the instruction and many for data), possibly causing multiple page faults per instruction
		*	the scenario above is unlikely to happen since locality of reference
*	Free-frame list
	*	a pool of free frames
	*	zero-fill-on-demand
	*	At some point, the list either falls to zero or falls below a certain threshold, atwhich point it must be repopulated
*	Performance of demand paging(重要，打一顆星星太陽月亮)
	*	Let p be the probability of a page fault(being close to 0), ma be the memory-access time
	*	effective access time = (1 − p) × ma + p × page fault time
	*	the effective access time is directly proportional to the **page-fault rate**
	*	limit the amount of swap space used through demand paging of binary executable files
		*	the file system itself serves as the backing store. However, swap space must still be used for pages not associated with a file (known as anonymous memory)
*	Copy-on-write
	![](https://i.imgur.com/TO8BSnV.png)
*	Page Replacement
	*	Since memory over-allocating
	*	if no frames are free, two page transfers (one for the page-out and one for the page-in) are required
	*	modify bit(dirty bit)
	![](https://i.imgur.com/2NlppoE.png)
	*	page-replacement algorithm
		*	FIFO(First in first out)
			![](https://i.imgur.com/rOKhJEe.png)
			*	Belady’s anomaly
				*	for some page-replacement algorithms, the page-fault rate may increase as the number of allocated frames increases
		*	LRU(least recently used)
			*	implementations
				*	Counter
				*	Stack
			*	stack algorithms
				*	never exhibit Belady’s anomaly
		*	LRU-Approximation(least recently used)
			*	Reference Bit
				*	set by the hardwarewhenever that page is referenced(either a read or a write to any byte in the page)
				*	只有一個Reference Bit
				*	每Reference到一個Page就把該Bits改成1
				*	一段時間後再統一改回0
				*	缺點: 沒辦法區分Page們戳過的順序
			* Additional-Reference-Bit:
				*	對每個Page都附加多一點Bits
				*	每Reference到一個Page就把這些Bits裡面最左邊的改成1
				*	每一段時間就把這些Bits右移
				*	>越左邊有1-bit的話它就在越近時被戳過
			* Second Chance Algorithm
				*	不考慮Dirty-Bit的Enhanced Second Chance Algorithm
			* Enhanced Second Chance Algorithm
				*	考慮一個(Reference-Bit, Dirty-Bit)數對，若某個Page被戳到則Reference-Bit = 1，用一個Circular Linked List串接所有Pages，一個一個檢查他們的Bits狀態，(0,0)是最適合被swap掉的，(0,1)/(1,0)次之，(1,1)最不適合，而如果試Swap某個Page時 它的Reference-Bit為1，則給它Second Chance: Reference-Bit重設為0
	*	Counting-Based Page Replacement
		*	least frequently used(LFU)
			*	the page with the smallest count be replaced
		*	most frequently used(MFU)
			*	page with the smallest count was probably just brought in and has yet to be used.
	*	Page-Buffering Algorithms
		*	maintain a list ofmodified pages. Whenever the paging device is idle, a modified page is selected and is written to secondary storage and reset its dirty bit
		*	increase the probability that a page will be clean
	*	raw disk	
	*	frame-allocation algorithm 
		*	equal allocation
		*	proportional allocation
			*	$a_i = s_i/S * m(\text{the number of frames})$
		*	global vs. local
			*	global
				*	reapers
					*	kernel routine is triggered that begins reclaiming pages from all processes in the system
				*	out-of-memory(OOM) killer 
					*	selects a process to terminate when the amount of free memory falls to very low levels
	*	major page fault
		*	a page is referenced and the page is not in memory.
	*	minor page fault
		*	a process does not have a logical mapping to a page, yet that page is in memory.
		*	Reasons
			1.   process may reference a shared library that is in memory, but the process does not have a mapping to it in its page table
			2.   a page is reclaimed from a process and placed on the free-frame list, but the page has not yet been zeroed out and allocated to another process
*   non-uniform memory access (NUMA)
	*   scheduler must track the last CPU on which each process ran
	![](https://i.imgur.com/lhuSlej.png)

*	Thrashing
	*	A process is thrashing if it is spending more time paging than executing
		![](https://i.imgur.com/CpxlORd.png)
	*	solution
		*	local replacement algorithm(priority replacement algorithm)
		*	locality model of process execution
			*	looking at how many frames a process is actually using
		*	working-set model
			*	working-set window defined by a parameter $\Delta$
			*	working set
				*	The set of pages in the most recent Δ page references
				![](https://i.imgur.com/lG03q8i.png)
		*	page-fault frequency(PFF)
			*	If the actual page-fault rate exceeds the upper limit, we allocate the process another frame
			*	If the page-fault rate falls below the lower limit, we remove a frame from the process
			![](https://i.imgur.com/bFEGUfo.png)
		*	implementing a computer system is to include enough physical memory
*	Memory compression
	*	compression ratio
*	Allocating Kernel Memory
	*	Buddy System
		*	可以想成動態開點線段樹(還會動態刪點)
		*	power-of-2 allocator
		*	coalescing
		![](https://i.imgur.com/oIDVapE.png)
	*	Slab Allocation
		*	slab
			*	made up of one or more physically contiguous pages
			*	states
				*	Full
				*	Empty
				*	Partial
			*	benefit
				*	No memory is wasted due to fragmentation. Fragmentation is not an issue because each unique kernel data structure has an associated cache,and each cache is made up of one or more slabs that are divided into chunks the size of the objects being represented. Thus, when the kernel requests memory for an object, the slab allocator returns the exact amount of memory required to represent the object
				*	Memory requests can be satisfied quickly. The slab allocation scheme is thus particularly effective for managing memory when objects are frequently allocated and deallocated, as is often the case with requests from the kernel. The act of allocating—and releasing—memory can be a timeconsuming process. However, objects are created in advance and thus can be quickly allocated from the cache. Furthermore, when the kernel has finished with an object and releases it, it is marked as free and returned to its cache, thusmaking it immediately available for subsequent requests from the kernel.
				![](https://i.imgur.com/64iNhx2.png)
	
*	Prepaging
	*	Assume s pages are prepaged and a fraction α of these s pages is actually used (0 ≤ α ≤ 1)
	*	page faults is greater or less than the cost of prepaging s * (1 − α) unnecessary pages
*	TLB reach
*	I/O Interlock and Page Locking
# Chapter 12 I/O systems
*	I/O hardware
	*	bus
		*	PCIe bus (the common PC system bus)
		*	Expansion bus(for slower devices, eg: USB)
		*	serial-attached SCSI (SAS)
	*	daisy chain
	*	fibr channel (FC)
	*	host bus adapter (HBA)
	![](https://i.imgur.com/pHf0OnQ.png)
*	Memory-Mapped I/O
	*	記得施吉昇喜歡吃自助餐
	*	data-in register
	*	data-out register
	*	status register
	*	control register
*	Polling(busy-waiting)
*	Interrupt
	*	interrupt-handler routine
	*	interrupt-request line
	*	non-maskable vs. maskable
	*	interrupt chaining
	![](https://i.imgur.com/eVGyJAn.png)
	*	interrupt priority levels
	*	first-level interrupt handler (FLIH), a second-levelinterrupt handler (SLIH)
*	Direct Memory Access(DMA)
	*	scatter–gather method
	*	Handshaking between the DMA controller and the device controller is performed via a pair of wires called DMA-request and DMA-acknowledge
	*	cycle stealing
	![](https://i.imgur.com/M0St2pl.png)
	*	direct virtual memory access (DVMA)



https://codex.cs.yale.edu/avi/os-book/OS10/practice-exercises/index-solu.html

### 沒有用的 notion 
## 跟 ppt 有略差 有剪短一些
## CH9, 10, 12
https://www.notion.so/OS-NOTE-c862dca83b7b48e2b651dc0ad8197d61
## Google到的127的整理CH1~4
https://hackmd.io/@UfWSs_8kTqyZLyWWpPPq_g/Hk0G3iRCG/https%3A%2F%2Fwww.ptt.cc%2Fbbs%2Fb04902xxx%2FM.1493626830.A.20B.html