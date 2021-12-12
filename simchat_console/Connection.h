#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include <thread>

bool connecting_state = false;
void loadingAnimation();

class Connection
{
public:
	Connection(std::string ip, std::string port, std::string username);
	void ConnectIP();

	std::string ip_;
	std::string port_;
	std::string username_;

private:

	bool connected = false;

};

