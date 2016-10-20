// 7.2 Imagine you have a call center with three levels of employees: fresher,
//     technical lead (TL), product manager (PM). There can be multiple 
//     employees, but only one TL or PM. An incoming telephone call must be 
//     allocated to a fresher who is free. If a fresher can't handle the call, 
//     he or she must escalate the call to technical lead. If the TL is not 
//     free or not able to handle it, then the call should be escalated to PM.
//     Design the classes and data structures for this problem. Implement a 
//     method get_call_handler().



// Solution

// All three ranks of employees have different work to be done, so those 
// specific functions are profile specific. We should keep these specific 
// things within their respective class.

// There are a few things which are common to them, like addresses, name, job 
// title, age, etc. These things can be kept in one class and can be extended 
// / inherited by others.

// Finally, there should be one CallHandler class which would route the calss 
// to the concerned person.

// ............................................................................
// Note: On any object oriented design question, there are many ways to design 
// the objects. Discuss the trade-offs of different solutions with your 
// interviewer. You should usually design for long term code flexibility and 
// maintainance.
// ............................................................................

#include <iostream>
#include <vector>
#include <queue>

#include <unistd.h>
#include <thread>

#include <ostream>
#include <sstream>
#include <mutex>
using namespace std;


class Logger {
public:
    // destructor is called when output is collected and
    // the temporary Logger() dies (after the ";").
    ~Logger() {
        Logger::mutex_.lock(); // make sure I am the only one writing
        std::cout << buffer_.str(); // write
        std::cout << std::flush; // push to output
        Logger::mutex_.unlock(); // I am done, now other threads can write
    }

    // funny construct you need to chain logs with "<<" like
    // in std::cout << "var = " << var;
    template <typename T>
    Logger &operator<<(T input) {
        buffer_ << input;
        return *this;
    }

private:
    // collect the output from chained << calls
    std::ostringstream buffer_;

    // mutex shared between all instances of Logger
    static std::mutex mutex_;
};

// define the static variable. This line must be in one .cpp file
std::mutex Logger::mutex_;


class Call
{
	int id = 1;
	int rank = 0; // minimal rank of employee who can handle this call

public:
	
	Call(int r, int i=0) : rank(r), id(i) {}

	void reply(string msg) {}

	void disconnect() {}

	int get_id()
	{
		return id;
	}

	int get_rank()
	{
		return rank;
	}

	void set_rank(int r)
	{
		rank = r;
	}
};


class CallHandler;


class Employee
{
	static CallHandler* call_handler;
	int rank; // 0 - fresher, 1 - techincal lead, 2 - product manager
	int id;
	mutex* mtx;

public:

	bool free;

	Employee(int r, int i) : rank(r), id(i), free(true)
	{
		mtx = new mutex();
	}

	bool is_free()
	{
		return free;
	}

	void set_busy()
	{
		mtx->lock();
		free = false;
		mtx->unlock();
	}

	void set_free()
	{
		mtx->lock();
		free = true;
		mtx->unlock();
	}

	int get_id()
	{
		return id;
	}

	int get_rank()
	{
		return rank;
	}

	void receive_call(Call* call)
	{
		Logger() << "Employee (id: " << id << ", rank: " << rank 
		         << ") dealing with call (id: " << call->get_id() << ", rank: " 
		         << call->get_rank() << ").\n";
		sleep(rand() % 3 + 1);
		call_handled(call);
	}

	void call_handled(Call* call)  // Call is complete
	{
		Logger() << "Employee (id: " << id << ", rank: " << rank
		         << ") done with call (id: " << call->get_id() << ", rank: " 
		         << call->get_rank() << ").\n";
		set_free();
	}

	void cannot_handle(Call* call);   // escalate call
};


class Fresher : public Employee
{
public:
	Fresher(int id) : Employee(0, id)
	{
	}
};


class TechLead : public Employee
{
public:
	TechLead(int id) : Employee(1, id)
	{
	}
};


class PM : public Employee
{
public:
	PM(int id) : Employee(2, id)
	{
	}
};


class CallHandler
{
	static const int levels = 3; // We have 3 levels of employees
	static const int num_freshers = 5; // We have 5 freshers
	static const int num_techlead = 3; // 
	static const int num_pm = 1;

	vector<vector<Employee*> >* employee_levels;
	vector<queue<Call*> >* call_queues;

	queue<thread*> workers;

public:
	CallHandler()
	{
		employee_levels = new vector<vector<Employee*> >(levels);

		employee_levels->push_back(vector<Employee*>());
		for(int i = 0; i < num_freshers; ++i)
			(*employee_levels)[0].push_back(new Fresher(i+1));

		employee_levels->push_back(vector<Employee*>());
		for(int i = 0; i < num_techlead; ++i)
			(*employee_levels)[1].push_back(new TechLead(i+1));

		employee_levels->push_back(vector<Employee*>());
		for(int i = 0; i < num_pm; ++i)
			(*employee_levels)[2].push_back(new PM(i+1));

		call_queues = new vector<queue<Call*> >(levels);
	}

	Employee* get_call_handler(Call*);

	void dispatch(Call* c)
	{
		thread* t = new thread(&CallHandler::dispatch_call, this, c);
		workers.push(t);
	}

	void check_queue()
	{
		while(true)
		{
			usleep(5000);
			for(int i = 0; i < levels; ++i)
			{
				if(!(*call_queues)[i].empty())
				{
					Call* c = (*call_queues)[i].front();
					(*call_queues)[i].pop();
					// Logger() << "Get call (id: " << c->get_id()
					// 	     << ", rank: " << c->get_rank() << ") from queue \n";
					dispatch(c);
				}
			}
		}
	}

	void do_work()
	{
		while(true)
		{
			usleep(5000);
			if(!workers.empty())
			{
				thread* t = workers.front();
				t->join();
				workers.pop();
			}
		}
	}

	// routes the call to an available employee, or adds to a queue
	void dispatch_call(Call*);

	void get_next_call(Employee* e)
	{
		// look for call for e's rank
		int rank = e->get_rank();
		if(!(*call_queues)[rank].empty())
		{
			Call* c = (*call_queues)[rank].front();
			(*call_queues)[rank].pop();
			dispatch(c);
		}
		Logger() << "Call queues for rank " << rank << " now empty.\n";
	}
};

void Employee::cannot_handle(Call* call)   // escalate call
{
	call->set_rank(rank + 1);
	call_handler->dispatch(call);
	set_free();
	call_handler->get_next_call(this); // looking for waiting call
}


Employee* CallHandler::get_call_handler(Call* call)
{
	for(int level = call->get_rank(); level < levels; ++level)
	{
		vector<Employee*> employee_level = (*employee_levels)[level];
		for(auto e : employee_level)
		{
			if(e->is_free())
			{
				e->set_busy();
				return e;
			}
		}
	}
	return NULL;
}

// routes the call to an available employee, or adds to a queue
void CallHandler::dispatch_call(Call* call)
{
	// Try to route the call to an employee with minimal rank
	// Logger() << "dispatching..." << '\n';

	Employee* emp = get_call_handler(call);

	if(emp != NULL)
	{
		Logger() << "Get employee (id: " << emp->get_id() 
	         << ", rank: " << emp->get_rank() << ").\n";
	}

	if(emp != NULL)
		emp->receive_call(call);
	else // Place the call into queue according to its rank
	{
		// Logger() << "No employee available, put the call in queue.\n";
		(*call_queues)[call->get_rank()].push(call);
	}
}


class CallCenter
{
	queue<Call*>* calls;
	static int handled_calls;
	CallHandler* call_handler;

public:

	CallCenter(CallHandler* ch) : call_handler(ch)
	{
		calls = new queue<Call*>();
	}

	Call* get_call()
	{
		if(!calls->empty())
		{
			Call* c = calls->front();
			calls->pop();
			return c;
		}
		Logger() << "No new calls available.\n";
		return NULL;
	}

	void add_call(Call* c)
	{
		calls->push(c);
	}

	bool has_calls()
	{
		return !(calls->empty());
	}

	void generate_rand_calls()
	{
		while(true)
		{
			sleep(1);
			srand(time(NULL));
			if(rand() % 10 > 4)
			{
				int rank = rand() % 3;
				Logger() << "Call id: " << ++handled_calls 
			         << ", rank: " << rank << '\n';
			    add_call(new Call(rank, handled_calls));
			}
		}
	}

	void check_calls()
	{
		while(true)
		{
			usleep(5000);
			if(!calls->empty())
			{
				Call* c = get_call();
				call_handler->dispatch(c);
			}
		}
	}
};

int CallCenter::handled_calls = 0;

CallHandler* CH = new CallHandler();

CallHandler* Employee::call_handler = CH;



int main()
{
	CallCenter cc(CH);

	thread* call_gen = new thread(&CallCenter::generate_rand_calls, &cc);
	thread* call_checker = new thread(&CallCenter::check_calls, &cc);

	thread* dispatcher = new thread(&CallHandler::do_work, CH);
	thread* queue_checker = new thread(&CallHandler::check_queue, CH);

	call_gen->join();
	call_checker->join();

	dispatcher->join();
	queue_checker->join();
	
	return 0;
}


// Note: this thing now works, but my computer gets hot..., maybe using thread
// is not a great idea, especially with a while(true), how could you do this 
// use interrupts instead?
// With sleep in each thread, the while(true) now stops hogging the CPU, but 
// not sure it's the best answer.













