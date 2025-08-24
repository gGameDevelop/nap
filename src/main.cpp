#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

const char* help =
"Output file content to the console\n"
"\n"
"Usage:\n"
"nap [COMMAND] ... [FILE] ...\n"
"\n"
"Commands:\n"
"  -v	--version           display version\n"
"  -h	--help              output this help dialog\n"
"  -n	--numbers           toggle line numbers";

int main(int argc, const char* argv[])
{
	bool numbers = false;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			if (*argv[i] == '-')
			{
				if (!strcmp(argv[i], "--version") || !strcmp(argv[i], "-v"))
				{
					std::cout << "nap 1.0.0" << std::endl;
					return 0;
				}
				else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h"))
				{
					std::cout << help << std::endl;
					return 0;
				}
				else if (!strcmp(argv[i], "--numbers") || !strcmp(argv[i], "-n"))
					numbers = true;
				else
				{
					std::cout << "nap: unknown command -- " << argv[i] << std::endl;
					std::cout << "Try 'nap --help' for more information." << std::endl;
					return 1;
				}
			}
			else
			{
				std::ifstream file(argv[i]);
				if (file)
				{
					std::string line;
					int number = 1;
					while (std::getline(file, line))
					{
						if (numbers)
							printf("%.3d| %s\n", number++, line.c_str());
						else
							printf("%s\n", line.c_str());
					}
				}
				else
				{
					std::cout << "nap: No such file with name: " << argv[i] << std::endl;
					return 1;
				}
			}
		}
	}

	return 0;
}
