#include <stdexcept>

using namespace std;
class Baseball {
public:
	void guess(const string &guessNumber) {
		assertIllegalArgument(guessNumber);
	}

private:
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("must be three letters");
		}
		for (char ch : guessNumber) {
			if (ch < '0' || ch >'9') continue;
			throw invalid_argument("must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw length_error("must not have same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
};