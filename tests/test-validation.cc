//
// Created by Samyak Jain on 10/20/20.
//
#include <core/file_interactor.h>
#include <core/ModelInterpretor.h>

#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

#include "core/model_generator.h"

TEST_CASE("fd"){
  /*
  std::ifstream training_image = std::ifstream(
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "training-data/trainingimages");

  std::ofstream model = std::ofstream(
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "models/validation-model");

  std::string training_label =
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "training-data/traininglabels";

  FileInteractor trainingFileInteractor = FileInteractor();
  trainingFileInteractor.InitializeLabelVector(training_label);

  training_image >> trainingFileInteractor;

  model << trainingFileInteractor;


*/
  //model is trained!

  std::ifstream saved_model = std::ifstream(
      "/Users/samyak/Desktop/FreshmanYear/CS126/CLionWorkspace/"
      "cinder_0.9.2_mac/my-projects/naivebayes2-samyakjain11/data/"
      "models/test_validation_model");

  ModelInterpretor m = ModelInterpretor(saved_model);



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

  int count = 0;
  double loopC = 0;

  for(image::Image image1 : validating_interactor.getImages())
  {
    loopC++;
    //converts char to int
    //credits: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    char a = image1.GetClassification();
    int ia = a - '0';

    if(m.ComputeClassification(image1) == ia)
      count++;
  }

  REQUIRE(count/loopC > 0.7);



}