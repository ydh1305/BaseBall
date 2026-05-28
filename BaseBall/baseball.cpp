#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		int strikes = countStrikes(guessNumber);
		int balls = countBalls(guessNumber);
		return { strikes == 3, strikes, balls };
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	int countStrikes(const string& guessNumber) {
		int count = 0;
		for (size_t i = 0; i < question.size(); i++) {
			if (guessNumber[i] == question[i]) count++;
		}
		return count;
	}
	int countBalls(const string& guessNumber) {
		int count = 0;
		for (size_t i = 0; i < question.size(); i++) {
			if (guessNumber[i] != question[i] && question.find(guessNumber[i]) != string::npos)
				count++;
		}
		return count;
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
private:
	string question;
};