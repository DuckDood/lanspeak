#include <iostream>
#include <SFML/Network.hpp>
#include <thread>


int main() {
	sf::UdpSocket socket;
	//std::optional ip = sf::IpAddress::getLocalAddress();
	std::optional ip = sf::IpAddress::Broadcast;
	unsigned short pr = 54024;
	unsigned int serverGet = 54020;

	while(socket.bind(pr) != sf::Socket::Status::Done) {
		pr++;
	}
	std::cout << pr << "\n";
	size_t rec;
	char buf[100];
	char buf2[100];
	std::string buff3;
	char message[100] = "Hello";
	int x, y;
	
	socket.setBlocking(false);
	while(1){
		sf::Socket::Status s = socket.receive(buf, sizeof(buf), rec, ip, pr);


		for(int i = 0; i < rec; i++) {
			buf2[i] = buf[i];
			buf2[i+1] = '\0';
		}
		
		//if(buff3 != buf2) {
		if(s == sf::Socket::Status::Done) {
		buff3 = buf2;
		std::cout << buf2 << "\n";
		//socket.send("hi", 3, ip.value(), serverGet);
		}
		}
}
