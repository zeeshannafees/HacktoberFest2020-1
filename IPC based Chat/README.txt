IPC based Chat App 
(Submitted by - Arghya Biswas for HacktoberFest 2020)


Simple chat apps using IPC in C using libraries ipc, msg and time.

Run both the programs(arghya.c and friend.c) in a folder simultaneously to chat between them. Sending a '*' would disconnect sender from chat and save the chat as a text file in the root directory. Please change the key to a new value before running the program each time.

Modules and features implemented:
- Message Passing
	1. Chat between 'Arghya' and 'Friend'
	2. Each chat is sent with timestamp of the sender
	3. When quit by sending '*', save chats with timestamp as text file logarghya.txt/logfriend.txt
- Shared Memory 
	1. Chat between 'Arghya' and 'Friend'
	2. Each chat is sent with timestamp of the sender
	3. Could NOT implement saving chats as text file