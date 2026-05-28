#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace testing;

class BaseballFixture:  public Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS;
		}
	}
};

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	try {
		game.guess(string("12s"));
		FAIL();
	}
	catch (exception e) {

	}
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}