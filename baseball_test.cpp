#include "gmock/gmock.h"
#include "baseball.cpp"
#include <vector>

using namespace testing;

class BaseballFixture : public Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNum) {
		try {
			game.guess(guessNum);
			FAIL();
		}
		catch (exception e) {

		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
