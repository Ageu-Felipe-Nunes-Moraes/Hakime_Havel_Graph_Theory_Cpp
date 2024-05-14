#include <iostream>
#include <vector>
#include <algorithm>

//Hakime Havel

class HakimeHavel {
private:
    // Counter to help
    int counter;
    // Get the highest value of vector
    int highestValue; 

    // Rearrange list in decrescente order
    std::vector<int> rearrangeVector(std::vector<int> vector) {
        std::sort(vector.begin(), vector.end(), std::greater<int>());
        return vector;
    }

    // Print in the terminal
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
            // Will subtract 1 from each position
            vector[j] = vector[j] - 1;
        }
        return vector;
    }

    // Checks whether it is a vector graphic or not
    void checkPosition(std::vector<int> vector) {
        for (int k = 0; k < vector.size(); ++k) {
            // # Checks if all the other positions are equal to the zero as well
            if (vector[k] == 0) {
                counter++;
                // Checks the counting of zeros
                if (counter == vector.size()) {
                    std::cout << "É um vetor gráfico: ";
                    showVector(vector);
                    break;
                }
            }
            // # Checks if there is any value in the from vector that is equal to "-1"
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

    // The function that checks if is a graphic vector using Hakime Havel's principles
    void graphicVector(std::vector<int> vector) {
        std::vector<int> decrescenteVector = rearrangeVector(vector);
        // Applying all necessary iterations to reach a satisfactory conclusion
        // Checks if there is any vertices with a degree greater than the size of the vector
        if (decrescenteVector.size() > decrescenteVector[0]) {
            showVector(decrescenteVector);
            for (size_t i = 0; i < vector.size(); ++i) {
                highestValue = decrescenteVector[0];
                // Deletes the first item from the vector
                decrescenteVector.erase(decrescenteVector.begin());
                std::vector<int> vectorSubtract = subtractPositions(decrescenteVector);
                showVector(vectorSubtract);
                decrescenteVector = rearrangeVector(vectorSubtract);
                showVector(decrescenteVector);
                // Checks if the first position is "0"
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
    // input list
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
