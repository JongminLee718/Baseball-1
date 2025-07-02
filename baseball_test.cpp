#include "gmock/gmock.h"
#include "baseball.cpp"
#include <vector>

using namespace testing;

class BaseballFixture : public Test {
public:
	Baseball game{ "123" };
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

TEST_F(BaseballFixture, returnSlovedResultIfMatched) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, returnSlovedResultFor2S0B) {
	GuessResult result = game.guess("124");
	 
	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, returnSlovedResultFor1S2B) {
	GuessResult result = game.guess("132");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}


int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
