//
// Created by Samyak Jain on 10/10/20.
//

#ifndef NAIVE_BAYES_MODEL_GENERATOR_H
#define NAIVE_BAYES_MODEL_GENERATOR_H
#include <map>
#include <vector>
#include "image.h"
#include <map>

/**
 * uses training data to generate a model for the algorithm
 */
class ModelGenerator {
 public:

  /**
   * constructor for ModelGenerator
   * @param images
   */
  ModelGenerator(std::vector<image::Image> images, int imageSize);

  ModelGenerator();

  /**
   * @return returns a string of the model that is generated
   */
  std::string GenerateModelAsString();

 private:
  std::vector<image::Image> images;
  int imageSize_;


  std::map<char, std::vector<image::Image>> classification_image_vector_map_;


  constexpr static double kLaplaceSmoothingCoefficient = 1;

  /**
   * @return generates a string that calculates all the class probabilities
   */
  std::string CalculateClassProbabilities();

  /**
   * @return generates a string that calculates all the pixel probabilities
   * according to each class
   */
  std::string CalculatePixelProbabilities();

  void InitializeClassificationVectorMap();
};

#endif  // NAIVE_BAYES_MODEL_GENERATOR_H
