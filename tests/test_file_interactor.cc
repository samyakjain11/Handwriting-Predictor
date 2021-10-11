//
// Created by Samyak Jain on 10/13/20.
//

#include <core/file_interactor.h>

#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

#include "core/model_generator.h"

///TODO: fix this require condition
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

  ///TODO: fix this test case
  REQUIRE(f.getImages().size() == 10);
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
