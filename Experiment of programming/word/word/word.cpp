#pragma execution_character_set("utf-8")
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <windows.h>

struct Word {
    std::string english;
    std::string chinese;
};

std::vector<Word> loadWords(const std::string& filename) {
    std::vector<Word> words;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string english, chinese;

        std::getline(ss, english, ',');
        std::getline(ss, chinese, ',');

        words.push_back({ english, chinese });
    }

    return words;
}

void shuffleWords(std::vector<Word>& words) {
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(words.begin(), words.end());
}

void quizEnglishToChinese(const std::vector<Word>& words) {
    std::srand(unsigned(std::time(0)));
    for (const auto& word : words) {
        std::set<std::string> options;
        options.insert(word.chinese);

        while (options.size() < 4) {
            int randIndex = std::rand() % words.size();
            options.insert(words[randIndex].chinese);
        }

        std::vector<std::string> choices(options.begin(), options.end());
        std::random_shuffle(choices.begin(), choices.end());

        std::cout << "What is the meaning of '" << word.english << "'?" << std::endl;
        for (size_t i = 0; i < choices.size(); ++i) {
            std::cout << i + 1 << ". " << choices[i] << std::endl;
        }

        int answer;
        std::cin >> answer;

        if (choices[answer - 1] == word.chinese) {
            std::cout << "Correct!" << std::endl;
        }
        else {
            std::cout << "Incorrect. The correct answer is '" << word.chinese << "'." << std::endl;
        }
    }
}

void quizChineseToEnglish(const std::vector<Word>& words) {
    std::srand(unsigned(std::time(0)));
    for (const auto& word : words) {
        std::set<std::string> options;
        options.insert(word.english);

        while (options.size() < 4) {
            int randIndex = std::rand() % words.size();
            options.insert(words[randIndex].english);
        }

        std::vector<std::string> choices(options.begin(), options.end());
        std::random_shuffle(choices.begin(), choices.end());

        std::cout << "What is the English word for '" << word.chinese << "'?" << std::endl;
        for (size_t i = 0; i < choices.size(); ++i) {
            std::cout << i + 1 << ". " << choices[i] << std::endl;
        }

        int answer;
        std::cin >> answer;

        if (choices[answer - 1] == word.english) {
            std::cout << "Correct!" << std::endl;
        }
        else {
            std::cout << "Incorrect. The correct answer is '" << word.english << "'." << std::endl;
        }
    }
}

int main() 
{
    SetConsoleOutputCP(65001);
    std::cout << "Choose difficulty level (1 = Primary, 2 = Middle, 3 = High): ";
    int level;
    std::cin >> level;
    std::cin.ignore(); 

    std::string filename;
    if (level == 1) {
        filename = "Primary.csv";
    }
    else if (level == 2) {
        filename = "Middle.csv";
    }
    else if (level == 3) {
        filename = "High.csv";
    }
    else {
        std::cerr << "Invalid level selected." << std::endl;
        return 1;
    }

    auto words = loadWords(filename);

    std::cout << "Choose order (1 = Random, 2 = Alphabetical): ";
    int order;
    std::cin >> order;
    std::cin.ignore(); 

    if (order == 1) {
        shuffleWords(words);
    }
    else if (order == 2) {
        std::sort(words.begin(), words.end(), [](const Word& a, const Word& b) {
            return a.english < b.english;
            });
    }
    else {
        std::cerr << "Invalid order selected." << std::endl;
        return 1;
    }

    std::cout << "Choose mode (1 = English to Chinese, 2 = Chinese to English): ";
    int mode;
    std::cin >> mode;
    std::cin.ignore(); 

    if (mode == 1) {
        quizEnglishToChinese(words);
    }
    else if (mode == 2) {
        quizChineseToEnglish(words);
    }
    else {
        std::cerr << "Invalid mode selected." << std::endl;
        return 1;
    }

    return 0;
}
