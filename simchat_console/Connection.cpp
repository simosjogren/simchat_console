#include "Connection.h"

// Establish a new connection address.
Connection::Connection(std::string ip, std::string port, std::string username) :
	ip_(ip), port_(port), username_(username)
{};

void Connection::ConnectIP() {
	std::thread animation(loadingAnimation);

	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOk = WSAStartup(ver, &wsData);

	animation.join();

	// If building fails.

	if (wsOk != 0) {
		connecting_state = false;
		system("CLS");
		std::cerr << "Winstock cannot be initialized!" << std::endl;
		return;
	}

	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		std::cerr << "Cant create socket." << std::endl;
		return;
	}

}

void loadingAnimation() {
	using namespace std::literals::chrono_literals;
	int itr = 0;
	while (connecting_state) {
		std::cout << "|   |" << std::endl;
		std::this_thread::sleep_for(0.25s);
		system("CLS");
		std::cout << "|-  |" << std::endl;
		std::this_thread::sleep_for(0.25s);
		system("CLS");
		std::cout << "|-- |" << std::endl;
		std::this_thread::sleep_for(0.25s);
		system("CLS");
		std::cout << "|---|" << std::endl;
		std::this_thread::sleep_for(0.25s);
		system("CLS");
	}
}
