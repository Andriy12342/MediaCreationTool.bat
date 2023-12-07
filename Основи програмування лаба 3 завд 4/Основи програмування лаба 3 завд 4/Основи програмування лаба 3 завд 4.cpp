#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

// Завдання 1
pair<double, double> calculateArraySums(const vector<double>& arr, int M) {
    double sumOdd = 0.0;
    double sumBetweenNegatives = 0.0;

    for (size_t i = 0; i < arr.size(); i += 2) {
        sumOdd += arr[i];
    }

    int firstNegativeIndex = -1, lastNegativeIndex = -1;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }
    }

    for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
        sumBetweenNegatives += arr[i];
    }

    return make_pair(sumOdd, sumBetweenNegatives);
}

// Завдання 2
pair<int, int> processMatrix(const vector<vector<int>>& matrix) {
    int productRowsWithoutNegatives = 1;
    int maxSumDiagonals = numeric_limits<int>::min();

    for (size_t i = 0; i < matrix.size(); ++i) {
        bool hasNegative = false;
        int sumDiagonals = 0;

        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
            }

            if (i + j == matrix[i].size() - 1) {
                sumDiagonals += matrix[i][j];
            }
        }

        if (!hasNegative) {
            productRowsWithoutNegatives *= i + 1;
        }

        if (sumDiagonals > maxSumDiagonals) {
            maxSumDiagonals = sumDiagonals;
        }
    }

    return make_pair(productRowsWithoutNegatives, maxSumDiagonals);
}

// Завдання 3
vector<string> processText(const string& inputText) {
    int wordCount = 0;
    istringstream iss(inputText);
    string word;

    while (iss >> word) {
        ++wordCount;
    }

    string maxVowelWord;
    int maxVowelCount = 0;

    istringstream iss2(inputText);
    while (iss2 >> word) {
        int vowelCount = 0;

        for (char c : word) {
            if (strchr("aeiouAEIOU", c) != nullptr) {
                ++vowelCount;
            }
        }

        if (vowelCount > maxVowelCount) {
            maxVowelCount = vowelCount;
            maxVowelWord = word;
        }
    }

    string sanitizedText;
    istringstream iss3(inputText);
    while (iss3 >> word) {
        sanitizedText += word + " ";
    }

    return { to_string(wordCount), maxVowelWord, sanitizedText };
}

int main() {
    vector<double> array = { 1.5, -2.0, 3.2, -4.7, 5.1 };
    int M = 2;

    auto result1 = calculateArraySums(array, M);
    cout << "Sum of odd elements: " << result1.first << endl;
    cout << "Sum between first and last negative elements: " << result1.second << endl;

    vector<vector<int>> matrix = { {1, 2, 3}, {4, -5, 6}, {7, 8, -9} };
    auto result2 = processMatrix(matrix);
    cout << "Product of rows without negatives: " << result2.first << endl;
    cout << "Max sum of diagonals: " << result2.second << endl;

    string inputText = "This is a sample text with some words.";
    auto result3 = processText(inputText);
    cout << "Word count: " << result3[0] << endl;
    cout << "Word with max vowels: " << result3[1] << endl;
    cout << "Sanitized text: " << result3[2] << endl;

    return 0;
}
