#include <iostream>
#include <SFML/Network.hpp>

int main() {
	sf::UdpSocket socket;
	unsigned int pr = 54024;
	unsigned short int serverGet = 54020;
	std::optional ip = sf::IpAddress::getLocalAddress();
	std::vector<short unsigned int> portList;

	pr = 54024;
	int max=10;
	// GENIUS
	for(int i = 0; i < max; i++) {
	if(socket.bind(pr) != sf::Socket::Status::Done) {
		portList.push_back(pr);
	}
		pr++;
	}
	socket.unbind();
	std::string buf = "hi";
	size_t rec;
	char buff[100];
	char bf2[100];
	socket.setBlocking(false);
	while(1) {
		std::getline(std::cin, buf);
		if(buf == "newclient") {
			portList.clear();
	pr = 54024;
	// GENIUS
		for(int i = 0; i < max; i++) {
		if(socket.bind(pr) != sf::Socket::Status::Done) {
			portList.push_back(pr);
		}
			pr++;
		
	}

		}
		for(int i = 0; i < portList.size(); i++) {
			socket.send(buf.c_str(), buf.size(), ip.value(), portList.at(i));
		}

		/*std::optional ip = sf::IpAddress::getLocalAddress();
		socket.bind(serverGet);
		if(socket.receive(buff, sizeof(buf), rec, ip, serverGet) == sf::Socket::Status::Done) {

		for(int i = 0; i < rec; i++) {
			bf2[i] = buff[i];
			bf2[i+1] = '\0';
		}
		std::cout << bf2 << "\n";
		}
		*/

	}
}
