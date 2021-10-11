//
// Created by Samyak Jain on 10/10/20.
//

#include "core/model_generator.h"

#include <cmath>
#include <iostream>

std::string ModelGenerator::GenerateModelAsString() {
  return CalculateClassProbabilities() + "\n" + CalculatePixelProbabilities();
}

ModelGenerator::ModelGenerator(std::vector<image::Image> images,
                               int imageSize) {
  if (images.empty())
    throw std::invalid_argument("no images in vector");

  images.erase(images.end()-1);

  ModelGenerator::images = images;
  InitializeClassificationVectorMap();

  ModelGenerator::imageSize_ = imageSize;
}

std::string ModelGenerator::CalculateClassProbabilities() {
  std::string probabilities = "";
  double classProbability = 0;

  for (std::map<char, std::vector<image::Image>>::iterator it =
           classification_image_vector_map_.begin();
       it != classification_image_vector_map_.end(); it++) {
    classProbability = (kLaplaceSmoothingCoefficient + (it->second).size()) /
                       (2 * kLaplaceSmoothingCoefficient + images.size());
    probabilities += std::to_string(log(classProbability)) + "\n";
  }

  return probabilities;
}

std::string ModelGenerator::CalculatePixelProbabilities() {
  std::string probabilities = "";
  double shadedProb;
  double unshadedProb;

  for (std::map<char, std::vector<image::Image>>::iterator it =
           classification_image_vector_map_.begin();
       it != classification_image_vector_map_.end(); it++) {
    for (int row = 0; row < imageSize_; row++) {
      for (int col = 0; col < imageSize_; col++) {
        int numberOfTimesPixelWasShaded = 0;
        int numberOfTimesPixelWasUnshaded = 0;
        for (image::Image image : it->second) {
          if (image.IsPixelShaded(row, col))
            numberOfTimesPixelWasShaded++;
          else
            numberOfTimesPixelWasUnshaded++;
        }
        shadedProb =
            (kLaplaceSmoothingCoefficient + numberOfTimesPixelWasShaded) /
            (2 * kLaplaceSmoothingCoefficient + (it->second).size());

        probabilities += std::to_string(log10(shadedProb)) + " ";

        unshadedProb =
            (kLaplaceSmoothingCoefficient + numberOfTimesPixelWasUnshaded) /
            (2 * kLaplaceSmoothingCoefficient + (it->second).size());

        probabilities += std::to_string(log10(unshadedProb)) + "\n";
      }
    }
  }
  return probabilities;
}

void ModelGenerator::InitializeClassificationVectorMap() {
  for (image::Image image : images) {
    std::map<char, std::vector<image::Image>>::iterator it;
    it = classification_image_vector_map_.find(image.GetClassification());

    if (it == classification_image_vector_map_.end()) {
      std::vector<image::Image> images_in_this_classification;
      images_in_this_classification.push_back(image);
      classification_image_vector_map_[image.GetClassification()] =
          images_in_this_classification;
    } else {
      it->second.push_back(image);
    }
  }
}

ModelGenerator::ModelGenerator() {
}
