#include <iostream>
#include <unistd.h>

using namespace std;

int main(void)
{
	char tmp[256];
	getcwd(tmp, 256);
	cout << "Directory: " << tmp << endl;
	return 0;
}
