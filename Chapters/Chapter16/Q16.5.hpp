#include <string>

class MyatoiHex{
private:
	const std::string & str;
	int result = 0;
public:
	MyatoiHex();
	MyatoiHex(const std::string & str);
	int myatoiHex();
	int atoiHexFromsstream();
};
