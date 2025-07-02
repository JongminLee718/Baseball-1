#include <stdexcept>

using namespace std;
class Baseball {
public:
	void guess(const string &str) {
		if (str.length() != 3) {
			throw length_error("must be three letters");
		}
	}
};