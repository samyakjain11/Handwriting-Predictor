#include <core/image.h>

#include <iostream>
#include <string>
#include <vector>

class ModelInterpretor {
 public:
  ModelInterpretor(std::istream& saved_model);

  /**
   * computes classification of an image
   * @param image the image object for which classification needs to be computed
   * @return classification of the image
   */
  int ComputeClassification(image::Image image);

  /**
   * calculates the likelihood of a certain image being a certain classification
   * @param classification the specific classification for whihc you are
   * calculating likelihood
   * @param image the image object for which you are calculating likelihood
   * @return returns the likelihood as a double
   */
  double CalculateLikelihood(int classification, image::Image image);

 private:
  /**
   * represents the calculated likelihoods of the image being a specific class
   */
  std::vector<double> class_likelihood_scores;

  /**
   * represents the calculated likelihoods of a specific pixel being shaded
   * given its class
   */
  std::vector<std::vector<double>> pixel_likelihood_scores_by_class;

  /**
   * finds the index of the maximum value in a vector
   * @param vect the vector from which you are trying to find a maximum value
   * @return the index of the maximum value
   */
  int FindIndexOfMaxOfVector(std::vector<double> vect);
};
