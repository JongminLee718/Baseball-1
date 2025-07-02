#include <stdexcept>

using namespace std;

struct GuessResult {
	int solved;
	int strikes;
	int balls;
};
class Baseball {
public:
	Baseball(const string &str) : question{ str } {}

	GuessResult guess(const string &guessNumber) {
		assertIllegalArgument(guessNumber);
		bool result = false;
		int strikes = getStrikesCount(guessNumber);
		int balls = balls = getBallCount(guessNumber);

		if (strikes == 3) result = true;
		return { result,strikes,balls };
	}

private:
	string question;
	int getStrikesCount(const std::string& guessNumber)
	{
		int strikes = 0;
		for (int strIdx = 0;strIdx < guessNumber.size(); strIdx++) {
			if (question[strIdx] == guessNumber[strIdx]) strikes++;
		}
		return strikes;
	}

	int getBallCount(const std::string& guessNumber)
	{
		int balls = 0;
		for (int queStrIdx = 0;queStrIdx < question.size(); queStrIdx++) {
			for (int guessStrIdx = 0;guessStrIdx < guessNumber.size(); guessStrIdx++) {
				if (queStrIdx == guessStrIdx) continue;
				if (question[queStrIdx] == guessNumber[guessStrIdx]) balls++;
			}
		}
		return balls;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("must be three letters");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
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