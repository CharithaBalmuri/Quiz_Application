#include <bits/stdc++.h>
using namespace std;

struct Question {
    string que;
    vector<string> options;
    int correct_ans;
};

class Quiz {
private:
    vector<Question> questions;
    int score;
public:
    Quiz() : score(0) {}

    void addQuestion(const string& que, const vector<string>& options, int correct_ans) {
        Question q = {que, options, correct_ans};
        questions.push_back(q);
    }

    void start() {
        for (size_t i = 0; i < questions.size(); i++) {
            cout << "Question " << (i + 1) << ": " << questions[i].que << "\n";
            for (size_t j = 0; j < questions[i].options.size(); j++) {
                cout << j + 1 << ". " << questions[i].options[j] << "\n";
            }

            int user_ans;
            bool valid_input = false;

            while (!valid_input) {
                cout << "Your answer (1-" << questions[i].options.size() << "): ";
                if (cin >> user_ans && user_ans >= 1 && user_ans <= questions[i].options.size()) {
                    valid_input = true;
                } else {
                    cout << "Invalid input. Please enter a number between 1 and " << questions[i].options.size() << ".\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            if (user_ans - 1 == questions[i].correct_ans) {
                cout << "Correct!\n";
                score++;
            } else {
                cout << "Incorrect! \n" << "Correct answer is: " << questions[i].options[questions[i].correct_ans] << "\n";
            }
            cout << "\n";
        }
        cout << "Your total score: " << score << " out of " << questions.size() << "\n";
    }
};

int main() {
    Quiz quiz;

    vector<string> s1 = {"Berlin", "Madrid", "Paris", "Rome"};
    quiz.addQuestion("What is the capital of France?", s1, 2);

    vector<string> s2 = {"Earth", "Jupiter", "Mars", "Saturn"};
    quiz.addQuestion("Which planet is known as the Red Planet?", s2, 2);

    vector<string> s3 = {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"};
    quiz.addQuestion("What is the largest ocean on Earth?", s3, 3);

    vector<string> s4 = {"Charles Dickens", "Mark Twain", "William Shakespeare", "Leo Tolstoy"};
    quiz.addQuestion("Who wrote 'Hamlet'?", s4, 2);

    vector<string> s5 = {"H2O", "O2", "CO2", "NaCl"};
    quiz.addQuestion("What is the chemical symbol for Water?", s5, 0);

    quiz.start();
    return 0;
}
