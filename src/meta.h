#define SUBMISSION_WEEK 2
#define MULTITHREAD_WEEK 2
#define SYNC_WEEK 3
#define SOCKET_WEEK 4

//Transaction are almost atomic in this example. Transaction wait helps show race conditions caused by lack of mutex locks.
//Transaction wait increases the delay between read and write operation
#define TRANSACTION_WAIT 
#define TRANSACTION_WAIT_TIME 0.1
//#define VERBOSE

//Serial wait delays start after each thread by wait time. Its useful to differentiate the critical section waits from serial waits.
//Serial wait increases the delay before critical section
#define SERIAL_WAIT
#define SERIAL_WAIT_TIME 1