#include "Application.hpp"
int main(int argc, char** argv) {
	AppMode mode;
	if (argc == 1) mode = AppTest;
	else {
		switch (argv[1][0]) {
		case 't':
			mode = AppTest; break;
		case 'r':
			mode = AppRandom; break;
		case 'c':
			mode = AppCustom; break;
		}
	}
	Application app(mode);
	return app.run();
}
