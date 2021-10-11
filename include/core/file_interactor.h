//
// Created by Samyak Jain on 10/10/20.
//

#ifndef NAIVE_BAYES_FILE_INTERACTOR_H
#define NAIVE_BAYES_FILE_INTERACTOR_H

#include <fstream>
#include <iostream>
#include <sstream>

#include "image.h"
#include "model_generator.h"

/**
 * this class reads in the user input by overloading the >> operator
 */
class FileInteractor {
 public:
  /**
   * default constructor
   */
  FileInteractor();


  /**
   * represents the size of the image
   */
  static const int kSizeOfImage = 3;

  /**
   * @return returns the vector of images stored in the object
   */
  std::vector<image::Image> getImages();

  /**
   * initializes the vector of images from given istream file
   * @param images_file the file in which images are contained
   */
  static void InitializeImagesVector(std::istream& images_file);

  /**
   * initializes the vector of labels from the given filepath
   * @param labels_file_path file path of file that contains labels
   */
  static void InitializeLabelVector(std::string labels_file_path);

  /**
   * overloads the >> operator to read in a files contents to my object
   * @param input the inputted file from which data will be read
   * @param fileInteractor the object with which data will be processed
   * @return returns istream
   */
  friend std::istream& operator>>(std::istream& input,
                                  FileInteractor& fileInteractor);

  /**
   * overloads the << operator to write the model in to a file
   * @param model the file in which the model will be written
   * @param fileInteractor the object which will help accomplish this
   * @return returns ostream
   */
  friend std::ostream& operator<<(std::ostream& model,
                                  FileInteractor& fileInteractor);

  ModelGenerator GetModelGenerator();

  void setModelGenerator(ModelGenerator generator);

 private:
  /**
   * represents the vector of labels
   */
  static std::vector<char> labels;

  /**
   * represents the vector of images
   */
  static std::vector<image::Image> images;

  ModelGenerator modelGenerator;

  const static int kImageSize = 28;

  /**
   * these represent which characters will be identified as which type of spaces
   */
  const static char kBlackSpace = '#';
  const static char kWhiteSpace = ' ';
  const static char kGreySpace = '+';
};

#endif  // NAIVE_BAYES_FILE_INTERACTOR_H
