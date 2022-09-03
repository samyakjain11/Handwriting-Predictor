#include <core/ModelInterpretor.h>
#include <core/file_interactor.h>

#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Enter your command in the following manner";
  std::cout << "train [insert training images file path] [insert training "
               "labels file path] save [insert file path where you want the "
               "model saved] note: if you already have a model, simply put "
               "train null null save null";

  if (argc != 5) {
    std::cout
        << "You have not entered the right amount of arguments. try again!";
  } else {
    try {
      std::ifstream training_image = std::ifstream(argv[1]);

      std::string training_label = argv[2];

      std::ofstream model = std::ofstream(argv[4]);

      FileInteractor f = FileInteractor();
      f.InitializeLabelVector(training_label);

      training_image >> f;

      model << f;
    } catch (std::invalid_argument e) {
      std::cout << "you have entered something incorrectly";
    }
    std::cout << "Enter your command in the following manner";
    std::cout << "test model [file path of your saved model]";

    if (argc != 8) {
      std::cout
          << "You have not entered the right amount of arguments. try again!";
    }
    std::ifstream saved_model = std::ifstream(argv[7]);
    ModelInterpretor modelInterpretor = ModelInterpretor(saved_model);

    std::ifstream validating_images = std::ifstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "classification-testing-data/testimages");

    std::string validating_labels =
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "classification-testing-data/testlabels";

    FileInteractor validating_interactor = FileInteractor();
    validating_interactor.InitializeLabelVector(validating_labels);

    validating_images >> validating_interactor;

    int result_accuracy_count = 0;
    double loop_count = 0;

    for (image::Image image1 : validating_interactor.getImages()) {
      loop_count++;
      // converts char to int
      // credits:
      // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
      char a = image1.GetClassification();
      int ia = a - '0';

      if (modelInterpretor.ComputeClassification(image1) == ia)
        result_accuracy_count++;
    }
    std::cout << "the accuracy of your model was: " +
                     std::to_string(result_accuracy_count / loop_count);
  }

  return 0;
}
