//
// Created by Samyak Jain on 10/13/20.
//

#include <core/file_interactor.h>

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("check file interactor happy path") {
  std::ifstream training_image = std::ifstream(
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "testing-data/testingimages");

  std::ofstream model = std::ofstream(
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "models/model");

  std::string training_label =
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "testing-data/testinglabels";

  FileInteractor f = FileInteractor();
  f.InitializeLabelVector(training_label);

  training_image >> f;

  model << f;

  std::vector<image::Image> images;

  image::Image zeroImage = image::Image("###\n# #\n###", '0', '#', '+', ' ', 3);
  image::Image oneImage = image::Image(" # \n # \n # ", '1', '#', '+', ' ', 3);
  image::Image twoImage = image::Image("###\n # \n###", '2', '#', '+', ' ', 3);
  image::Image threeImage =
      image::Image("###\n ##\n###", '3', '#', '+', ' ', 3);
  image::Image fourImage = image::Image("# #\n###\n  #", '4', '#', '+', ' ', 3);
  image::Image fiveImage = image::Image("###\n## \n## ", '5', '#', '+', ' ', 3);
  image::Image sixImage = image::Image("#  \n## \n## ", '6', '#', '+', ' ', 3);
  image::Image sevenImage =
      image::Image("###\n # \n#  ", '7', '#', '+', ' ', 3);
  image::Image eightImage =
      image::Image("###\n # \n###", '8', '#', '+', ' ', 3);
  image::Image nineImage = image::Image(" ##\n ##\n  #", '9', '#', '+', ' ', 0);

  images.push_back(zeroImage);
  images.push_back(oneImage);
  images.push_back(twoImage);
  images.push_back(threeImage);
  images.push_back(fourImage);
  images.push_back(fiveImage);
  images.push_back(sixImage);
  images.push_back(sevenImage);
  images.push_back(eightImage);
  images.push_back(nineImage);

  REQUIRE(f.getImages() == images);
}
TEST_CASE("testing non existent files") {
  SECTION("nonexistent label file") {
    std::ifstream training_image = std::ifstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "testing-data/testingimages");

    std::ofstream model = std::ofstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "models/model");

    std::string training_label =
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-kfjd/naivebayes2-samyakjain11/data/"
        "testing-data/testinglabels";

    FileInteractor f = FileInteractor();

    REQUIRE_THROWS_AS(f.InitializeLabelVector(training_label),
                      std::invalid_argument);
  }
  SECTION("nonexistent imaging file") {
    std::ifstream training_image = std::ifstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-kh/naivebayes2-samyakjain11/data/"
        "testing-data/testingimages");

    std::ofstream model = std::ofstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "models/model");

    std::string training_label =
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "testing-data/testinglabels";

    FileInteractor f = FileInteractor();
    f.InitializeLabelVector(training_label);

    REQUIRE_THROWS_AS(training_image >> f, std::invalid_argument);
  }
  SECTION("nonexisting model file") {
    std::ifstream training_image = std::ifstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "testing-data/testingimages");

    std::ofstream model = std::ofstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "models/model123");

    std::string training_label =
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "testing-data/testinglabels";

    FileInteractor f = FileInteractor();
    f.InitializeLabelVector(training_label);

    training_image >> f;

    model << f;

    // if it got this far, that means everything works.
    REQUIRE(true);
  }
}
TEST_CASE("testing empty files") {
  SECTION("empty image file") {
    std::ifstream training_image = std::ifstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "testing-data/emptyimages");

    std::ofstream model = std::ofstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "models/model");

    std::string training_label =
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "testing-data/testinglabels";

    FileInteractor f = FileInteractor();
    f.InitializeLabelVector(training_label);

    REQUIRE_THROWS_AS(training_image >> f, std::invalid_argument);
  }
  SECTION("empty label file") {
    std::ifstream training_image = std::ifstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "testing-data/testingimages");

    std::ofstream model = std::ofstream(
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "models/model");

    std::string training_label =
        "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
        "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
        "testing-data/emptylabels";

    FileInteractor f = FileInteractor();
    REQUIRE_THROWS_AS(f.InitializeLabelVector(training_label),
                      std::invalid_argument);
  }
}
