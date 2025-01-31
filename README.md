# philosophers
The Philosophers project is part of the curriculum at 42, designed to introduce students to multithreading, process synchronization, and concurrency issues using the dining philosophers problem.

In this project, a group of philosophers sits around a table, each with a plate of spaghetti and two forks. They must alternate between thinking, eating, and sleeping, but they can only eat if they have both forks. The challenge is to prevent deadlocks and race conditions while ensuring that every philosopher eats properly.

Objectives:
	* Understand and implement threads with pthread;
	* Use mutexes to handle shared resources;
	* Avoid deadlocks and data races;
	* Manage thread synchronization efficiently.
	
Key Features:
Each philosopher follows a routine:
🧠 Thinking → 🍝 Eating → 😴 Sleeping
	* Uses mutexes to control fork access;
	* A monitor thread ensures that no philosopher starves;
	* Supports an optional meal limit, terminating when all philosophers have eaten enough.
	
Compilation:
	git clone https://github.com/Kupesa26/philosophers.git
	cd philosophers
	make
	./philo <num_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
		ex.: ./philo 5 800 200 200


