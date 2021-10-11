#include <core/file_interactor.h>

#include <iostream>

int main(int argc, char* argv[]) {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.

  if (argc != 6) {
    std::cout
        << "You have not entered the right amount of arguments. try again!";
  } else {
    std::string imageFilePath = argv[1];
    std::string labelFilePath = argv[3];
    std::string modelFilePath = argv[5];

    try {
      std::ifstream training_image = std::ifstream(imageFilePath);

      std::ofstream model = std::ofstream(modelFilePath);

      std::string training_label = labelFilePath;

      FileInteractor f = FileInteractor();
      f.InitializeLabelVector(training_label);

      training_image >> f;

      model << f;
    } catch (const char* msg) {
      std::cout << msg;
    }
  }

  return 0;
}
