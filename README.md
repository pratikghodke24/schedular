# scheduler

For a given in-phase input task set consisting of periodic tasks, find Hyper-period and the best frame size possible and provide a periodic schedule per every frame. Store the table in a file named periodicSchedule.txt.

List of all files in the directory and a short description:

1. main.c : Driver file,takes input(period,WCET,deadline) from file(table.txt).
2. func.h : Header file consisitng of function definition.
3. hyperperiod.c : Used to calculate hyperperiod.
4. framesize.c : Used to findout frame size.If multiple frames sizes are eligible then largest frame size is considered.
5. createTable.c : Used to create a cyclic Scedule for periodic tasks and to generate a output file(periodicSchedule.txt).

Instructions to execute program : 

$ gcc createTable.c framesize.c -lm hyperperiod.c main.c -o main
$ ./main


Program Discription:

*Take input from file table.txt. table.txt format(period(int),WCET(float),deadline(int)). Store the inputs in arrays.
*Next, calculate hyperperiod.
*Then, calculate frame size using conditions:
		1.f>=max(e(i))
		2.hyperperiod/f
		3.2*f-gcd(p(i),f)<=d(i)
Consider largest frame size eligible.
*Using frame size calculated in last section generate periodicSchedule.txt.
format of periodicSchedule.txt (frame_number  slack_space  job(i)-starting_time-ending_time ----->same if more jobs are executing in frame)
