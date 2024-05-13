#include <iostream>
#include <vector>
#include <algorithm>

class HakimeHavel {
private:
    int counter;
    int highestValue;

    std::vector<int> rearrangeVector(std::vector<int> vector) {
        std::sort(vector.begin(), vector.end(), std::greater<int>());
        return vector;
    }

    void showVector(std::vector<int> vector) {
        std::cout << "[";
        for (size_t i = 0; i < vector.size(); ++i) {
            std::cout << vector[i];
            if (i != vector.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]\n";
    }

    std::vector<int> subtractPositions(std::vector<int> vector) {
        for (int j = 0; j < highestValue; ++j) {
            vector[j] = vector[j] - 1;
        }
        return vector;
    }

    void checkPosition(std::vector<int> vector) {
        for (int k = 0; k < vector.size(); ++k) {
            if (vector[k] == 0) {
                counter++;
                if (counter == vector.size()) {
                    std::cout << "É um vetor gráfico: ";
                    showVector(vector);
                    break;
                }
            }
            if (vector[k] == -1) {
                std::cout << "Não é um vetor gráfico: ";
                showVector(vector);
                break;
            }
        }
    }

public:
    HakimeHavel() {
        counter = 0;
        highestValue = 0;
    }

    void graphicVector(std::vector<int> vector) {
        std::vector<int> decrescenteVector = rearrangeVector(vector);
        if (decrescenteVector.size() > decrescenteVector[0]) {
            showVector(decrescenteVector);
            for (size_t i = 0; i < vector.size(); ++i) {
                highestValue = decrescenteVector[0];
                decrescenteVector.erase(decrescenteVector.begin());
                std::vector<int> vectorSubtract = subtractPositions(decrescenteVector);
                showVector(vectorSubtract);
                decrescenteVector = rearrangeVector(vectorSubtract);
                showVector(decrescenteVector);
                if (decrescenteVector[0] == 0) {
                    checkPosition(decrescenteVector);
                    break;
                }
            }
        } else {
            std::cout << "\nTipo de lista inválida\n";
        }
    }
};

int main() {
    HakimeHavel hakime;
    hakime.graphicVector({3, 2, 2, 2, 2});
    return 0;
}

//test value = 3,2,2,2,2

//not graphic
//[6, 5, 4, 4, 4, 4, 4, 2]
//[4, 3, 3, 3, 3, 3, 2]
//[2, 2, 2, 2, 3, 2]
//[3, 2, 2, 2, 2, 2]
//[1, 1, 1, 2, 2]
//[2, 2, 1, 1, 1]
//[1, 0, 1, 1]
//[1, 1, 1, 0]
//[0, 1, 0]
//[1, 0, 0]
//[-1, 0]
//[0, -1]

// it's graphic
//[5, 4, 3, 3, 3, 3, 3, 2]
//[3, 2, 2, 2, 2, 3, 2]
//[3, 3, 2, 2, 2, 2, 2]
//[2, 1, 1, 2, 2, 2]
//[2, 2, 2, 2, 1, 1]
//[1, 1, 2, 1, 1]
//[2, 1, 1, 1, 1]
//[0, 0, 1, 1]
//[1, 1, 0, 0]
//[0, 0, 0]
//[0, 0, 0]
