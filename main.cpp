#include <iostream>
#include <memory>
#include <string>

namespace std
{
	template<typename T, typename ... Args>
	std::unique_ptr<T> make_unique(Args&& ... args)
	{
		return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}
}

class command
{
	public:
	virtual void execute() = 0; //ew. paramsy
	virtual ~command() = default;
};

class exit_command
	: public command
{
	public:
	
	virtual void execute() override
	{
		exit(0);
	}
};

class command_factory
{
	public:
	
	using ptr = std::unique_ptr<command>;

	ptr construct(const std::string& commandline)
	{
		(void)commandline;
		if(commandline == "exit") return std::make_unique<exit_command>();
		return nullptr;
	}
};

int main()
{	
	std::string line;
	command_factory cf;
	while(std::cin >> line)
	{
		std::cout << line << '\n';
		std::unique_ptr<command> cmd(cf.construct(line));
		if(!cmd)
		{
			std::cout << "There is no such command\n";
			continue;
		}
		cmd->execute();
	}	
}
